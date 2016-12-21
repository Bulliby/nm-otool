/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:07:15 by gwells            #+#    #+#             */
/*   Updated: 2016/12/21 13:08:24 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

static int			magic_key(const void *ptr, uint32_t cigam, uint32_t magic)
{
	if ((!ft_memcmp(ptr, &cigam, sizeof(uint32_t)) ||\
	!ft_memcmp(ptr, &magic, sizeof(uint32_t))) && cigam == MH_CIGAM)
		header32(ptr);
	else if ((!ft_memcmp(ptr, &cigam, sizeof(uint32_t)) ||\
	!ft_memcmp(ptr, &magic, sizeof(uint32_t))) && cigam == MH_CIGAM_64)
		header64(ptr);
	else if (!ft_memcmp(ptr, &cigam, sizeof(uint32_t)) && cigam == FAT_CIGAM)
		headerfat(ptr, true);
	else if (!ft_memcmp(ptr, &magic, sizeof(uint32_t)) && magic == FAT_MAGIC)
		headerfat(ptr, false);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int					check_arch(const void *ptr)
{
	int				ret;

	ret = EXIT_FAILURE;
	ret &= magic_key(ptr, MH_CIGAM, MH_MAGIC);
	ret &= magic_key(ptr, MH_CIGAM_64, MH_MAGIC_64);
	ret &= magic_key(ptr, FAT_CIGAM, FAT_MAGIC);
	if (ret == EXIT_FAILURE)
	{
		ft_putendl_fd("Bad Architecture", 2);
		return (EXIT_FAILURE);
	}
	else
		return (EXIT_SUCCESS);
}
