#include "nmotool.h"

void		undefined(t_argfunc	*arg)
{
	if (arg->nlist64 && (arg->nlist64->n_type & N_TYPE) == N_UNDF)
	{
		print_addr(arg->nlist64, arg->nlist32);
		if (!arg->ext)
			ft_putstr("u ");
		else
			ft_putstr("U ");
		ft_putendl(arg->stringtable + arg->nlist64->n_un.n_strx);
	}
	else if (arg->nlist32 && (arg->nlist32->n_type & N_TYPE) == N_UNDF)
	{
		print_addr(arg->nlist64, arg->nlist32);
		if (!arg->ext)
			ft_putstr("u ");
		else
			ft_putstr("U ");
		ft_putendl(arg->stringtable + arg->nlist64->n_un.n_strx);
	}
}	

void		absolute(t_argfunc	*arg)
{
	if (arg->nlist64 && (arg->nlist64->n_type & N_TYPE) == N_ABS)
	{
		print_addr(arg->nlist64, arg->nlist32);
		if (!arg->ext)
			ft_putstr("a ");
		else
			ft_putstr("A ");
		ft_putendl(arg->stringtable + arg->nlist64->n_un.n_strx);
	}
	else if (arg->nlist32 && (arg->nlist32->n_type & N_TYPE) == N_ABS)
	{
		print_addr(arg->nlist64, arg->nlist32);
		if (!arg->ext)
			ft_putstr("a ");
		else
			ft_putstr("A ");
		ft_putendl(arg->stringtable + arg->nlist64->n_un.n_strx);
	}
}	

void		common(t_argfunc	*arg)
{
	if (arg->nlist64 && (arg->nlist64->n_type & N_TYPE) == N_UNDF &&\
		arg->nlist64->n_value)
	{
		print_addr(arg->nlist64, arg->nlist32);
		if (!arg->ext)
			ft_putstr("c ");
		else
			ft_putstr("C ");
		ft_putendl(arg->stringtable + arg->nlist64->n_un.n_strx);
	}
	else if (arg->nlist32 && (arg->nlist32->n_type & N_TYPE) == N_UNDF &&\
			arg->nlist32->n_value)
	{
		print_addr(arg->nlist64, arg->nlist32);
		if (!arg->ext)
			ft_putstr("c ");
		else
			ft_putstr("C ");
		ft_putendl(arg->stringtable + arg->nlist64->n_un.n_strx);
	}
}	

void		other(t_argfunc	*arg)
{
	printf("other\n");
}	
