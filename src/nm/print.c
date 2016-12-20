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

void				swap(t_nlist64 *tab, size_t index)
{
	t_nlist64		tmp;

	tmp = tab[index];	
	tab[index] = tab[index + 1];
	tab[index + 1] = tmp;

}

void				sort_nlist(t_nlist64 *tab, char *stringtable,  uint32_t nsyms)
{
	t_bool			stop;
	size_t			i;

	stop = false;
	while (!stop)
	{
		i = 0;
		stop = true;
		while (i != nsyms - 1)
		{
			if (ft_strcmp(stringtable + tab[i].n_un.n_strx,\
			stringtable + tab[i + 1].n_un.n_strx) > 0)
			{
				swap(tab, i);
				stop = false;
			}
			i++;
		}
	}
}

void				print_tab_info64(const void *ptr, const t_symtab *symtab,\
					const t_lc *lc, uint32_t ncmds)
{
	size_t			i;
	t_argfunc		arg;
	t_ptrsymbols	ptrsym[SYMBOLS];
	
	i = 0;
	arg.nlist64 = (void *) ptr + symtab->symoff;
	arg.stringtable = (void *) ptr + symtab->stroff;
	arg.nlist32 = NULL;
	arg.ncmds = ncmds;
	arg.lc = lc;
	setupptrsym(ptrsym);
	sort_nlist(arg.nlist64, arg.stringtable, symtab->nsyms);
	while (i != symtab->nsyms)
	{
		arg.ext = ((arg.nlist64->n_type & N_EXT) == N_EXT);
		parse_nlist64(&arg, ptrsym);
		arg.nlist64++;
		i++;
	}
}

void			print_tab_info32(const void *ptr, const t_symtab *symtab,\
				const t_lc *lc, uint32_t ncmds)
{
	size_t		i;
	t_nlist32	*nlist;
	char		*stringtable;

	i = 0;
	nlist = (void *) ptr + symtab->symoff;
	stringtable = (void *) ptr + symtab->stroff;
	while (i != symtab->nsyms)
	{
		i++;
	}
}
