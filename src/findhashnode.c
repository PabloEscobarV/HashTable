/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findhashnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:48:20 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/14 15:34:34 by Pablo Escob      ###   ########.fr       */
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
	while (atmp)
	{
		--atmp;
		if (hashtable->table[i] && hashtable->table[i]->state
			&& !ft_strcmp(key, hashtable->table[i]->key))
				return (i);
		i = (hash + atmp * step) % hashtable->tabsize;
	}
	return (hashtable->tabsize);
}
