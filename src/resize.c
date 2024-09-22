/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:13:06 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/22 14:00:27 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include <stdlib.h>

int	resizehashtable(t_hashtable *hashtable, int xsize)
{
	int			i;
	int			tmpsize;
	t_hashnode	**tmp;

	tmp = hashtable->table;
	tmpsize = hashtable->tabsize;
	hashtable->tabsize *= xsize;
	hashtable->table = crttable(hashtable->tabsize);
	i = 0;
	while (i < tmpsize)
	{
		if (tmp[i] && tmp[i]->state)
			addnode(hashtable, tmp[i]->key, tmp[i]->data);
		++i;
	}
	freetable(tmp, tmpsize);
	return (E_OK);
}
