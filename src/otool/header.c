#include "nmotool.h"

void			header64(const t_header64 *header)
{
	uint32_t	ncmds;
	void		*ptr;

	ncmds = header->ncmds;
	ptr = (void *)header + sizeof(*header);
	parse64(ncmds, ptr);
}

void			header32(const t_header32 *header)
{
	uint32_t	ncmds;
	void		*ptr;

	ncmds = header->ncmds;
	ptr = (void *)header + sizeof(*header);
	parse32(ncmds, ptr);
}

