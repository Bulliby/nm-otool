#include "nmotool.h"

static t_bool		search_for_sect(const char *sect, const t_lc *lc, uint8_t index, const uint32_t nsects, uint8_t *count)
{
	uint32_t		x;

	x = 0;
	lc  = (void *) lc + sizeof(t_seg64);
	while (x != nsects)
	{
		(*count)++;
		if (*count == index && !ft_strcmp(sect, ((t_sect64 *)lc)->sectname))
			return true;
		lc = (void *) lc + sizeof(t_sect64);
		x++;
	}		
	return false;
}



static t_bool	through_seg(const char *sect, const t_lc *lc, uint8_t index, uint32_t ncmds)
{
	uint32_t	i;
	t_bool		ret;
	uint32_t	nsects;
	uint8_t		count;

	i = 0;
	count = 0;
	ret = false;
	while (i != ncmds)
	{
		if (lc->cmd == LC_SEGMENT || lc->cmd == LC_SEGMENT_64)
		{
			nsects = ((t_seg64*)lc)->nsects;
			if ((ret = search_for_sect(sect, lc, index, nsects, &count)) == true)
				break;
		}
		lc = (void *) lc + lc->cmdsize;
		i++;
	}
	return (ret);
}

void		text(t_argfunc	*arg)
{
	if (arg->nlist64 && (arg->nlist64->n_type & N_TYPE) == N_SECT &&\
	 through_seg("__text", arg->lc, arg->nlist64->n_sect, arg->ncmds) == true)
	{
		print_addr(arg->nlist64, arg->nlist32);
		if (!arg->ext)
			ft_putstr("t ");
		else
			ft_putstr("T ");
		ft_putendl(arg->stringtable + arg->nlist64->n_un.n_strx);
	}
	else if (arg->nlist32 && (arg->nlist32->n_type & N_TYPE) == N_SECT &&\
			through_seg("__text", arg->lc, arg->nlist32->n_sect, arg->ncmds) == true)
	{
		print_addr(arg->nlist64, arg->nlist32);
		if (!arg->ext)
			ft_putstr("t ");
		else
			ft_putstr("T ");
		ft_putendl(arg->stringtable + arg->nlist32->n_un.n_strx);
	}
}	

void		bbs(t_argfunc	*arg)
{
	printf("bbs\n");
}	

void		data(t_argfunc	*arg)
{
	printf("data\n");
}	

