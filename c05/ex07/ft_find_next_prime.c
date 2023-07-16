/* #include <stdio.h> */
/* #include <unistd.h> */
/* #include <time.h> */
/*  */
/* #define ANSI_COLOR_RED     "\x1b[31m" */
/* #define ANSI_COLOR_GREEN   "\x1b[32m" */
/* #define ANSI_COLOR_YELLOW  "\x1b[33m" */
/* #define ANSI_COLOR_BLUE    "\x1b[34m" */
/* #define ANSI_COLOR_MAGENTA "\x1b[35m" */
/* #define ANSI_COLOR_CYAN    "\x1b[36m" */
/* #define ANSI_COLOR_RESET   "\x1b[0m" */

int MAX_INT				= 2147483647;
int MAX_INT_ROUND_SQRT	= 2147395600;
int MAX_INT_SQRT		= 46340;

int ft_is_prime(int nb)
{
	int i;

	i = 3;
	if (nb == 2)
		return (1);
	if (nb % 2 == 0 || nb == 1)
		return (0);
	while(i < nb / 2 && i < MAX_INT_SQRT)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int ft_find_next_prime(int nb)
{
	while(nb++, nb < MAX_INT)
		if (ft_is_prime(nb))
			return (nb);
	return (0);
}

/* int main(void) */
/* { */
/* 	int	i; */
/* 	int count_prime = 0; */
/* 	int prime_number; */
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
/* 	printf("Found " ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET " prime numbers\n", count_prime); */
/* 	clock_t toc = clock(); */
/* 	printf("Elapsed: " ANSI_COLOR_GREEN "%f" ANSI_COLOR_RESET " seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC); */
/*  */
/* 	prime_number = 190; */
/* 	prime_number = 2147483587; */
/* 	prime_number = 2147483629; */
/* 	printf("Next prime number (%d): %d\n", prime_number, ft_find_next_prime(prime_number)); */
/*  */
/* 	return (0); */
/* } */
