/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 03:42:53 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/08/25 03:42:53 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_print_combn(int n)
{
	int	i;
	int	comb[n];

	if (n < 1 || n > 9)
		return ;
	i = -1;
	while (i++, i < n)
		comb[i] = i;
	while (1)
	{
		i = -1;
		while (i++, i < n)
			ft_putnbr(comb[i]);
		i = n - 1;
		while (i >= 0 && comb[i] == (10 - n) + i)
			i--;
		if (i < 0)
			break ;
		else
			write(1, ", ", 2);
		comb[i]++;
		while (i++, i < n)
			comb[i] = comb[i - 1] + 1;
	}
}

int	main(void)
{
	ft_print_combn(2);
	write(1, "\n", 1);
	ft_print_combn(3);
	write(1, "\n", 1);
	return (0);
}
