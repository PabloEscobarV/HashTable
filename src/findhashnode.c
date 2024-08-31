/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findhashnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:48:20 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/31 20:58:42 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include <stdlib.h>

int	findnode(t_hashtable *hashtable, const char *key)
{
	int	i;
	int	hash;
	int	step;
	int	atmp;

	hash = gethash(hashtable->fhash, key, hashtable->tabsize);
	step = getstephash(hash, hashtable->tabsize);
	i = hash;
	atmp = hashtable->tabsize * 2;
	while (hashtable->table[i] && hashtable->table[i]->state && atmp)
	{
		--atmp;
		i = (hash + i * step) % hashtable->tabsize;
	}
	if (hashtable->table[i] && hashtable->table[i]->state)
		return (i);
	return (hashtable->tabsize);
}
