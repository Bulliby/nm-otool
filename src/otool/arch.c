#include "nmotool.h"

static int			magic_key(const void *ptr, uint32_t cigam, uint32_t magic)
{
	if (!ft_memcmp(ptr, &cigam, sizeof(uint32_t)) || 
	!ft_memcmp(ptr, &magic, sizeof(uint32_t)))
		header32(ptr);
	else if (!ft_memcmp(ptr, &cigam, sizeof(uint32_t)) || 
	!ft_memcmp(ptr, &magic, sizeof(uint32_t)))
		header32(ptr);
	else if (ft_memcmp(ptr, &cigam, sizeof(uint32_t)))		
		headerfat(ptr, true);
	else if (ft_memcmp(ptr, &magic, sizeof(uint32_t)))		
		headerfat(ptr, false);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				check_arch(const void *ptr)
{
	int			ret;

	ret = EXIT_SUCCESS;
	ret |= magic_key(ptr, MH_CIGAM, MH_MAGIC);	
	ret |= magic_key(ptr, MH_CIGAM_64, MH_MAGIC_64);	
	ret |= magic_key(ptr, FAT_CIGAM, FAT_MAGIC);	
	if (ret == EXIT_FAILURE)
		ft_putendl_fd("Bad Architecture", 2);
	return (ret);
}
