/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 05:08:52 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/05 05:08:52 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putchar.h"

void	rush(int x, int y)
{
	char	c;
	int		lin;
	int		col;

	lin = 1;
	col = 0;
	while (col < y)
	{
		c = (col != 0 && col != y - 1) ? '|' : 'o';
		ft_putchar(c);
		while (lin < x)
		{
			if (col == 0 || col == y - 1)
				c = (lin == x - 1) ? 'o' : '-';
			else
				c = (lin == x - 1) ? '|' : ' ';
			ft_putchar(c);
			lin++;
		}
		lin = 1;
		ft_putchar('\n');
		col++;
	}
}
