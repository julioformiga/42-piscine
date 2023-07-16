/* #include <stdio.h> */

int ft_iterative_power(int nb, int power)
{
	int	i;

	i = 1;
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	while(power--, power >= 0)
		i = i * nb;
	return (i);
}

/* int main(void) */
/* { */
/* 	int	i; */
/* 	int	power = 10; */
/*  */
/* 	i = -1; */
/* 	printf("Expoente %d de %d: %d\n", i, power, ft_iterative_power(i, power)); */
/* 	i = 0; */
/* 	printf("Expoente %d de %d: %d\n", i, power, ft_iterative_power(i, power)); */
/* 	i = 2; */
/* 	printf("Expoente %d de %d: %d\n", i, power, ft_iterative_power(i, power)); */
/* 	i = 5; */
/* 	printf("Expoente %d de %d: %d\n", i, power, ft_iterative_power(i, power)); */
/* 	i = 10; */
/* 	printf("Expoente %d de %d: %d\n", i, power, ft_iterative_power(i, power)); */
/* 	return (0); */
/* } */
