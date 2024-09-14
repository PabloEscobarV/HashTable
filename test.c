/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:03:26 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/14 15:34:57 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/hashtable.h"
#include <stdlib.h>
#include <stdio.h>

char  **crtstrs(int size, t_cchar *startkey)
{
	int    i;
	int    strsize;
	char  **keys;
	char	*tmp;

	keys = malloc((size + 1) * sizeof(char *));
	keys[size] = NULL;
	i = 0;
	while (i < size)
	{
		keys[i] = ft_strjoinfree((char *)startkey, ft_itoa(i), 1);
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
	count = 10;
	hashtable = crthashtable(size);
	keys = crtstrs(count, "KEY: ");
	data = crtstrs(count, "DATA: ");
	for (int i = 0; i < count; ++i)
		hashtable->add(hashtable, (t_cchar *)keys[i], (t_cchar *)data[i]);
	for (int i = 0; i < count; ++i)
	{
		size = hashtable->find(hashtable, keys[i]);
		printf("NODE[%d]:\tKEY: %s\tDATA: %s\n",
			i, hashtable->table[size]->key, hashtable->table[size]->data);
	}
	for (int i = 0; i < count; ++i)
		if (i && !(i % 2))
			hashtable->remove(hashtable, keys[i]);
	printf("---------------------\n");
	for (int i = 0; i < count; ++i)
	{
		size = hashtable->find(hashtable, keys[i]);
		if (size < hashtable->tabsize)
			printf("NODE[%d]:\tKEY: %s\tDATA: %s\n",
				i, hashtable->table[size]->key, hashtable->table[size]->data);
	}
	return (0);
}