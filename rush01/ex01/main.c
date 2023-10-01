/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:44:45 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/04 06:06:40 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DEBUG 0
#define MATRIZ 7

int	**ft_create_matriz(int rows, int cols)
{
	int	i;
	int	j;
	int	**matriz;

	matriz = malloc(rows * sizeof(int *));
	i = -1;
	while (i++, i < cols)
	{
		matriz[i] = malloc(cols * sizeof(int));
		j = -1;
		while (j++, j < rows)
			matriz[i][j] = 0;
	}
	return (matriz);
}

int	**ft_text_to_matriz(char *text)
{
	int	i;
	int	j;
	int	c;
	int	**matriz;

	matriz = ft_create_matriz(4, MATRIZ);
	i = 0;
	j = 0;
	while (*text)
	{
		c = *text++;
		if (c == 32)
			continue ;
		matriz[i][j] = c - 48;
		if (matriz[i][j] < 1 || matriz[i][j] > MATRIZ)
		{
			write(1, "Invalid game!\n", 14);
			return (NULL);
		}
		j++;
		if (j == MATRIZ)
		{
			i++;
			j = 0;
			if (i == MATRIZ)
				break ;
		}
	}
	if (i != 4 || j != 0)
	{
		printf("%d - %d", i, j);
		write(1, "Invalid game!\n", 14);
		return (NULL);
	}
	return (matriz);
}

int	**ft_matriz_invert(int **matriz)
{
	int	i;
	int	j;
	int	**matriz_invert;

	matriz_invert = ft_create_matriz(MATRIZ, MATRIZ);
	i = -1;
	while (i++, i < MATRIZ)
	{
		j = -1;
		while (j++, j < MATRIZ)
			matriz_invert[j][i] = matriz[i][j];
	}
	return (matriz_invert);
}

void	ft_print_digit(int i)
{
	int	num;

	num = i + 48;
	write(1, &num, 1);
}

void	ft_print_matriz(int **matriz)
{
	int	i;
	int	j;

	i = -1;
	write(1, "  ", 2);
	while (i++, i < MATRIZ)
	{
		ft_print_digit(matriz[0][i]);
		write(1, " ", 1);
	}
	write(1, "\n", 1);
	i = -1;
	while (i++, i < MATRIZ)
	{
		ft_print_digit(matriz[2][i]);
		j = 0;
		while (j++, j < (MATRIZ * 2) + 2)
			write(1, " ", 1);
		ft_print_digit(matriz[3][i]);
		write(1, "\n", 1);
	}
	i = -1;
	write(1, "  ", 2);
	while (i++, i < MATRIZ)
	{
		ft_print_digit(matriz[1][i]);
		write(1, " ", 1);
	}
	write(1, "\n", 1);
}

void	ft_print_matriz_resolv(int **matriz)
{
	int	row;
	int	col;

	row = -1;
	col = -1;
	write(1, "\n", 1);
	while (row++, row < MATRIZ)
	{
		write(1, "  ", 2);
		col = -1;
		while (col++, col < MATRIZ)
		{
			ft_print_digit(matriz[row][col]);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

void	ft_print_game(int **matriz, int **matriz_resolv)
{
	int	i;
	int	ir;

	i = -1;
	write(1, "  ", 2);
	while (i++, i < MATRIZ)
	{
		ft_print_digit(matriz[0][i]);
		write(1, " ", 1);
	}
	write(1, "\n", 1);
	i = -1;
	while (i++, i < MATRIZ)
	{
		ft_print_digit(matriz[2][i]);
		write(1, " ", 1);
		ir = -1;
		write(1, "\e[1m", 4);
		while (ir++, ir < MATRIZ)
		{
			if (matriz_resolv[i][ir] == 0)
				write(1, " ", 1);
			else
				ft_print_digit(matriz_resolv[i][ir]);
			write(1, " ", 1);
		}
		write(1, "\e[m", 3);
		ft_print_digit(matriz[3][i]);
		write(1, "\n", 1);
	}
	i = -1;
	write(1, "  ", 2);
	while (i++, i < MATRIZ)
	{
		ft_print_digit(matriz[1][i]);
		write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int	ft_check_matriz_line_repeat(int *line)
{
	int	i;
	int	j;
	int	sum;

	i = -1;
	while (i++, i < MATRIZ)
	{
		sum = 0;
		j = -1;
		while (j++, j < MATRIZ)
		{
			if (line[j] == line[i])
			{
				sum++;
				if (sum == 2)
				{
					if (DEBUG)
						printf("Repeat: %d\n", line[j]);
					return (1);
				}
			}
		}
	}
	return (0);
}

int	ft_check_matriz_line(int *line, int init, int end)
{
	int	i;
	int	sum;
	int	lmax;

	if(ft_check_matriz_line_repeat(line))
		return (1);
	i = -1;
	sum = 1;
	lmax = line[0];
	while (i++, i < MATRIZ - 1)
	{
		if (lmax == MATRIZ)
			break;
		if (lmax < line[i + 1])
			sum++;
		if (line[i] < line[i + 1])
			lmax = line[i + 1];
	}
	if (sum != init)
		return (1);
	i = MATRIZ;
	sum = 1;
	lmax = line[MATRIZ - 1];
	while (i--, i > 0)
	{
		if (lmax == MATRIZ)
			break;
		if (lmax < line[i - 1])
			sum++;
		if (line[i] < line[i - 1])
			lmax = line[i - 1];
	}
	if (sum != end)
		return (1);
	return (0);
}

int	ft_check_matriz(int **matriz, int **matriz_resolv)
{
	int	i;
	int	**matriz_invert;

	i = -1;
	while (i++, i < MATRIZ)
		if (ft_check_matriz_line(matriz_resolv[i], matriz[2][i], matriz[3][i]))
			return (0);
	matriz_invert = ft_matriz_invert(matriz_resolv);
	i = -1;
	while (i++, i < MATRIZ)
		if (ft_check_matriz_line(matriz_invert[i], matriz[0][i], matriz[1][i]))
			return (0);
	return (1);
}

int	**ft_resolv_matriz(int **matriz)
{
	int		row;
	int		col;
	int		**matriz_resolv;
	char	*resolv;

	(void)matriz;
	/* resolv = "1234234134124123"; */
	/* resolv = "1253431425253415421343152"; */
	resolv = "654231532416143625416352321564265143";
	matriz_resolv = ft_create_matriz(MATRIZ, MATRIZ);
	row = -1;
	col = -1;
	while (row++, row < MATRIZ)
	{
		col = -1;
		while (col++, col < MATRIZ)
			matriz_resolv[row][col] = *resolv++ - 48;
	}
	return (matriz_resolv);
}

int	ft_check_solution_values(int **matriz, int **solution, int row, int col, int num)
{
	int	i;
	int	j;

	i = -1;
	while (i++, i < MATRIZ)
		if (solution[row][i] == num || solution[i][col] == num)
			return (0);

	i = -1;
	while (i++, i < MATRIZ)
	{
		j = -1;
		while (j++, j < 4)
		{
			if (row == j && col == i && matriz[0][i] > j + 1 && num >= MATRIZ - (matriz[0][i]) + j + 2)
				return (0);
			if (row == MATRIZ - (j + 1) && col == i && matriz[1][i] > j + 1 && num >= MATRIZ - (matriz[1][i]) + j + 2)
				return (0);
			if (row == i && col == j && matriz[2][i] > j + 1 && num >= MATRIZ - (matriz[2][i]) + j + 2)
				return (0);
			if (row == i && col == MATRIZ - (j + 1) && matriz[3][i] > j + 1 && num >= MATRIZ - (matriz[3][i]) + j + 2)
				return (0);
		}
	}
	return (1);
}

int	ft_solve_skyscraper(int **matriz, int **solution, int **matriz_fixvals, int row, int col)
{
	int	num;

	if (row == MATRIZ)
	{
		/* ft_print_matriz_resolv(solution); */
		if (!ft_check_matriz(matriz, solution))
			return (0);
		return (1);
	}
	if (matriz_fixvals[row][col] != 0)
	{
		if (col == MATRIZ - 1)
			return ft_solve_skyscraper(matriz, solution, matriz_fixvals, row + 1, 0);
		else
			return ft_solve_skyscraper(matriz, solution, matriz_fixvals, row, col + 1);
	}
	num = 0;
	while (num++, num <= MATRIZ)
	{
		if (ft_check_solution_values(matriz, solution, row, col, num))
		{
			solution[row][col] = num;
			if (col == MATRIZ - 1)
			{
				if (ft_solve_skyscraper(matriz, solution, matriz_fixvals, row + 1, 0))
					return (1);
			}
			else
			{
				if (ft_solve_skyscraper(matriz, solution, matriz_fixvals, row, col + 1))
					return (1);
			}
			solution[row][col] = 0;
		}
	}
	return (0);
}

int	**ft_generate_solutions(int **matriz, int **matriz_fixvals)
{
	int	i;
	int	j;
	int	**solution;

	if (matriz == NULL || matriz_fixvals == NULL)
		return (NULL);
	solution = (int **)malloc(MATRIZ * sizeof(int *));
	i = -1;
	while (i++, i < MATRIZ)
		solution[i] = (int *)malloc(MATRIZ * sizeof(int));
	i = -1;
	while (i++, i < MATRIZ)
	{
		j = -1;
		while (j++, j < MATRIZ)
			solution[i][j] = matriz_fixvals[i][j];
	}
	if (ft_solve_skyscraper(matriz, solution, matriz_fixvals, 0, 0))
		return (solution);
	else
		return (NULL);
}

int	**ft_create_matriz_fixvals(int **matriz, int **matriz_fixvals)
{
	int	i;
	int	j;
	int	row;
	int	col;
	int	aux;

	i = -1;
	while (i++, i < 4)
	{
		j = -1;
		while (j++, j < MATRIZ)
		{
			if (i == 0) {
				row = i;
				col = j;
			}
			else if (i == 1) {
				row = MATRIZ - 1;
				col = j;
			}
			else if (i == 2) {
				row = j;
				col = 0;
			}
			else if (i == 3) {
				row = j;
				col = MATRIZ - 1;
			}
			if (matriz[i][j] == 1)
			{
				matriz_fixvals[row][col] = MATRIZ;
				if (i == 0 && matriz[1][j] == 2)
					matriz_fixvals[MATRIZ - 1][col] = MATRIZ - 1;
				else if (i == 1 && matriz[0][j] == 2)
					matriz_fixvals[0][col] = MATRIZ - 1;
				else if (i == 2 && matriz[3][j] == 2)
					matriz_fixvals[row][MATRIZ - 1] = MATRIZ - 1;
				else if (i == 3 && matriz[2][j] == 2)
					matriz_fixvals[row][0] = MATRIZ - 1;
			}
			else if (matriz[i][j] == MATRIZ)
			{
				if (i == 0 || i == 2)
				{
					aux = -1;
					while (aux++, aux < MATRIZ)
					{
						if (i == 0)
							matriz_fixvals[row + aux][col] = aux + 1;
						else
							matriz_fixvals[row][col + aux] = aux + 1;
					}
				}
				else
				{
					aux = MATRIZ;
					while (aux--, aux >= 0)
					{
						if (i == 1)
							matriz_fixvals[aux][col] = MATRIZ - aux;
						else
							matriz_fixvals[row][aux] = MATRIZ - aux;
					}
				}
			}
		}
	}
	return (matriz_fixvals);
}

int	main(void)
{
	char	*argv;
	int		**matriz;
	/* int		**matriz_resolv; */
	int		**matriz_fixvals;

	/* argv = "2213213231322213"; */
	/* argv = "3321213342121242"; */
	/* argv = "32132235133321221332"; */
	/* argv = "23312221522312321432"; */
	/* argv = "322441233214332212123342"; */
	/* argv = "623221132224532321125224"; */
	/* argv = "223421332312321233144232"; */
	/* argv = "212223334122231324423213"; */
	/* argv = "423312321232422123231433"; */
	/* argv = "3223142132522435223312124323"; */
	argv = "4322213231324333223122212353";
	/* argv = "5132223241342223332134222143"; */
	/* argv = "23442143432134232132343334122243"; */
	matriz = ft_text_to_matriz(argv);
	if (!matriz)
		return (1);
	/* matriz_resolv = ft_resolv_matriz(matriz); */
	/* ft_print_game(matriz, matriz_resolv); */
	/* ft_print_matriz(matriz); */
	/* if(ft_check_matriz(matriz, matriz_resolv)) */
	/* 	printf("Success\n"); */
	/* else */
	/* 	printf("Error\n"); */

	matriz_fixvals = ft_create_matriz(MATRIZ, MATRIZ);
	ft_create_matriz_fixvals(matriz, matriz_fixvals);
	/* matriz_fixvals[1][5] = 7; */
	/* matriz_fixvals[2][0] = 3; */
	/* matriz_fixvals[2][2] = 4; */
	/* matriz_fixvals[2][3] = 1; */
	/* matriz_fixvals[3][1] = 6; */

	/* argv = "4322213231324333223122212353"; */
	matriz_fixvals[2][4] = 4;
	matriz_fixvals[6][6] = 3;
	matriz_fixvals[5][2] = 4;
	matriz_fixvals[5][5] = 2;
	matriz_fixvals[6][6] = 3;

	/* matriz_fixvals[0][1] = 5; */
	/* matriz_fixvals[1][1] = 4; */
	/* matriz_fixvals[1][3] = 6; */
	/* matriz_fixvals[1][4] = 2; */
	/* matriz_fixvals[2][0] = 2; */
	/* matriz_fixvals[3][0] = 4; */
	/* matriz_fixvals[3][5] = 5; */
	/* matriz_fixvals[3][6] = 6; */
	/* matriz_fixvals[4][3] = 7; */
	/* matriz_fixvals[4][4] = 8; */
	/* matriz_fixvals[4][7] = 5; */
	/* matriz_fixvals[6][5] = 3; */
	/* matriz_fixvals[6][7] = 2; */
	/* matriz_fixvals[7][2] = 5; */
	/* matriz_fixvals[7][5] = 4; */

	ft_print_game(matriz, matriz_fixvals);
	int **solution = ft_generate_solutions(matriz, matriz_fixvals);

	if (solution != NULL)
	{
		printf("Solution found:\n");
		ft_print_game(matriz, solution);
	}
	else
		printf("Could not find solution for this puzzle.");
	printf("\n");

	for (int i = 0; i < MATRIZ; i++)
	{
		free(matriz_fixvals[i]);
		/* if (solution[i] != NULL) */
		/* 	free(solution[i]); */
	}
	free(matriz_fixvals);
	/* free(matriz); */
	/* if (solution != NULL) */
	/* 	free(solution); */
	return (0);
}
