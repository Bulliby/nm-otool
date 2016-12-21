/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:51:18 by gwells            #+#    #+#             */
/*   Updated: 2016/12/21 13:10:32 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

static void			base(unsigned char c)
{
	char			ret;
	char			modulo;
	char			stamp[BASE];

	ft_strcpy(stamp, "0123456789abcdef");
	ret = c / BASE;
	modulo = c % BASE;
	if (modulo > BASE)
		base(ret);
	ft_putchar(stamp[(int)ret]);
	ft_putchar(stamp[(int)modulo]);
}

void				put_hexa(const void *ptr, size_t nbbytes)
{
	while (nbbytes--)
	{
		ft_putchar(' ');
		base(*(unsigned char *)ptr);
		ptr++;
	}
	ft_putchar(' ');
	ft_putchar('\n');
}

size_t				nbrlen(uint64_t nbr, size_t base)
{
	size_t			count;

	count = 0;
	while (nbr >= base)
	{
		nbr /= base;
		count++;
	}
	count++;
	return (count);
}
