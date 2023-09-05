/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 03:03:38 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/08/25 03:03:38 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(int n1, int n2, int n3)
{
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, &n3, 1);
	if (n1 + n2 + n3 != 168)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = 48;
	n2 = 48;
	n3 = 48;
	while (n1 <= 57)
	{
		while (n2 <= 57)
		{
			while (n3 <= 57)
			{
				if (n1 < n2 && n2 < n3)
					ft_print_numbers(n1, n2, n3);
				n3++;
			}
			n3 = 48;
			n2++;
		}
		n2 = 48;
		n1++;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
