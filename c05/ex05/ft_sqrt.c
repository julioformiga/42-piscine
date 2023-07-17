/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:44:21 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/07/17 17:44:21 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* #include <unistd.h> */
/* #include <stdio.h> */
/* #include <time.h> */

int	g_max_int = 2147483647;
int	g_max_round_sqrt = 2147395600;
int	g_max_sqrt = 46340;

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i++, i <= g_max_sqrt)
		if (i * i == nb)
			return (i);
	return (0);
}

/* int	main(void) */
/* { */
/* 	int	i; */
/*  */
/* 	clock_t tic = clock(); */
/* 	i = -500; */
/* 	printf("Sqrt %d: %d\n", i, ft_sqrt(i)); */
/* 	i = 0; */
/* 	printf("Sqrt %d: %d\n", i, ft_sqrt(i)); */
/* 	i = 25; */
/* 	printf("Sqrt %d: %d\n", i, ft_sqrt(i)); */
/* 	i = 225; */
/* 	printf("Sqrt %d: %d\n", i, ft_sqrt(i)); */
/* 	i = 2116; */
/* 	printf("Sqrt %d: %d\n", i, ft_sqrt(i)); */
/* 	i = g_max_round_sqrt; */
/* 	printf("Sqrt %d: %d\n", i, ft_sqrt(i)); */
/* 	clock_t toc = clock(); */
/* 	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC); */
/* 	return (0); */
/* } */
