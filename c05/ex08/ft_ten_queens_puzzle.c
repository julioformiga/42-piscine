/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:44:21 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/07/17 17:44:21 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_check_pos(int pos, int *temp, int val)
{
	int	i;

	i = -1;
	while (i++, i < pos)
	{
		if (
			val == temp[i]
			|| (val == temp[i] + pos - i && temp[i] + pos - i < 10)
			|| (val == temp[i] - (pos - i) && temp[i] - (pos - i) > -1)
		)
			return (0);
	}
	return (1);
}

void	ft_print_array(int arr[], int length)
{
	int	i;
	int	a;

	i = -1;
	while (i++, i < length)
	{
		a = arr[i] + 48;
		write(1, &a, 1);
	}
	write(1, "\n", 1);
}

int	ft_recursive(int pos, int *temp, int count)
{
	int	i;

	i = -1;
	while (i++, i <= 9)
	{
		if (ft_check_pos(pos, temp, i))
		{
			temp[pos] = i;
			if (pos == 9)
			{
				ft_print_array(temp, 10);
				return (count + 1);
			}
			count = ft_recursive(pos + 1, temp, count);
		}
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	temp[10];

	return (ft_recursive(0, temp, 0));
}

/* int main(void) */
/* { */
/* 	ft_ten_queens_puzzle(); */
/* 	return (1); */
/* } */
