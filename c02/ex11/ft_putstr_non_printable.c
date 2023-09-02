/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:51:21 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/02 23:51:21 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_dec2hex(int dec)
{
	int		i;
	int		temp;
	char	hex[100];

	i = 1;
	write(1, "\\", 1);
	if (dec < 16)
		write(1, "0", 1);
	while (dec != 0)
	{
		temp = dec % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 87;
		hex[i++] = temp;
		dec = dec / 16;
	}
	while (i--, i > 0)
		write(1, &hex[i], 1);
}

void	ft_putstr_non_printable(char *str)
{
	str--;
	while (str++, *str)
	{
		if (!(*str >= 32 && *str <= 126))
			ft_dec2hex(*str);
		else
			write(1, str, 1);
	}
}

int	main(void)
{
	char	*str = "\nCoucou\ntu vas bien\t?";

	printf("%s\n", str);
	ft_putstr_non_printable(str);
	write(1, "\n", 1);
	return (0);
}
