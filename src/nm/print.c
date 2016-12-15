#include "nmotool.h"
#include <mach-o/nlist.h>

void			print_tab_info64(const void *ptr, const t_symtab *symtab)
{
	size_t		i;
	t_nlist64	*nlist;
	char		*stringtable;

	i = 0;
	nlist = (void *) ptr + symtab->symoff;
	stringtable = (void *) ptr + symtab->stroff;
	while (i != symtab->nsyms)
	{
		printf("[%s]\n", stringtable + nlist[i].n_un.n_strx);
		i++;
	}
}

void			print_tab_info32(const void *ptr, const t_symtab *symtab)
{
	size_t		i;
	t_nlist32	*nlist;
	char		*stringtable;

	i = 0;
	nlist = (void *) ptr + symtab->symoff;
	stringtable = (void *) ptr + symtab->stroff;
	while (i != symtab->nsyms)
	{
		printf("[%s]\n", stringtable + nlist[i].n_un.n_strx);
		i++;
	}
}
