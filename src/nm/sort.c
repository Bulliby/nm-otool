/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:25:02 by gwells            #+#    #+#             */
/*   Updated: 2016/12/21 13:25:45 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

static void			swap64(t_nlist64 *tab, size_t index)
{
	t_nlist64		tmp;

	tmp = tab[index];
	tab[index] = tab[index + 1];
	tab[index + 1] = tmp;
}

static void			swap32(t_nlist32 *tab, size_t index)
{
	t_nlist32		tmp;

	tmp = tab[index];
	tab[index] = tab[index + 1];
	tab[index + 1] = tmp;
}

void				sort_nlist64(t_nlist64 *tab, char *stringtable,\
					uint32_t nsyms)
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
			if (ft_strcmp(stringtable + tab[i].n_un.n_strx, stringtable +\
			tab[i + 1].n_un.n_strx) > 0)
			{
				swap64(tab, i);
				stop = false;
			}
			i++;
		}
	}
}

void				sort_nlist32(t_nlist32 *tab, char *stringtable,\
					uint32_t nsyms)
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
			if (ft_strcmp(stringtable + tab[i].n_un.n_strx, stringtable +\
			tab[i + 1].n_un.n_strx) > 0)
			{
				swap32(tab, i);
				stop = false;
			}
			i++;
		}
	}
}
