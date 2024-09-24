/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removehashnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:08:04 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/24 23:34:44 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include "../hdrs/hash_table.h"
#include "../hdrs/enums.h"
#include <stdlib.h>

int	removenode(t_hash_table *hashtable, const char *key)
{
	int	i;

	i = findnode(hashtable, key);
	if (!(hashtable->table[i]))
		return (E_HTOK);
	free((void *)hashtable->table[i]->key);
	free((void *)hashtable->table[i]->data);
	hashtable->table[i]->key = NULL;
	hashtable->table[i]->data = NULL;
	hashtable->table[i]->state = E_HTFALSE;
	return (E_HTOK);
}
