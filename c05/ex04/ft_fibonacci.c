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
/* #include <stdio.h> */
/* #include <unistd.h> */
/* #include <time.h> */

int	ft_fibonacci(int nb)
{
	if (nb < 0)
		return (-1);
	if (nb == 0 || nb == 1)
		return (nb);
	return (ft_fibonacci(nb - 1) + ft_fibonacci(nb - 2));
}

/* int ft_fibonacci_iterative(int nb) */
/* { */
/* 	int	a, b, swap; */
/*  */
/* 	if (nb < 0) */
/* 		return (-1); */
/* 	a = 0; */
/* 	b = 1; */
/* 	for(int i = 0; i < nb; i++) */
/* 	{ */
/* 		swap = a; */
/* 		a = b; */
/* 		b = swap + b; */
/* 	} */
/* 	return (a); */
/* } */
/*  */
/* int main(void) */
/* { */
/* 	int	i; */
/*  */
/*  */
/* 	clock_t tic = clock(); */
/* 	printf("RECURSIVE\n"); */
/* 	i = -1; */
/* 	printf("Fibonacci %d: %d\n", i, ft_fibonacci(i)); */
/* 	i = 0; */
/* 	printf("Fibonacci %d: %d\n", i, ft_fibonacci(i)); */
/* 	i = 5; */
/* 	printf("Fibonacci %d: %d\n", i, ft_fibonacci(i)); */
/* 	i = 15; */
/* 	printf("Fibonacci %d: %d\n", i, ft_fibonacci(i)); */
/* 	i = 46; */
/* 	printf("Fibonacci %d: %d\n", i, ft_fibonacci(i)); */
/* 	clock_t toc = clock(); */
/* 	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC); */
/*  */
/* 	sleep(1); */
/* 	printf("------------------------\n"); */
/* 	clock_t tic2 = clock(); */
/* 	printf("ITERATIVE\n"); */
/* 	i = -1; */
/* 	printf("Fibonacci %d: %d\n", i, ft_fibonacci_iterative(i)); */
/* 	i = 0; */
/* 	printf("Fibonacci %d: %d\n", i, ft_fibonacci_iterative(i)); */
/* 	i = 5; */
/* 	printf("Fibonacci %d: %d\n", i, ft_fibonacci_iterative(i)); */
/* 	i = 15; */
/* 	printf("Fibonacci %d: %d\n", i, ft_fibonacci_iterative(i)); */
/* 	i = 46; */
/* 	printf("Fibonacci %d: %d\n", i, ft_fibonacci_iterative(i)); */
/* 	clock_t toc2 = clock(); */
/* 	printf("Elapsed: %f seconds\n", (double)(toc2 - tic2) / CLOCKS_PER_SEC); */
/*  */
/* 	return (0); */
/* } */
