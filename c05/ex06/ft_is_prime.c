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

int	g_max_int = 2147483647;
int	g_max_int_round_sqrt = 2147395600;
int	g_max_int_sqrt = 46340;

int	ft_is_prime(int nb)
{
	int	i;

	if (nb == 2)
		return (1);
	if (nb % 2 == 0 || nb == 1)
		return (0);
	i = 3;
	while (i < nb / 2 && i < MAX_INT_SQRT)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

/* int main(void) */
/* { */
/* 	int	i; */
/* 	int count_prime = 0; */
/*  */
/*  */
/* 	clock_t tic = clock(); */
/* 	printf(ANSI_COLOR_GREEN); */
/* 	for (i = 2147482500; i < MAX_INT; i++) */
	/* for (i = 0; i < 200; i++) */
/* 	{ */
/* 		if (ft_is_prime(i)) */
/* 		{ */
/* 			printf("%d\n", i); */
/* 			count_prime++; */
/* 		} */
/* 	} */
/* 	printf(ANSI_COLOR_RESET); */
/* 	printf("Found " ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET " prime numbers\n",
 *  	count_prime); */
/* 	clock_t toc = clock(); */
/* 	printf("Elapsed: " ANSI_COLOR_GREEN "%f" ANSI_COLOR_RESET " seconds\n",
 *  	(double)(toc - tic) / CLOCKS_PER_SEC); */
/*  */
/* 	return (0); */
/* } */
