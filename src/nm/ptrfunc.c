#include "nmotool.h"

void		setupptrsym(t_ptrsymbols *ptrsym)
{
	ptrsym[UNDEFINED] = &undefined;
	ptrsym[ABSOLUTE] = &absolute;
	ptrsym[COMMON] = &common;
	ptrsym[DATA] = &data;
	ptrsym[BBS] = &bbs;
	ptrsym[TEXT] = &text;
	ptrsym[OTHER] = &other;
}

static t_bool		is_other_field(uint8_t n_type)
{
	uint8_t			bit;

	bit = 0x80;
	if (n_type & bit || n_type & (bit >> 1) || n_type & (bit >> 2))
		return (true);
	/*
	bit = 0x10;
	if (n_type & bit)
		return (true);
	*/
	return (false);
}

void				print_type32(char type, t_argfunc *arg)
{
	if (is_other_field(arg->nlist32->n_type))
		return ;
	print_addr(NULL, arg->nlist32, type);
	if (arg->ext)
		type = ft_toupper(type);
	ft_putchar(type);
	ft_putchar(' ');
	ft_putendl(arg->stringtable + arg->nlist32->n_un.n_strx);
}

void				print_type64(char type, t_argfunc *arg)
{
	if (is_other_field(arg->nlist64->n_type))
		return ;
	print_addr(arg->nlist64, NULL, type);
	if (arg->ext)
		type = ft_toupper(type);
	ft_putchar(type);
	ft_putchar(' ');
	ft_putendl(arg->stringtable + arg->nlist64->n_un.n_strx);
}
