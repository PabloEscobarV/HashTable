/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addhashnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:35:44 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/23 22:13:02 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include "../hdrs/enums.h"
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

int	findplace(const char *key, t_hashtable *hashtable, int hash, int step)
{
	int	i;
	int	atmp;

	i = hash;
	atmp = hashtable->tabsize * 2;
	while (hashtable->table[i] && hashtable->table[i]->state && atmp)
	{
		if (!ft_strcmp(key, hashtable->table[i]->key))
			return (i);
		--atmp;
		i = (hash + atmp * step) % hashtable->tabsize;
	}
	if (!hashtable->table[i] || !hashtable->table[i]->state)
		return (i);
	hashtable->resize(hashtable, C_RESIZE);
	return (findplace(key, hashtable, hash, step));
}

void	writedata(int place, t_cchar *key, t_cchar *data, t_hashtable *hashtable)
{
	if (!hashtable->table[place])
		hashtable->table[place] = crthashnodet(key, data);
	else
	{
		if (ft_strcmp(key, hashtable->table[place]->key))
		{
			free((void *)hashtable->table[place]->key);
			hashtable->table[place]->key = (t_cchar *)ft_strdup(key);
		}
		free((void *)hashtable->table[place]->data);
		hashtable->table[place]->data = (t_cchar *)ft_strdup(data);
		hashtable->table[place]->state = E_HTTRUE;
	}
	++hashtable->datacount;
	++hashtable->nodecount;
}

int	addnode(t_hashtable *hashtable, const char *key, const char *data)
{
	int	place;
	int	hash;
	int	step;

	checkhashtable(hashtable);
	hash = gethash(hashtable->fhash, key, hashtable->tabsize);
	step = getstephash(hash, hashtable->tabsize);
	place = findplace(key, hashtable, hash, step);
	writedata(place, key, data, hashtable);
	return (E_HTOK);
}
