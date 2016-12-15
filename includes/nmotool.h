#ifndef NMOTOOL
# define NMOTOOL

#include "libft.h"
#include <stdio.h> //to remove
#include <stdlib.h>
#include <mach-o/fat.h>
#include <mach-o/loader.h>

#define BASE 16

typedef struct stat					t_stat;
typedef struct mach_header_64		t_header64;
typedef struct mach_header			t_header32;
typedef struct fat_header			t_headerfat; 
typedef struct fat_arch				t_arch;
typedef struct segment_command_64	t_seg64; 
typedef struct segment_command		t_seg32; 
typedef struct section_64			t_sect64;
typedef struct section				t_sect32;

/*
** header.c
*/
void			header64(const t_header64 *header);
void			header32(const t_header32 *header);

/*
** fatheader.c
*/
void			headerfat(const void *ptr, t_bool islittleendian);

/*
** parse.c
*/
void			parse32(const void * ptr, const uint32_t ncmds, const t_seg32 *seg);
void			parse64(const void * ptr, const uint32_t ncmds, const t_seg64 *sef);

/*
** arch.c
*/
int				check_arch(const void *ptr);

/*
** print.c
*/
void			print_section64(const void *ptr, size_t size,\
				uint64_t vmaddr);
void			print_section32(const void *ptr, size_t size,\
				uint64_t vmaddr);
/*
** print_tools.c
*/
void			put_hexa(const void *ptri, size_t nbbytes);
size_t			nbrlen(uint64_t nbr, size_t base);
#endif
