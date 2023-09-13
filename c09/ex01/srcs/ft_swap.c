/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:37:07 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/08/30 13:18:33 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int	main(void)
{
	int	i_a;
	int	i_b;
	int	*swap_a;
	int	*swap_b;

	i_a = 41;
	i_b = 42;
	swap_a = &i_a;
	swap_b = &i_b;
	printf("A = %d - B %d\n", *swap_a, *swap_b);
	ft_swap(swap_a, swap_b);
	printf("A = %d - B %d\n", *swap_a, *swap_b);
	return (0);
}
