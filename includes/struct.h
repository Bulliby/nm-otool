/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:34:58 by gwells            #+#    #+#             */
/*   Updated: 2016/12/21 13:35:39 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <mach-o/fat.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>

typedef enum	e_symbols
{
	UNDEFINED = 0,
	ABSOLUTE,
	COMMON,
	DATA,
	BBS,
	TEXT,
	OTHER
}				t_symbols;

typedef struct stat					t_stat;
typedef struct mach_header_64		t_header64;
typedef struct mach_header			t_header32;
typedef struct fat_header			t_headerfat;
typedef struct fat_arch				t_arch;
typedef struct segment_command_64	t_seg64;
typedef struct segment_command		t_seg32;
typedef struct section_64			t_sect64;
typedef struct section				t_sect32;
typedef struct load_command			t_lc;
typedef struct symtab_command		t_symtab;
typedef	struct nlist_64				t_nlist64;
typedef	struct nlist				t_nlist32;

typedef struct						s_argfunc
{
	const t_lc						*lc;
	t_nlist64						*nlist64;
	t_nlist32						*nlist32;
	void							*stringtable;
	t_bool							ext;
	uint32_t						ncmds;
}									t_argfunc;

typedef void						(*t_ptrsymbols)(t_argfunc *arg);

#endif
