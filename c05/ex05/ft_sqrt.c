/* #include <stdio.h> */
/* #include <unistd.h> */
/* #include <time.h> */

int MAX_INT = 2147483647;
int MAX_ROUND_SQRT = 2147395600;
int MAX_SQRT = 46340;

int ft_sqrt(int nb)
{
	int i = 0;

	while(i++, i <= MAX_SQRT)
		if (i * i == nb)
			return (i);
	return (0);
}

/* int main(void) */
/* { */
/* 	int	i; */
/*  */
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
/* 	i = MAX_ROUND_SQTR; */
/* 	printf("Sqrt %d: %d\n", i, ft_sqrt(i)); */
/* 	clock_t toc = clock(); */
/* 	printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC); */
/*  */
/* 	return (0); */
/* } */
