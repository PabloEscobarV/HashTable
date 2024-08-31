/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crthashatable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:26:02 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/31 21:13:11 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
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

	hashtable = malloc(sizeof(t_hashnode));
	if (!hashtable)
	{
		ft_perror(HT_MALLOCERROR);
		exit(-1);
	}
	hashtable->table = crttable(size);
	hashtable->tabsize = size;
	hashtable->datacount = 0;
	hashtable->nodecount = 0;
	hashtable->fhash = NULL;
	hashtable->add = NULL;
	hashtable->find = NULL;
	hashtable->remove = NULL;
	hashtable->rehash = NULL;
	hashtable->resize = NULL;
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
		free(table[size]->data);
		free(table[size]->key);
		free(table[size]);
	}
	free(table);
}

void	freehashtablet(t_hashtable *hashtable)
{
	freetable(hashtable->table, hashtable->tabsize);
	free(hashtable);
}
