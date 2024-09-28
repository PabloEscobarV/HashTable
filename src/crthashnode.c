/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crthashnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:25:21 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/28 19:19:47 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/enums.h"
#include "../hdrs/hashtablesrvc.h"

t_hashnode	*crthashnodet(const char *key, const char *data)
{
	t_hashnode	*hashnode;

	hashnode = malloc(sizeof(t_hashnode));
	if (!hashnode)
	{
		ft_perror(HT_MALLOCERROR);
		exit(E_HTERR);
	}
	hashnode->key = (t_cchar *)ft_strdup(key);
	hashnode->data = (t_cchar *)ft_strdup(data);
	if (key)
		hashnode->state = E_HTTRUE;
	else
		hashnode->state = E_HTFALSE;
	return (hashnode);
}

void	freehashnodet(t_hashnode *node)
{
	free((void *)node->data);
	free((void *)node->key);
	free(node);
}

void	*delhashnodet(t_hashnode *node)
{
	free((void *)node->data);
	free((void *)node->key);
	free(node);
	return (NULL);
}
