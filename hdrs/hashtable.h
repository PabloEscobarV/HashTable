/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:45:05 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/15 02:49:03 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../NearestPrime/libft/libft.h"
#include <stdint.h>
#include <stdlib.h>

#define HASHSEED		0
#define C_RESIZE		2
#define HT_MALLOCERROR	"ERRROR!!! BAD ALLOC MEMMORY"

typedef const char			t_cchar;
typedef struct s_hashnode	t_hashnode;
typedef struct s_hashtable	t_hashtable;

typedef			uint32_t (* f_hash)(const char *key, int tabsize, uint32_t seed);
typedef			int (* f_addnode)(t_hashtable *, t_cchar *key, t_cchar *data);
typedef			int (* f_findnode)(t_hashtable *, t_cchar *key);
typedef			int (* f_removenode)(t_hashtable *, t_cchar *key);
typedef			int	(* f_resizehashtab)(t_hashtable *, int xsize);
typedef			int	(* f_rehash)(t_hashtable *);

enum	e_hashnodestate
{
	e_false,
	e_true,
};

enum	e_errorcodes
{
	E_ERR = -1,
	E_OK,
	E_KO,
	E_ERROR,
};

struct s_hashnode
{
    const char		*key;
    const char		*data;
    char  			state;
};

struct	s_hashtable
{
	int				tabsize;
	int				nodecount;
	int				datacount;
	t_hashnode		**table;
	f_hash			fhash;
	f_addnode		add;
	f_findnode		find;
	f_removenode	remove;
	f_resizehashtab	resize;
	f_rehash		rehash;
};

/////////////////////////////////HASHTABLE METHODS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
int			findnode(t_hashtable *hashtable, const char *key);
int			removenode(t_hashtable *hashtable, const char *key);
int			addnode(t_hashtable *hashtable, const char *key, const char *data);
int			resizehashtable(t_hashtable *hashtable, int xsize);
int			rehash(t_hashtable *hashtable);
int			gethash(f_hash fhash, const char *key, int tabsize);
int			getstephash(t_ulong hash, int tabsize);
uint32_t	murmur3_32(const char* str, int len, uint32_t hash);
/////////////////////////////////CRT HASHTABLE\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_hashnode	**crttable(int size);
t_hashtable	*crthashtable(int size);
t_hashtable	*crtnewhashtable(t_hashtable *table, int xsize);
void		freetable(t_hashnode **table, int size);
void		freehashtablet(t_hashtable *hashtable);
/////////////////////////////////HASHNODE\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_hashnode	*crthashnodet(const char *key, const char *data);
void		freehashnodet(t_hashnode *node);
void		*delhashnodet(t_hashnode *node);
