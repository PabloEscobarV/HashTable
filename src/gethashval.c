/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gethashval.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:42:43 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/31 20:57:05 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/hashtable.h"
#include "../NearestPrime/libft/libft.h"
#include "../NearestPrime/hdrs/getnearprime.h"
#include <stdint.h>
#include <stdlib.h>

int	gethash(f_hash fhash, const char *key, int tabsize)
{
	if (!key || !(*key))
		return (E_KO);
	return (fhash(key, ft_strlen(key), HASHSEED) % tabsize);
}

int	getstephash(t_ulong hash, int tabsize)
{
	t_ulong	prime;

	prime = getnearestprime(tabsize);
	return (prime - (hash % prime));
}
