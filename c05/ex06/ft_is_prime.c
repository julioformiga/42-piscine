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

	if (nb == 2)
		return (1);
	if (nb % 2 == 0 || nb == 1)
		return (0);
	i = 3;
	while(i < nb / 2 && i < MAX_INT_SQRT)
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
/* 	printf("Found " ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET " prime numbers\n", count_prime); */
/* 	clock_t toc = clock(); */
/* 	printf("Elapsed: " ANSI_COLOR_GREEN "%f" ANSI_COLOR_RESET " seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC); */
/*  */
/* 	return (0); */
/* } */
