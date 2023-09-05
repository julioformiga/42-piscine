/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:27:09 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/08/25 03:21:50 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	nb;

	nb = 47;
	while (nb++, nb <= 57)
		write(1, &nb, 1);
}

int	main(void)
{
	ft_print_numbers();
	return (0);
}
