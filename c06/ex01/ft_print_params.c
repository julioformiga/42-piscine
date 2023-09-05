/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:21:20 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/05 14:21:44 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		i = 0;
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
