#include "nmotool.h"

void			header64(const t_header64 *header)
{
	uint32_t	ncmds;
	t_seg64		*seg;

	printf("Arch 64\n");
	ncmds = header->ncmds;
	seg = (void *)header + sizeof(*header);
	parse64(header, ncmds, seg);
}

void			header32(const t_header32 *header)
{
	uint32_t	ncmds;
	t_seg32		*seg;

	printf("Arch 32\n");
	ncmds = header->ncmds;
	seg = (void *)header + sizeof(*header);
	parse32(header, ncmds, seg);
}

