/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addhashnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:35:44 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/14 15:05:02 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include <stdlib.h>
#include <stdio.h>

void	checkhashtable(t_hashtable *hashtable)
{
	if (hashtable->tabsize <= hashtable->nodecount + 1)
		hashtable->resize(hashtable, C_RESIZE);
	if (hashtable->datacount
		&& hashtable->nodecount >= hashtable->datacount * C_RESIZE)
		hashtable->rehash(hashtable);
}

int	findplace(t_hashtable *hashtable, int hash, int step)
{
	int	i;
	int	atmp;

	i = hash;
	atmp = hashtable->tabsize * 2;
	while (hashtable->table[i] && hashtable->table[i]->state && atmp)
	{
		--atmp;
		i = (hash + atmp * step) % hashtable->tabsize;
	}
	if (!hashtable->table[i])
		return (i);
	if (hashtable->table[i] && !hashtable->table[i]->state)
	 	return (i);
	hashtable->resize(hashtable, C_RESIZE);
	return (findplace(hashtable, hash, step));
}

int	addnode(t_hashtable *hashtable, const char *key, const char *data)
{
	int	place;
	int	hash;
	int	step;

	checkhashtable(hashtable);
	hash = gethash(hashtable->fhash, key, hashtable->tabsize);
	step = getstephash(hash, hashtable->tabsize);
	place = findplace(hashtable, hash, step);
	printf("Add KEY: %s with data: %s in %d node\n", key, data, place);
	if (!hashtable->table[place])
		hashtable->table[place] = crthashnodet(key, data);
	else
	{
		hashtable->table[place]->key = (t_cchar *)ft_strdup(key);
		hashtable->table[place]->data = (t_cchar *)ft_strdup(data);
		hashtable->table[place]->state = e_true;
	}
	++hashtable->datacount;
	++hashtable->nodecount;
	return (E_OK);
}
