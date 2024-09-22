/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:04:33 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/22 19:23:38 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include "../hdrs/enums.h"
#include <stdlib.h>
#include <stdio.h>

int	resizehashtable(t_hashtable *hashtable, int xsize)
{
	int			i;
	int			tmpsize;
	t_hashnode	**tmp;

	printf("RESIZE HAS STARTED\n");
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
	return (E_HTOK);
}
