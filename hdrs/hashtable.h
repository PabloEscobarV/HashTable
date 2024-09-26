/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:45:05 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/26 23:10:00 by Pablo Escob      ###   ########.fr       */
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
typedef struct s_hash_table	t_hash_table;
typedef struct s_hashtable	t_hashtable;

typedef uint32_t (*	t_fhash)(const char *key, int tabsize, uint32_t seed);
// typedef int (*	t_faddnode)(t_hashtable *, t_cchar *key, t_cchar *data);
// typedef int (*	t_fremovenode)(t_hashtable *, t_cchar *key);
// typedef int (*	t_fresizehashtab)(t_hashtable *, int xsize);
// typedef int	(*	t_frehash)(t_hashtable *);
// typedef t_cchar	(*	t_f)();

struct s_hashnode
{
    const char		*key;
    const char		*data;
    char  			state;
};

struct	s_hashtable
{
	t_hash_table	*table;
	int 			(* add)(t_hashtable *, t_cchar *key, t_cchar *data);
	int 			(* remove_node)(t_hashtable *, t_cchar *key);
	const char		*(* get_data)(t_hashtable *, const char *key);
	const char		*(* get_key)(t_hashtable *, const char *key);
	int 			(* get_tabsize)(t_hash_table *_hash_table);
	int				(* get_place)(t_hashtable *hashtable, const char *key);
	void			(* set_f_hash)(t_hash_table *_hash_table, t_fhash f_hash);
};

// struct	s_hashtable
// {
// 	int				tabsize;
// 	int				nodecount;
// 	int				datacount;
// 	t_hashnode		**table;
// 	t_fhash			fhash;
// 	t_faddnode		add;
// 	t_fremovenode	remove;
// 	t_fresizehashtab	resize;
// 	t_frehash		rehash;
// };

/////////////////////////////////HASHTABLE METHODS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
int				findnode(t_hashtable *hashtable, const char *key);
int				removenode(t_hashtable *hashtable, const char *key);
int				addnode(t_hashtable *hashtable, const char *key, const char *data);
int				resizehashtable(t_hashtable *hashtable, int xsize);
int				rehash(t_hashtable *hashtable);
int				gethash(t_fhash fhash, const char *key, int tabsize);
int				getstephash(t_ulong hash, int tabsize);
uint32_t		murmur3_32(const char* str, int len, uint32_t hash);
/////////////////////////////////CRT HASHTABLE\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_hashtable		*crthashtable(int size);
t_hashtable		*crtnewhashtable(t_hashtable *table, int xsize);
void			freetable(t_hashnode **table, int size);
void			freehashtablet(t_hashtable *hashtable);
/////////////////////////////////HASHNODE\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_hashnode		*crthashnodet(const char *key, const char *data);
void			freehashnodet(t_hashnode *node);
void			*delhashnodet(t_hashnode *node);
const char		*get_data(t_hashtable *hashtable, const char *key);
const char		*get_key(t_hashtable *hashtable, const char *key);
int				get_place(t_hashtable *hashtable, const char *key);
/////////////////////////////////_HASH_TABLE\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
// t_hashnode	**crttable(int size);
t_hash_table	*crt_hash_table(int size);
void			freehash_table(t_hash_table *hashtable);
