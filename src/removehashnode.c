/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removehashnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:08:04 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/26 22:33:54 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include "../hdrs/hash_table.h"
#include "../hdrs/enums.h"
#include <stdlib.h>

int	removenode(t_hashtable *hashtable, const char *key)
{
	int	i;

	i = findnode(hashtable, key);
	if (!(hashtable->table->table[i]))
		return (E_HTOK);
	free((void *)hashtable->table->table[i]->key);
	free((void *)hashtable->table->table[i]->data);
	hashtable->table->table[i]->key = NULL;
	hashtable->table->table[i]->data = NULL;
	hashtable->table->table[i]->state = E_HTFALSE;
	return (E_HTOK);
}
