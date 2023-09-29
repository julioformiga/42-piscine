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
#include <stdbool.h>

#define DEBUG 0
#define MATRIZ 6

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
		j++;
		if (j == MATRIZ)
		{
			i++;
			if (i == MATRIZ)
				break ;
			j = 0;
		}
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

int	ft_check_solution_values(int **solution, int row, int col, int num)
{
	int	i;

	i = -1;
	while (i++, i < MATRIZ)
		if (solution[row][i] == num || solution[i][col] == num)
			return (0);
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
		if (ft_check_solution_values(solution, row, col, num))
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

int	main(void)
{
	char	*argv;
	int		**matriz;
	/* int		**matriz_resolv; */
	int		**matriz_fixvals;

	/* argv = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"; */
	/* argv = "3 3 2 1 2 1 3 3 4 2 1 2 1 2 4 2"; */
	/* argv = "3 2 1 3 2 2 3 5 1 3 3 3 2 1 2 2 1 3 3 2"; */
	/* argv = "2 3 3 1 2 2 2 1 5 2 2 3 1 2 3 2 1 4 3 2"; */
	/* resolv = "1253431425253415421343152"; */
	/* argv = "2 2 1 4 2 3 3 1 3 3 2 2 3 1 3 2 4 2 3 2 1 3 2 3"; */
	/* argv = "1 2 2 3 3 2 5 1 2 3 2 4 1 2 3 2 3 2 5 1 2 3 2 4"; */
	argv = "3 2 2 4 4 1 2 3 3 2 1 4 3 3 2 2 1 2 1 2 3 3 4 2";
	/* resolv = "654231532416143625416352321564265143"; */
	matriz = ft_text_to_matriz(argv);
	/* matriz_resolv = ft_resolv_matriz(matriz); */
	/* ft_print_game(matriz, matriz_resolv); */
	ft_print_matriz(matriz);
	/* if(ft_check_matriz(matriz, matriz_resolv)) */
	/* 	printf("Success\n"); */
	/* else */
	/* 	printf("Error\n"); */

	matriz_fixvals = ft_create_matriz(MATRIZ, MATRIZ);
	/* matriz_fixvals[2][2] = 3; */
	/* matriz_fixvals[3][5] = 2; */
	/* matriz_fixvals[4][4] = 6; */
	/* matriz_fixvals[5][4] = 4; */
	matriz_fixvals[0][3] = 1;
	matriz_fixvals[2][3] = 5;
	matriz_fixvals[3][2] = 2;
	matriz_fixvals[4][1] = 1;
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
		/* free(matriz[i]); */
		/* if (solution[i] != NULL) */
		/* 	free(solution[i]); */
	}
	free(matriz_fixvals);
	free(matriz);
	/* if (solution != NULL) */
		free(solution);
	return (0);
}
