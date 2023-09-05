/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:09:08 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/07/17 18:09:08 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <time.h>

int	g_max_int = 2147483647;
int	g_max_int_round_sqrt = 2147395600;
int	g_max_int_sqrt = 46340;

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb == 2)
		return (1);
	if (nb % 2 == 0 || nb == 1)
		return (0);
	while (i < nb / 2 && i < g_max_int_sqrt)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (nb++, nb < g_max_int)
		if (ft_is_prime(nb))
			return (nb);
	return (0);
}

int	main(void)
{
	int		i;
	int		count_prime;
	int		prime_number;
	clock_t	tic;
	clock_t	toc;

	count_prime = 0;
	tic = clock();
	i = 2147482500;
	i = 0;
	i = 321320;
	while (i++, i < 343230)
		if (ft_is_prime(i))
			count_prime++;
	printf("Found %d prime numbers\n", count_prime);
	toc = clock();
	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	prime_number = 2147483587;
	printf("Prime: %d\n", prime_number);
	printf("Next prime: %d\n", ft_find_next_prime(prime_number));
	return (0);
}
