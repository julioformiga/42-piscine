/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
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

int	g_max_int = 2147483647;
int	g_max_round_sqrt = 2147395600;
int	g_max_sqrt = 46340;

int	ft_is_prime(int nb)
{
	int	i;

	if (nb == 2)
		return (1);
	if (nb % 2 == 0 || nb == 1)
		return (0);
	i = 3;
	while (i < nb / 2 && i < g_max_sqrt)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	main(void)
{
	int		i;
	int		count_prime;
	clock_t	tic;
	clock_t	toc;

	count_prime = 0;
	tic = clock();
	i = -1;
	while (i++, i < 200)
	{
		if (ft_is_prime(i))
		{
			printf("%d\n", i);
			count_prime++;
		}
	}
	printf("Found %d prime numbers\n", count_prime);
	toc = clock();
	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	return (0);
}
