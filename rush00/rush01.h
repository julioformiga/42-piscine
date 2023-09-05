/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:42:54 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/05 05:12:51 by julio.formiga    ###   ########.fr       */
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
		c = (col != 0 && col != y - 1) ? '*' : '/';
		if (col == y - 1 && lin == 1 && y > 1) c = '\\'; // hack
		ft_putchar(c);
		while (lin < x)
		{
			if (col == 0 || col == y - 1)
				c = (lin == x - 1) ? '/' : '*';
			else
				c = (lin == x - 1) ? '*' : ' ';
			if (col == 0 && lin == x - 1) c = '\\'; // hack
			ft_putchar(c);
			lin++;
		}
		lin = 1;
		ft_putchar('\n');
		col++;
	}
}
