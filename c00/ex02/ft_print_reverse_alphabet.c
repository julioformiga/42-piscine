/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 03:07:51 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/08/25 03:07:51 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 123;
	while (c--, c >= 'a')
		write(1, &c, 1);
}

int	main(void)
{
	ft_print_reverse_alphabet();
	return (0);
}
