/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:15:44 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/22 19:17:16 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

enum	e_hterrorcodes
{
	E_HTERR = -1,
	E_HTOK,
	E_HTKO,
	E_HTERROR,
};

enum	e_hashnodestate
{
	E_HTFALSE,
	E_HTTRUE,
};
