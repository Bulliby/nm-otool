/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:17:58 by gwells            #+#    #+#             */
/*   Updated: 2016/12/21 13:21:20 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"
#include <mach-o/nlist.h>

static void			parse_nlist(t_argfunc *arg, t_ptrsymbols *ptrsym)
{
	size_t			i;

	i = 0;
	while (i != SYMBOLS)
	{
		ptrsym[i](arg);
		i++;
	}
}

void				print_tab_info64(const void *ptr, const t_symtab *symtab,\
					const t_lc *lc, uint32_t ncmds)
{
	size_t			i;
	t_argfunc		arg;
	t_ptrsymbols	ptrsym[SYMBOLS];

	i = 0;
	arg.nlist64 = (void *)ptr + symtab->symoff;
	arg.stringtable = (void *)ptr + symtab->stroff;
	arg.nlist32 = NULL;
	arg.ncmds = ncmds;
	arg.lc = lc;
	setupptrsym(ptrsym);
	sort_nlist64(arg.nlist64, arg.stringtable, symtab->nsyms);
	while (i != symtab->nsyms)
	{
		arg.ext = ((arg.nlist64->n_type & N_EXT) == N_EXT);
		parse_nlist(&arg, ptrsym);
		arg.nlist64++;
		i++;
	}
}

void				print_tab_info32(const void *ptr, const t_symtab *symtab,\
					const t_lc *lc, uint32_t ncmds)
{
	size_t			i;
	t_argfunc		arg;
	t_ptrsymbols	ptrsym[SYMBOLS];

	i = 0;
	arg.nlist32 = (void *)ptr + symtab->symoff;
	arg.stringtable = (void *)ptr + symtab->stroff;
	arg.nlist64 = NULL;
	arg.ncmds = ncmds;
	arg.lc = lc;
	setupptrsym(ptrsym);
	sort_nlist32(arg.nlist32, arg.stringtable, symtab->nsyms);
	while (i != symtab->nsyms)
	{
		arg.ext = ((arg.nlist32->n_type & N_EXT) == N_EXT);
		parse_nlist(&arg, ptrsym);
		arg.nlist32++;
		i++;
	}
}
