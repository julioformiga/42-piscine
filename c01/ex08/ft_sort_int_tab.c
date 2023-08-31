/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:01:18 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/08/31 14:01:18 by julio.formiga    ###   ########.fr       */
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
	{
		write(1, "-2147483648", 11);
		return ;
	}
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
	{
		ft_putchar(nb + 48);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	swap;
	int	i;
	int	j;

	j = 0;
	while (j++, j < size)
	{
		i = 0;
		while (i++, i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				swap = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = swap;
			}
		}
	}
}

int	main(void)
{
	int	i = -1;
	int	size = 6;
	int	tab[6] = {2, 4, 6, 5, 3, 1};

	while (i++, i < size)
		ft_putnbr(tab[i]);
	ft_sort_int_tab(tab, size);
	write(1, "\n", 1);
	i = -1;
	while (i++, i < size)
		ft_putnbr(tab[i]);
	return (0);
}
