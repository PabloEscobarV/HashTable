/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removehashnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:08:04 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/31 20:24:12 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include <stdlib.h>

int removenode(t_hashtable *hashtable, const char *key)
{
    t_hashnode  *node;

    node = findhashnode(hashtable, key);
    if (!node)
        return (E_OK);
    free(node->data);
    free(node->key);
    node->state = e_false;
    return (E_OK);
}
