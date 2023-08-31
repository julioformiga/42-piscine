/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 02:00:37 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/08/31 02:00:37 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	str--;
	while (str++, *str != '\0')
		write(1, str, 1);
}

int	main(void)
{
	char	*str;

	str = "Scuola 42\t Firenze\nC01: ex05";
	ft_putstr(str);
	ft_putstr("\nScuola 42\t Firenze\nC01: ex05");
	return (0);
}
