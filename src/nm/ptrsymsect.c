#include "nmotool.h"

static t_bool		search_for_sect(const char *sect, const t_lc *lc,\
					uint8_t index, uint8_t *count)
{
	uint32_t		x;
	uint32_t		nsects;

	x = 0;
	nsects = ((t_seg64*)lc)->nsects;
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



t_bool	through_seg(t_argfunc *arg, const char *sect, uint8_t index)
{
	uint32_t	i;
	t_bool		ret;
	uint8_t		count;
	const t_lc	*tmp;

	i = 0;
	count = 0;
	ret = false;
	tmp = arg->lc;
	while (i != arg->ncmds)
	{
		if (tmp->cmd == LC_SEGMENT || tmp->cmd == LC_SEGMENT_64)
		{
			if ((ret = search_for_sect(sect, tmp, index, &count)) == true)
				break;
		}
		tmp = (void *) tmp + tmp->cmdsize;
		i++;
	}
	return (ret);
}

void		text(t_argfunc	*arg)
{
	if (arg->nlist64 && (arg->nlist64->n_type & N_TYPE) == N_SECT && \
	through_seg(arg, "__text", arg->nlist64->n_sect) == true)
		print_type64('t', arg);
	if (arg->nlist32 && (arg->nlist32->n_type & N_TYPE) == N_SECT &&\
	through_seg(arg, "__text", arg->nlist32->n_sect) == true)
		print_type32('t', arg);
}

void		bbs(t_argfunc	*arg)
{
	if (arg->nlist64 && (arg->nlist64->n_type & N_TYPE) == N_SECT && \
	through_seg(arg, "__bbs", arg->nlist64->n_sect) == true)
		print_type64('b', arg);
	if (arg->nlist32 && (arg->nlist32->n_type & N_TYPE) == N_SECT &&\
	through_seg(arg, "__bbs", arg->nlist32->n_sect) == true)
		print_type32('b', arg);
}	

void		data(t_argfunc	*arg)
{
	if (arg->nlist64 && (arg->nlist64->n_type & N_TYPE) == N_SECT && \
	through_seg(arg, "__data", arg->nlist64->n_sect) == true)
		print_type64('d', arg);
	if (arg->nlist32 && (arg->nlist32->n_type & N_TYPE) == N_SECT &&\
	through_seg(arg, "__data", arg->nlist32->n_sect) == true)
		print_type32('d', arg);
}	
