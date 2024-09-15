/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removehashnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:08:04 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/15 02:46:53 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include <stdlib.h>

int	removenode(t_hashtable *hashtable, const char *key)
{
	int	i;

	i = hashtable->find(hashtable, key);
	if (!(hashtable->table[i]))
		return (E_OK);
	free((void *)hashtable->table[i]->key);
	free((void *)hashtable->table[i]->data);
	hashtable->table[i]->key = NULL;
	hashtable->table[i]->data = NULL;
	hashtable->table[i]->state = e_false;
	return (E_OK);
}
