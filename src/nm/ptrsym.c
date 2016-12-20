#include "nmotool.h"

static t_bool	in_other_section(t_argfunc *arg)
{
	if (arg->nlist64 && (through_seg(arg, "__text", arg->nlist64->n_sect)\
	|| through_seg(arg, "__bss", arg->nlist64->n_sect)\
	|| through_seg(arg, "__data", arg->nlist64->n_sect)))
		return (true);
	if (arg->nlist32 && (through_seg(arg, "__text", arg->nlist32->n_sect)\
	|| through_seg(arg, "__bss", arg->nlist32->n_sect)\
	|| through_seg(arg, "__data", arg->nlist32->n_sect)))
		return (true);
	return (false);
}

void		undefined(t_argfunc	*arg)
{
	if (arg->nlist64 && (arg->nlist64->n_type & N_TYPE) == N_UNDF)
		print_type64('u', arg);
	if (arg->nlist32 && (arg->nlist32->n_type & N_TYPE) == N_UNDF)
		print_type32('u', arg);
}	

void		absolute(t_argfunc	*arg)
{
	if (arg->nlist64 && (arg->nlist64->n_type & N_TYPE) == N_ABS)
		print_type64('a', arg);
	if (arg->nlist32 && (arg->nlist32->n_type & N_TYPE) == N_ABS)
		print_type32('a', arg);
}	

void		common(t_argfunc	*arg)
{
	if (arg->nlist64 && (arg->nlist64->n_type & N_TYPE) == N_UNDF &&\
	arg->nlist64->n_value)
		print_type64('c', arg);
	if (arg->nlist32 && (arg->nlist32->n_type & N_TYPE) == N_UNDF &&\
	arg->nlist64->n_value)
		print_type32('c', arg);
}	

void		other(t_argfunc	*arg)
{
	if (arg->nlist64 && !in_other_section(arg) && (arg->nlist64->n_type\
	& N_TYPE) == N_SECT)
		print_type64('s', arg);
	if (arg->nlist32 && !in_other_section(arg) && (arg->nlist32->n_type\
	& N_TYPE) == N_SECT)
		print_type32('s', arg);
}	
