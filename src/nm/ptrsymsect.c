#include "nmotool.h"

static i

static int			search_for_sect(const char *sect, const t_lc *lc, uint8_t index)
{
	uint32_t		i;		
	uint32_t		x;
	uint32_t		count;
	const uint32_t	nsects;

	i = 0;
	count = 0;
	while (i != ncmds)
	{
		if (lc->cmd == LC_SEGEMENT || lc->cmd == LC_SEGEMENT_64)
		{
			x = 0;
			nsects = lc->nsect;
			lc += sizeof(t_seg);
			while (x != nsects)
			{
				count++;
				if (count == index && !ft_strcmp(sect, lc->sectname))
					return true;
				lc += sizeof(t_sect);
				x++;
			}		
		}
		lc = (void *) lc + lc->cmdsize;
		i++;
	}
	return false;
}

void		text(t_argfunc	*arg)
{
	printf("text\n");
}	

void		bbs(t_argfunc	*arg)
{
	printf("bbs\n");
}	

void		data(t_argfunc	*arg)
{
	printf("data\n");
}	

