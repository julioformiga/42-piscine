/* #include <stdio.h> */

int ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
}

/* int main(void) */
/* { */
/* 	int	i; */
/* 	int	power = 0; */
/*  */
/* 	i = -1; */
/* 	printf("Expoente %d de %d: %d\n", i, power, ft_recursive_power(i, power)); */
/* 	i = 0; */
/* 	printf("Expoente %d de %d: %d\n", i, power, ft_recursive_power(i, power)); */
/* 	i = 1; */
/* 	printf("Expoente %d de %d: %d\n", i, power, ft_recursive_power(i, power)); */
/* 	i = 5; */
/* 	printf("Expoente %d de %d: %d\n", i, power, ft_recursive_power(i, power)); */
/* 	i = 10; */
/* 	printf("Expoente %d de %d: %d\n", i, power, ft_recursive_power(i, power)); */
/* 	return (0); */
/* } */
