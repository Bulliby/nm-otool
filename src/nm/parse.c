#include "nmotool.h"

void				parse64nm(const void * ptr, const uint32_t ncmds,\
					const t_lc *lc)
{
	uint32_t		i;
	t_symtab		*symtab;
	
	i = 0;
	while (i != ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			symtab = (t_symtab *)lc;
			print_tab_info64(ptr, symtab);
		}
		lc = (void *) lc + lc->cmdsize;
		i++;
	}
}

void				parse32nm(const void * ptr, const uint32_t ncmds,\
					const t_lc *lc)
{
	uint32_t		i;
	t_symtab		*symtab;
	
	i = 0;
	while (i != ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			symtab = (t_symtab *)lc;
			print_tab_info32(ptr, symtab);
		}
		lc = (void *) lc + lc->cmdsize;
		i++;
	}
}
