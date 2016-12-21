/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrsymsect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:24:37 by gwells            #+#    #+#             */
/*   Updated: 2016/12/21 13:38:21 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

void		text(t_argfunc *arg)
{
	if (arg->nlist64 && (arg->nlist64->n_type & N_TYPE) == N_SECT && \
	through_seg(arg, "__text", arg->nlist64->n_sect) == true)
		print_type64('t', arg);
	if (arg->nlist32 && (arg->nlist32->n_type & N_TYPE) == N_SECT &&\
	through_seg(arg, "__text", arg->nlist32->n_sect) == true)
		print_type32('t', arg);
}

void		bbs(t_argfunc *arg)
{
	if (arg->nlist64 && (arg->nlist64->n_type & N_TYPE) == N_SECT && \
	through_seg(arg, "__bss", arg->nlist64->n_sect) == true)
		print_type64('b', arg);
	if (arg->nlist32 && (arg->nlist32->n_type & N_TYPE) == N_SECT &&\
	through_seg(arg, "__bss", arg->nlist32->n_sect) == true)
		print_type32('b', arg);
}

void		data(t_argfunc *arg)
{
	if (arg->nlist64 && (arg->nlist64->n_type & N_TYPE) == N_SECT && \
	through_seg(arg, "__data", arg->nlist64->n_sect) == true)
		print_type64('d', arg);
	if (arg->nlist32 && (arg->nlist32->n_type & N_TYPE) == N_SECT &&\
	through_seg(arg, "__data", arg->nlist32->n_sect) == true)
		print_type32('d', arg);
}
