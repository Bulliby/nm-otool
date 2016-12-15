#include "nmotool.h"

static void			put_ptr32(uint64_t *vmaddr)
{
	size_t		len;

	len = nbrlen(*vmaddr, BASE);
	len = BASE / 2 - len;
	ft_putnchar('0', len);
	ft_putnbrbase(*vmaddr, "0123456789abcdef", BASE);
	*vmaddr += BASE;
}

static void			put_ptr64(uint64_t *vmaddr)
{
	size_t		len;

	len = nbrlen(*vmaddr, BASE);
	len = BASE - len;
	ft_putnchar('0', len);
	ft_putnbrbase(*vmaddr, "0123456789abcdef", BASE);
	*vmaddr += BASE;
}

void			print_section32(const void *ptr, size_t size,\
				uint64_t vmaddr)
{
	while (size > BASE)
	{
		put_ptr32(&vmaddr);
		put_hexa(ptr, BASE);
		ptr+=BASE;
		size-=BASE;
	}
	put_ptr32(&vmaddr);
	put_hexa(ptr, size);
}

void			print_section64(const void *ptr, size_t size,\
				uint64_t vmaddr)
{
	while (size > BASE)
	{
		put_ptr64(&vmaddr);
		put_hexa(ptr, BASE);
		ptr+=BASE;
		size-=BASE;
	}
	put_ptr64(&vmaddr);
	put_hexa(ptr, size);
}
