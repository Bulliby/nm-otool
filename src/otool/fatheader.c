#include "nmotool.h"
#include <mach-o/fat.h>

static uint32_t			bigtolitte(uint32_t value)
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

static t_bool	is64bit(void)
{
	if (sizeof(void *) == 4)
		return (false);
	return (true);	
}

static void			archfat(const t_headerfat *header, const uint32_t nbarch)
{
	t_arch			*arch;
	uint32_t		i;

	i = 0;
	arch = (void *)header + sizeof(*header);
	while (i != nbarch)
	{
		if (is64bit() && (bigtolitte(arch->cputype) == CPU_TYPE_X86_64 ||\
		arch->cputype == CPU_TYPE_X86_64))
			header64((void*)header + arch->offset);
		else if (!is64bit() && (arch->cputype == CPU_TYPE_I386 || 
		bigtolitte(arch->cputype) == CPU_TYPE_I386))
			header32((void*)header + arch->offset);
		i++;
	}	
}

void				headerfat(const t_headerfat *header, t_bool islittleendian)
{
	uint32_t		nbarch;

	if (islittleendian)
		nbarch = bigtolitte(header->nfat_arch);
	else
		nbarch = header->nfat_arch;
	archfat(header, nbarch);
}
