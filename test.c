/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:28:50 by marvin            #+#    #+#             */
/*   Updated: 2024/09/09 13:28:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/hashtable.h"

char	**crtstrs(int size, t_cchar *startkey)
{
	int		i;
	int		strsize;
	char	**keys;

	keys = malloc((size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		keys[i] = ft_strjoinfree(startkey, ft_itoa(i), 2);
		++i;
	}
	return (keys);
}

int main()
{
	int			size;
	int			count;
	char		**keys;
	char		**data;
    t_hashtable	*hashtable;

	size = 10;
	count = 50;
	keys = crtstrs(count, "KEY: ");
	data = crtstrs(count, "DATA: ");
	hashtable = crthashtable(size);
	for (int i = 0; i < count; ++i)
		hashtable->add(hashtable, keys[i], data[i]);
    return (0);
}
