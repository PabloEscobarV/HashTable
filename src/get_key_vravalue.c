/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_vravalue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:32:47 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/24 23:49:37 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/hashtable.h"
#include "../hdrs/hash_table.h"

const char	*get_data(t_hash_table *hashtable, const char *key)
{
	int	i;

	i = findnode(hashtable, key);
	if (i >= hashtable->tabsize)
		return (NULL);
	return (hashtable->table[i]->data);
}

const char	*get_key(t_hash_table *hashtable, const char *key)
{
	int	i;

	i = findnode(hashtable, key);
	if (i >= hashtable->tabsize)
		return (NULL);
	return (hashtable->table[i]->key);
}
