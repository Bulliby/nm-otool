#include "nmotool.h"

static void			section(const uint32_t nsects, const t_sect32 *sect)
{
	uint32_t		x;

	x = 0;
	while (x != nsects)
	{
		if (!ft_strcmp(sect->sectname, "__text"))
		{
			ft_puthexa((void *)sect + sect->offset, sect->size + sect->offset); 
		}
		sect += sect->size;
		x++;
	}

}

void				parse32(const uint32_t ncmds, const t_seg32 *seg)
{
	uint32_t		i;
	uint32_t		nsect;
	t_sect32		*sect;
	
	i = 0;
	while (i != ncmds)
	{
		if (seg->cmd == LC_SEGMENT && !ft_strcmp(seg->segname, "__TEXT"))
		{
			nsect = seg->nsects;
			sect = (void *)seg + sizeof(*seg);
			section(nsect, sect);
		}
		seg = (void *) seg + seg->cmdsize;
		i++;
	}
}

void			parse64(const uint32_t ncmds, const t_seg64 *seg)
{
	(void)ncmds;
	(void)seg;
}
