/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:18:06 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/05 05:23:38 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (s1 == s2)
		return (0);
	i = -1;
	while (i++, *s1)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (-s2[i]);
}

void	ft_sort_params(char *tab[], int size)
{
	int	swap;
	int	i;
	int	j;

	j = 0;
	while (j++, j < size)
	{
		i = 0;
		while (i++, i < size)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				swap = *tab[i];
				*tab[i] = *tab[i + 1];
				*tab[i + 1] = swap;
			}
		}
	}
}

int	main(int argc, char *argv[])
{
	int		i;

	if (argc > 1)
	{
		i = 0;
		ft_sort_params(argv, argc - 1);
		while (i++, i < argc)
		{
			argv[i]--;
			while (argv[i]++, *argv[i] != '\0')
				write(1, argv[i], 1);
			write(1, "\n", 1);
		}
	}
	return (0);
}
