/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rehash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:17:52 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/14 13:56:59 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include "../hdrs/hashtable.h"
#include <stdlib.h>
#include <stdio.h>

int	rehash(t_hashtable *hashtable)
{
	printf("STARTING REHASH\n");
	return (resizehashtable(hashtable, 1));
}