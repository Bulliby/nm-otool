#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <mach-o/fat.h>
#include <mach-o/loader.h>

#include "nmotool.h"

static int			map_file(int fd)
{
	void			*ptr;
	int				ret;
	t_stat			st;

	ret = EXIT_SUCCESS;
	if (fstat(fd, &st) < 0)
	{
		ft_putendl_fd("fstat error", 2);
		ret = EXIT_FAILURE;
	}
	else 
	{
		if ((ptr = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0))\
		== MAP_FAILED)
		{
			ft_putendl_fd("can't mmap", 2);
			ret = EXIT_FAILURE;
		}
		else
		{
			check_arch(ptr);
			if (munmap(ptr, st.st_size) < 0)
				ft_putendl_fd("munmap failed", 2);
		}
	}
	return (ret);
}

static int			open_files(char *file)
{
	int				ret;
	int				fd;
	
	ret = EXIT_SUCCESS;
	if (((fd = open(file, O_RDONLY)) < 0))
	{
		ft_putstr("Can't open file : ");
		ft_putendl(file);
		ret = EXIT_FAILURE;
	}
	else
	   ret = map_file(fd);
	return (ret);	
}

static int			hanlde_files(char **argv)
{
	int				ret;

	ret = EXIT_SUCCESS;
	argv++;
	while (*argv)
	{
		if (open_files(*argv) == EXIT_FAILURE)
			ret = EXIT_FAILURE;
		argv++;
	}
	return (ret);
}

int			main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putendl("Enter a file name");
		return (EXIT_FAILURE);
	}
	return (hanlde_files(argv));
}
