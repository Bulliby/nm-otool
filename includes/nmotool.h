/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmotool.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:29:12 by gwells            #+#    #+#             */
/*   Updated: 2016/12/21 13:36:17 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMOTOOL_H
# define NMOTOOL_H

# include "libft.h"
# include "struct.h"
# include <stdlib.h>
# include <mach-o/fat.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>

# define BASE 16

# define SYMBOLS	7

/*
** ptrfunc.c
*/
void			setupptrsym(t_ptrsymbols *ptrsym);
void			print_addr(t_nlist64 *nlist64, t_nlist32 *nlist32, char type);
void			print_type32(char type, t_argfunc *arg);
void			print_type64(char type, t_argfunc *arg);

/*
** ptrsym.c
*/
void			undefined(t_argfunc *arg);
void			absolute(t_argfunc	*arg);
void			common(t_argfunc	*arg);
void			other(t_argfunc	*arg);
void			indirect(t_argfunc	*arg);

/*
** ptrsymsect.c
*/
t_bool			through_seg(t_argfunc *arg, const char *sect, uint8_t index);
void			text(t_argfunc	*arg);
void			data(t_argfunc	*arg);
void			bbs(t_argfunc	*arg);

/*
** header.c
*/
void			header64(const t_header64 *header);
void			header32(const t_header32 *header);

/*
** fatheader.c
*/
void			headerfat(const void *ptr, t_bool islittleendian);

/*
** parse.c
*/
void			parse32(const void *ptr, const uint32_t ncmds,\
				const t_seg32 *seg);
void			parse64(const void *ptr, const uint32_t ncmds,\
					const t_seg64 *sef);
void			parse32nm(const void *ptr, const uint32_t ncmds,\
				const t_lc *lc);
void			parse64nm(const void *ptr, const uint32_t ncmds,\
				const t_lc *lc);

/*
** arch.c
*/
int				check_arch(const void *ptr);

/*
** print.c
*/
void			print_section64(const void *ptr, size_t size,\
				uint64_t vmaddr);
void			print_section32(const void *ptr, size_t size,\
				uint64_t vmaddr);
void			print_tab_info32(const void *ptr, const t_symtab *symtab,\
				const t_lc *lc, uint32_t ncmds);
void			print_tab_info64(const void *ptr, const t_symtab *symtab,\
				const t_lc *lc, uint32_t ncmds);
/*
** print_tools.c
*/
void			put_hexa(const void *ptri, size_t nbbytes);
size_t			nbrlen(uint64_t nbr, size_t base);

/*
** arch_tools.c
*/
uint32_t		bigtolitte(uint32_t value);
t_bool			is64bit(void);

/*
** sort.c
*/
void			sort_nlist64(t_nlist64 *tab, char *stringtable, uint32_t nsyms);
void			sort_nlist32(t_nlist32 *tab, char *stringtable, uint32_t nsyms);
#endif
