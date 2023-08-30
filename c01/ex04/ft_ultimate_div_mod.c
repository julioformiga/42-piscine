/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:27:44 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/08/30 14:27:44 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	val_a;
	int	val_b;

	val_a = *a;
	val_b = *b;
	*a = val_a / val_b;
	*b = val_a % val_b;
}

int	main(void)
{
	int	*a;
	int	*b;
	int	val_a;
	int	val_b;

	val_a = 11;
	val_b = 2;
	a = &val_a;
	b = &val_b;
	printf("A = %d / B = %d\n", *a, *b);
	ft_ultimate_div_mod(a, b);
	printf("A = %d / B = %d\n", *a, *b);
	return (0);
}
