/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:25:44 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/04 06:06:39 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putchar.h"

void	rush(int x, int y)
{
	int		lin;
	int		col;
	char	c;

	lin = 1;
	col = 0;
	while (col < y)
	{
		c = (col != 0 && col != y - 1) ? 'B' : 'A';
		ft_putchar(c);
		while (lin < x)
		{
			if (col == 0 || col == y - 1)
				c = (lin == x - 1) ? 'C' : 'B';
			else
				c = (lin == x - 1) ? 'B' : ' ';
			if (col == 0 && lin == x - 1) c = 'C'; /* hack */
			ft_putchar(c);
			lin++;
		}
		lin = 1;
		ft_putchar('\n');
		col++;
	}
}
