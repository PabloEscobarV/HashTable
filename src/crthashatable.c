/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crthashatable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:26:02 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/22 19:22:59 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include "../hdrs/enums.h"
#include <stdlib.h>

t_hashnode	**crttable(int size)
{
	t_hashnode	**table;

	table = malloc(size * sizeof(t_hashnode *));
	if (!table)
	{
		ft_perror(HT_MALLOCERROR);
		exit(-1);
	}
	while (size)
	{
		--size;
		table[size] = NULL;
	}
	return (table);
}

t_hashtable	*crthashtable(int size)
{
	t_hashtable	*hashtable;

	hashtable = malloc(sizeof(t_hashtable));
	if (!hashtable)
	{
		ft_perror(HT_MALLOCERROR);
		exit(-1);
	}
	hashtable->table = crttable(size);
	hashtable->tabsize = size;
	hashtable->datacount = 0;
	hashtable->nodecount = 0;
	hashtable->fhash = murmur3_32;
	hashtable->add = addnode;
	hashtable->find = findnode;
	hashtable->remove = removenode;
	hashtable->rehash = rehash;
	hashtable->resize = resizehashtable;
	return (hashtable);
}

t_hashtable	*crtnewhashtable(t_hashtable *table, int xsize)
{
	t_hashtable	*newtable;

	newtable = crthashtable(table->tabsize * xsize);
	newtable->datacount = 0;
	newtable->nodecount = 0;
	newtable->fhash = table->fhash;
	newtable->add = table->add;
	newtable->find = table->find;
	newtable->remove = table->remove;
	newtable->rehash = table->rehash;
	newtable->resize = table->resize;
	return (newtable);
}

void	freetable(t_hashnode **table, int size)
{
	while (size)
	{
		--size;
		if (table[size])
		{
			free((void *)(table[size]->data));
			free((void *)(table[size]->key));
			free(table[size]);
		}
	}
	free(table);
}

void	freehashtablet(t_hashtable *hashtable)
{
	freetable(hashtable->table, hashtable->tabsize);
	free(hashtable);
}
