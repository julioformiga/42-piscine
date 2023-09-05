/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:44:21 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/07/17 17:44:21 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <time.h>

int	ft_fibonacci(int nb)
{
	if (nb < 0)
		return (-1);
	if (nb == 0 || nb == 1)
		return (nb);
	return (ft_fibonacci(nb - 1) + ft_fibonacci(nb - 2));
}

int	ft_fibonacci_iterative(int nb)
{
	int	a;
	int	b;
	int	i;
	int	swap;

	if (nb < 0)
		return (-1);
	a = 0;
	b = 1;
	i = -1;
	while (i++, i < nb)
	{
		swap = a;
		a = b;
		b = swap + b;
	}
	return (a);
}

int	main(void)
{
	int		i;
	clock_t	tic;
	clock_t	toc;
	clock_t	tic2;
	clock_t	toc2;

	tic = clock();
	printf("RECURSIVE\n");
	i = 5;
	printf("Fibonacci %d: %d\n", i, ft_fibonacci(i));
	i = 46;
	printf("Fibonacci %d: %d\n", i, ft_fibonacci(i));
	toc = clock();
	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	printf("------------------------\n");
	tic2 = clock();
	printf("ITERATIVE\n");
	i = 5;
	printf("Fibonacci %d: %d\n", i, ft_fibonacci_iterative(i));
	i = 46;
	printf("Fibonacci %d: %d\n", i, ft_fibonacci_iterative(i));
	toc2 = clock();
	printf("Elapsed: %f seconds\n", (double)(toc2 - tic2) / CLOCKS_PER_SEC);
	return (0);
}
