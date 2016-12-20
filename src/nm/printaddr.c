#include "nmotool.h"

static void	put_ptr(uint64_t value, t_bool print64)
{
	size_t		len;

	len = nbrlen(value, BASE);
	if (print64)
		len = BASE - len;
	else
		len = (BASE >> 1) - len;
	ft_putnchar('0', len);
	ft_putnbrbase(value, "0123456789abcdef", BASE);
}

void		print_addr(t_nlist64 *nlist64, t_nlist32 *nlist32)
{
	if (nlist64)
	{
		if (!nlist64->n_value)
			ft_putnchar(' ', 16);
		else
			put_ptr(nlist64->n_value, true);
	}
	else
	{
		if (!nlist32->n_value)
			ft_putnchar(' ', 8);
		else
			put_ptr(nlist32->n_value, false);
	}
	ft_putchar(' ');
}
