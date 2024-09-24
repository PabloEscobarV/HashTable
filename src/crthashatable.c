/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crthashatable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:26:02 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/24 23:48:41 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include "../hdrs/hash_table.h"
#include <stdlib.h>

t_hashtable	*crthashtable(int size)
{
	t_hashtable	*hashtable;

	hashtable = malloc(sizeof(t_hashtable));
	if (!hashtable)
	{
		ft_perror(HT_MALLOCERROR);
		exit(-1);
	}
	hashtable->table = crt_hash_table(size);
	hashtable->add = addnode;
	hashtable->remove_node = removenode;
	hashtable->rehash = rehash;
	hashtable->resize = resizehashtable;
	hashtable->get_data = get_data;
	hashtable->get_key = get_key;
	hashtable->get_tabsize = get_tabsize;
	hashtable->set_f_hash(hashtable->table, murmur3_32);
	return (hashtable);
}

t_hashtable	*crtnewhashtable(t_hashtable *table, int size)
{
	t_hashtable	*newtable;

	newtable = malloc(sizeof(t_hashtable));
	if (!newtable)
	{
		ft_perror(HT_MALLOCERROR);
		exit(-1);
	}
	newtable->table = crt_hash_table(size);
	newtable->add = table->add;
	newtable->remove_node = table->remove_node;
	newtable->rehash = table->rehash;
	newtable->resize = table->resize;
	newtable->get_data = table->get_data;
	newtable->get_key = table->get_key;
	newtable->get_tabsize = table->get_tabsize;
	newtable->set_f_hash(newtable->table, get_f_hash(table->table));
	return (newtable);
}

void	freetable(t_hashnode **table, int size)
{
	while (size)
	{
		--size;
		if (table[size])
		{
			free((void *)(table[size]->data));
			free((void *)(table[size]->key));
			free(table[size]);
		}
	}
	free(table);
}

void	freehashtablet(t_hashtable *hashtable)
{
	freetable(get_hashnode(hashtable->table), get_tabsize(hashtable->table));
	free(hashtable);
}
