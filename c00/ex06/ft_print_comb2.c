/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 03:26:49 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/08/25 03:26:49 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(int n1, int n2, int n3, int n4)
{
	int	pair1;
	int	pair2;

	pair1 = ((n1 - 48) * 10) + (n2 - 48);
	pair2 = ((n3 - 48) * 10) + (n4 - 48);
	if (pair1 < pair2)
	{
		write(1, &n1, 1);
		write(1, &n2, 1);
		write(1, " ", 1);
		write(1, &n3, 1);
		write(1, &n4, 1);
		if (pair1 + pair2 < 197)
			write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;
	int	n3;
	int	n4;

	n1 = 47;
	n2 = 47;
	n3 = 47;
	n4 = 47;
	while (n1++, n1 <= 57)
	{
		while (n2++, n2 <= 57)
		{
			while (n3++, n3 <= 57)
			{
				while (n4++, n4 <= 57)
					ft_print_numbers(n1, n2, n3, n4);
				n4 = 47;
			}
			n3 = 47;
		}
		n2 = 47;
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
