/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:14:48 by gwells            #+#    #+#             */
/*   Updated: 2016/12/21 13:15:15 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

void			header64(const t_header64 *header)
{
	uint32_t	ncmds;
	t_lc		*lc;

	ncmds = header->ncmds;
	lc = (void *)header + sizeof(*header);
	parse64nm(header, ncmds, lc);
}

void			header32(const t_header32 *header)
{
	uint32_t	ncmds;
	t_lc		*lc;

	ncmds = header->ncmds;
	lc = (void *)header + sizeof(*header);
	parse32nm(header, ncmds, lc);
}
