/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:45:33 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/07/17 17:45:33 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

int	main(void)
{
	int	i;

	i = -1;
	printf("Fatorial de %d: %d\n", i, ft_recursive_factorial(i));
	i = 0;
	printf("Fatorial de %d: %d\n", i, ft_recursive_factorial(i));
	i = 1;
	printf("Fatorial de %d: %d\n", i, ft_recursive_factorial(i));
	i = 5;
	printf("Fatorial de %d: %d\n", i, ft_recursive_factorial(i));
	i = 14;
	printf("Fatorial de %d: %d\n", i, ft_recursive_factorial(i));
	return (0);
}
