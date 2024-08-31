/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crthashnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:25:21 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/31 19:39:20 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"

t_hashnode	*crthashnodet(char *key, char *data)
{
	t_hashnode	*hashnode;

	hashnode = malloc(sizeof(t_hashnode));
	if (!hashnode)
	{
		ft_perror(HT_MALLOCERROR);
		exit(E_ERR);
	}
	hashnode->key = key;
	hashnode->data = data;
	if (key)
		hashnode->state = e_true;
	else
		hashnode->state = e_false;
	return (hashnode);
}

void	freehashnodet(t_hashnode *node)
{
	free(node->data);
	free(node->key);
	free(node);
}

void	*delhashnodet(t_hashnode *node)
{
	free(node->data);
	free(node->key);
	free(node);
	return (NULL);
}
