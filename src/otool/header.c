/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:05:59 by gwells            #+#    #+#             */
/*   Updated: 2016/12/21 13:06:12 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"
#include <ar.h>

void			header64(const t_header64 *header)
{
	uint32_t	ncmds;
	t_seg64		*seg;

	if (!ft_memcmp(header, ARMAG, SARMAG) || header->cputype != CPU_TYPE_X86_64)
	{
		ft_putendl_fd("Bad Architecture", 2);
		return ;
	}
	ncmds = header->ncmds;
	seg = (void *)header + sizeof(*header);
	parse64(header, ncmds, seg);
}

void			header32(const t_header32 *header)
{
	uint32_t	ncmds;
	t_seg32		*seg;

	if (!ft_memcmp(header, ARMAG, SARMAG) || header->cputype != CPU_TYPE_X86_64)
	{
		ft_putendl_fd("Bad Architecture", 2);
		return ;
	}
	ncmds = header->ncmds;
	seg = (void *)header + sizeof(*header);
	parse32(header, ncmds, seg);
}
