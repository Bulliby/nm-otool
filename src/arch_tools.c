/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arch_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:08:54 by gwells            #+#    #+#             */
/*   Updated: 2016/12/21 13:09:16 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

uint32_t				bigtolitte(uint32_t value)
{
	uint32_t			ret;
	uint32_t			copy;

	copy = value;
	ret = (copy & 0xFF000000) >> 24;
	copy = value;
	ret |= (copy & 0x00FF0000) >> 8;
	copy = value;
	ret |= (copy & 0x0000FF00) << 8;
	copy = value;
	ret |= (copy & 0x000000FF) << 24;
	return (ret);
}

t_bool					is64bit(void)
{
	if (sizeof(void *) == 4)
		return (false);
	return (true);
}
