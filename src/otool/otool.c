#include <mach-o/loader.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "libft.h"

#define MACH_ARCH 4
typedef struct stat t_stat;

static void		arch_64(int fd)
{
	char			stamp[5];

	ft_bzero(stamp, 5);
	read(fd, stamp, 4);
	if (*(int *)stamp != MH_MAGIC_64)
		ft_quit("Bad architecture", 2, 42);
}	

static void			*map_file(char * const path, int *fd)
{
	t_stat		st;
	void		*ret;

	if ((*fd = open(path, O_RDWR)) == -1)
		ft_quit("open error", 2, 42);
	arch_64(*fd);
	if (fstat(*fd, &st) == -1)
		ft_quit("stat error", 2, 42);
	if ((ret = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, *fd, 0)) == MAP_FAILED)
	   ft_quit("map error2", 2, 42);	
	return (ret);
}

static void						ft_put_hexa(unsigned char c, char *base, char baselen)
{
	char						ret;
	char						modulo;

	ret = c / baselen;
	modulo = c % baselen;
	if (modulo > baselen)
		ft_put_hexa(ret, "0123456789ABCDEF", 16);
	ft_putchar(base[ret]);
	ft_putchar(base[modulo]);
}

static void						print_text(void *ptr, struct section_64 *sect)
{
	unsigned char				c;
	int							i;
	int							size;

	size = sect->size;
	//printf("size [%i]\n", size);
	//printf("offset [%i]\n", sect->offset);
	//size += getpagesize() - (size % getpagesize());
	printf("addr [%p]\n", (void*)sect->addr);
	for (i = sect->offset; i < size + sect->offset; i++)
	{
		c = ((char*)ptr)[i];
		ft_put_hexa(c, "0123456789ABCDEF", 16);
	}
}

static void						get_text(char * const ptr, int fd)
{
	struct mach_header_64		*header;
	int							ncmds;	
	struct load_command			*cmds;
	struct segment_command_64	*seg;
	struct section_64			*sect;
	int							i;
	int							x;
	void						*text;
	static int					count = 0;

	header = (struct mach_header_64 *) ptr;
	ncmds = header->ncmds;
	cmds = (void *)header + sizeof(*header);
	seg = (struct segment_command_64 *)cmds;	
	for (i = 0; i != ncmds; i++)
	{
		if(seg->cmd == LC_SEGMENT_64 && !ft_strcmp(seg->segname, "__TEXT"))
		{
			sect = (void *)seg + sizeof(*seg);
			for (x = 0; x != seg->nsects; x++)
			{
				if (!ft_strcmp(sect->sectname, "__text"))
				{
					print_text(ptr, sect);
					break;
				}
			}
			break ;
		}	
		seg = (void *) seg + seg->cmdsize;
	}
}

int			main(int argc, char **argv)
{
	char	*macho;
	int		fd;

	if (argc != 2)
		ft_quit("At least one arg", 2, 42);
	macho = map_file(argv[1], &fd);
	get_text(macho, fd);
	return (42);
}
