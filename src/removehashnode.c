/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removehashnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:08:04 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/22 19:38:42 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include "../hdrs/enums.h"
#include <stdlib.h>

int	removenode(t_hashtable *hashtable, const char *key)
{
	int	i;

	i = hashtable->find(hashtable, key);
	if (!(hashtable->table[i]))
		return (E_HTOK);
	free((void *)hashtable->table[i]->key);
	free((void *)hashtable->table[i]->data);
	hashtable->table[i]->key = NULL;
	hashtable->table[i]->data = NULL;
	hashtable->table[i]->state = E_HTFALSE;
	return (E_HTOK);
}
