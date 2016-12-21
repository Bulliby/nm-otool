/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   through_seg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:25:56 by gwells            #+#    #+#             */
/*   Updated: 2016/12/21 13:29:00 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

static t_bool		search_for_sect64(const char *sect, const t_lc *lc,\
					uint8_t index, uint8_t *count)
{
	uint32_t		x;
	uint32_t		nsects;

	x = 0;
	nsects = ((t_seg64*)lc)->nsects;
	lc = (void *)lc + sizeof(t_seg64);
	while (x != nsects)
	{
		if (*count == index && !ft_strcmp(sect, ((t_sect64 *)lc)->sectname))
			return (true);
		lc = (void *)lc + sizeof(t_sect64);
		(*count)++;
		x++;
	}
	return (false);
}

static t_bool		search_for_sect32(const char *sect, const t_lc *lc,\
					uint8_t index, uint8_t *count)
{
	uint32_t		x;
	uint32_t		nsects;

	x = 0;
	nsects = ((t_seg32*)lc)->nsects;
	lc = (void *)lc + sizeof(t_seg32);
	while (x != nsects)
	{
		if (*count == index && !ft_strcmp(sect, ((t_sect32 *)lc)->sectname))
			return (true);
		lc = (void *)lc + sizeof(t_sect32);
		(*count)++;
		x++;
	}
	return (false);
}

t_bool				through_seg(t_argfunc *arg, const char *sect, uint8_t index)
{
	uint32_t		i;
	t_bool			ret;
	uint8_t			count;
	const t_lc		*tmp;

	i = 0;
	count = 1;
	ret = false;
	tmp = arg->lc;
	while (i != arg->ncmds)
	{
		if (tmp->cmd == LC_SEGMENT || tmp->cmd == LC_SEGMENT_64)
		{
			if (arg->nlist64 && (ret = search_for_sect64(sect, tmp,\
			index, &count)) == true)
				break ;
			else if (arg->nlist32 && (ret = search_for_sect32(sect, tmp,\
			index, &count)) == true)
				break ;
		}
		tmp = (void *)tmp + tmp->cmdsize;
		i++;
	}
	return (ret);
}
