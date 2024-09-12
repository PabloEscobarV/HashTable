/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:03:26 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/12 09:21:22 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/hashtable.h"
#include "stdio.h"

char  **crtstrs(int size, t_cchar *startkey)
{
	int    i;
	int    strsize;
	char  **keys;

	keys = malloc((size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		keys[i] = ft_strjoinfree((char *)startkey, ft_itoa(i), 1);
		++i;
	}
	return (keys);
}

int main()
{
	int      size;
	int      count;
	char    **keys;
	char    **data;
	t_hashtable  *hashtable;

	size = 1;
	count = 5;
	keys = crtstrs(count, "KEY: ");
	data = crtstrs(count, "DATA: ");
	hashtable = crthashtable(size);
	for (int i = 0; i < count; ++i)
		hashtable->add(hashtable, keys[i], data[i]);
	for (int i = 0; i < count; ++i)
		printf("NODE[%d]:\t%s\n", i, hashtable->table[hashtable->find(hashtable, keys[i])]);
	return (0);
}
