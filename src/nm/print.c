#include "nmotool.h"
#include <mach-o/nlist.h>

static void				parse_nlist64(t_argfunc *arg, t_ptrsymbols *ptrsym)
{
	size_t				i;

	i = 0;
	while (i != SYMBOLS)
	{
		ptrsym[i](arg);
		i++;
	}
}

void				print_tab_info64(const void *ptr, const t_symtab *symtab,\
					const t_lc *lc)
{
	size_t			i;
	t_argfunc		arg;
	t_ptrsymbols	ptrsym[SYMBOLS];
	
	i = 0;
	arg.nlist64 = (void *) ptr + symtab->symoff;
	arg.stringtable = (void *) ptr + symtab->stroff;
	arg.nlist32 = NULL;
	setupptrsym(ptrsym);
	while (i != symtab->nsyms)
	{
		arg.ext = ((arg.nlist64->n_type & N_EXT) == N_EXT);
		parse_nlist64(&arg, ptrsym);
		arg.nlist64++;
		i++;
	}
}

void			print_tab_info32(const void *ptr, const t_symtab *symtab,\
				const t_lc *lc)
{
	size_t		i;
	t_nlist32	*nlist;
	char		*stringtable;

	i = 0;
	nlist = (void *) ptr + symtab->symoff;
	stringtable = (void *) ptr + symtab->stroff;
	while (i != symtab->nsyms)
	{
		//printf("[%s]\n", stringtable + nlist[i].n_un.n_strx);
		i++;
	}
}
