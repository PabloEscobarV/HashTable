/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:13:06 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/24 23:53:52 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include "../hdrs/hash_table.h"
#include "../hdrs/enums.h"
#include <stdlib.h>

int	resizehashtable(t_hashtable *hashtable, int xsize)
{
	int			i;
	int			tmpsize;
	t_hashnode	**tmp;

	tmp = hashtable->table->table;
	tmpsize = hashtable->table->tabsize;
	hashtable->table->tabsize *= xsize;
	hashtable->table = crt_hash_table(hashtable->table->tabsize);
	i = 0;
	while (i < tmpsize)
	{
		if (tmp[i] && tmp[i]->state)
			addnode(hashtable->table, tmp[i]->key, tmp[i]->data);
		++i;
	}
	freetable(tmp, tmpsize);
	return (E_HTOK);
}
