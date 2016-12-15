#include "nmotool.h"

void			header64(const t_header64 *header)
{
	uint32_t	ncmds;
	t_lc		*lc;

	ft_putendl("Arhc64");
	ncmds = header->ncmds;
	lc = (void *)header + sizeof(*header);
	parse64nm(header, ncmds, lc);
}

void			header32(const t_header32 *header)
{
	uint32_t	ncmds;
	t_lc		*lc;

	ft_putendl("Arhc32");
	ncmds = header->ncmds;
	lc = (void *)header + sizeof(*header);
	parse32nm(header, ncmds, lc);
}

