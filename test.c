/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:03:26 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/26 23:00:58 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/hashtable.h"
#include <stdlib.h>
#include <stdio.h>

char  **crtstrs(int size, t_cchar *startkey)
{
	int    i;
	char  **keys;

	keys = malloc((size + 1) * sizeof(char *));
	keys[size] = NULL;
	i = 0;
	while (i < size)
	{
		keys[i] = ft_strjoinfree((char *)startkey, ft_itoa(i * i), 1);
		++i;
	}
	return (keys);
}

void	printm(const char **mat)
{
	while (*mat)
	{
		printf("%s\n", *mat);
		++mat;
	}
}

int main()
{
	int			size;
	int			count;
	char		**keys;
	char		**data;
	t_hashtable	*hashtable;

	size = 1;
	count = 100;
	hashtable = crthashtable(size);
	keys = crtstrs(count, "KEY FOR HASHTABL: ");
	data = crtstrs(count, "DATA: ");
	// printm((t_cchar **)keys);
	for (int i = 0; i < count; ++i)
	{
		hashtable->add(hashtable, (t_cchar *)keys[i], (t_cchar *)data[i]);
		if (i)
			hashtable->add(hashtable, (t_cchar *)keys[i - 1], (t_cchar *)data[i - 1]);
	}
	for (int i = 0; i < count; ++i)
	{
		printf("NODE[%d]:\tKEY: %s\tDATA: %s\tHASHTABLE[%d]\n",
			i, hashtable->get_key(hashtable, keys[i]),
			hashtable->get_data(hashtable, keys[i]),
			hashtable->get_place(hashtable, keys[i]));
	}
	for (int i = 0; i < count; ++i)
		if (i && !(i % 2))
			hashtable->remove_node(hashtable, keys[i]);
	printf("---------------------\n");
	for (int i = 0; i < count; ++i)
	{
		printf("NODE[%d]:\tKEY: %s\tDATA: %s\n",
			i, hashtable->get_key(hashtable, keys[i]),
			hashtable->get_data(hashtable, keys[i]));
	}
	ft_free_d((void **)keys);
	ft_free_d((void **)data);
	freehashtablet(hashtable);
	return (0);
}