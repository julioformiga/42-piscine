/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 05:18:47 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/06 05:18:48 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	if (!base || base[0] == '\0' || base[1] == '\0')
		return (0);
	i = -1;
	while (i++, base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (j++, base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	char	digit;

	if (!check_base(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	digit = base[nbr % base_len];
	write(1, &digit, 1);
}

int	main(void)
{
	int	n;

	n = 424242;
	write(1, "HEX: ", 5);
	ft_putnbr_base(n, "0123456789ABCDEF");
	write(1, "\n", 1);
	write(1, "BIN: ", 5);
	ft_putnbr_base(n, "01");
	write(1, "\n", 1);
	write(1, "DEC: ", 5);
	ft_putnbr_base(n, "0123456789");
	write(1, "\n", 1);
	write(1, "OCT: ", 5);
	ft_putnbr_base(n, "poneyvif");
	write(1, " ????????\n", 10);
	return (0);
}
