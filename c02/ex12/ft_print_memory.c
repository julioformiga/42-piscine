/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 01:05:36 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/03 01:05:51 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_memory_addr(const void *ptr)
{
	int		i;
	int		len_str;
	char	*hex_digit;
	char	address_str[20];
	char	*p;

	hex_digit = "0123456789abcdef";
	p = address_str;
	i = sizeof(ptr) * 2;
	while (i--, i >= 0)
		*p++ = hex_digit[((size_t)ptr >> (i * 4)) & 0xF];
	*p = '\0';
	len_str = 0;
	while (address_str[len_str])
		len_str++;
	write(STDOUT_FILENO, address_str, len_str);
}

void	ft_print_memory_hex(
	char c, unsigned int i, unsigned int j, unsigned int size
)
{
	char	*bytes;
	char	byte_str[3];
	int		n;

	bytes = &c;
	if (i + j < size)
	{
		n = -1;
		while (n++, n < 1)
		{
			byte_str[0] = "0123456789abcdef"[bytes[n] / 16];
			byte_str[1] = "0123456789abcdef"[bytes[n] % 16];
			byte_str[2] = '\0';
			write(STDOUT_FILENO, byte_str, 2);
		}
	}
	else
		write(1, "  ", 2);
	if (j % 2 == 1)
		write(1, " ", 1);
}

void	ft_print_memory_text(
	char c, unsigned int i, unsigned int j, unsigned int size
)
{
	if (i + j < size)
	{
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
			write(1, ".", 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	*ptr;

	ptr = addr;
	i = 0;
	while (i < size)
	{
		ft_print_memory_addr(ptr + i);
		write(1, ": ", 2);
		j = -1;
		while (j++, j < 16)
			ft_print_memory_hex(ptr[i + j], i, j, size);
		j = -1;
		while (j++, j < 16)
			ft_print_memory_text(ptr[i + j], i, j, size);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

int	main(void)
{
	char			*str;
	unsigned int	len_str;

	str = "Bonjour les aminches\n\n\nc'est f se avec\n\n\nprint_memory\t\nbuffer[lol].";
	len_str = 0;
	while (str[len_str])
		len_str++;
	ft_print_memory(str, len_str);
	return (0);
}
