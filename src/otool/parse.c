#include "nmotool.h"

static void			section32(const void * ptr, const uint32_t nsects, \
					const t_sect32 *sect)
{
	uint32_t		x;

	x = 0;
	while (x != nsects)
	{
		if (!ft_strcmp(sect->sectname, "__text"))
		{
			ft_puthexa((void *)ptr + sect->offset, sect->size); 
		}
		sect += sect->size;
		x++;
	}

}

void				parse32(const void * ptr, const uint32_t ncmds,\
					const t_seg32 *seg)
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
			section32(ptr, nsect, sect);
		}
		seg = (void *) seg + seg->cmdsize;
		i++;
	}
}

static void			section64(const void * ptr, const uint32_t nsects,\
					const t_sect64 *sect)
{
	uint32_t		x;

	x = 0;
	while (x != nsects)
	{
		if (!ft_strcmp(sect->sectname, "__text"))
		{
			ft_puthexa((void *)ptr + sect->offset, sect->size); 
		}
		sect += sect->size;
		x++;
	}

}

void				parse64(const void * ptr, const uint32_t ncmds,\
					const t_seg64 *seg)
{
	uint32_t		i;
	uint32_t		nsect;
	t_sect64		*sect;
	
	i = 0;
	while (i != ncmds)
	{
		if (seg->cmd == LC_SEGMENT_64 && !ft_strcmp(seg->segname, "__TEXT"))
		{
			nsect = seg->nsects;
			sect = (void *)seg + sizeof(*seg);
			section64(ptr, nsect, sect);
		}
		seg = (void *) seg + seg->cmdsize;
		i++;
	}
}
