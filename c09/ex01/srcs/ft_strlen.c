/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:59:30 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/04 15:59:30 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	str--;
	while (str++, *str != '\0')
		len++;
	return (len);
}

int	main(void)
{
	char	*str;
	char	str_array[100] = "Scuola 42\t Firenze\nC01: ex06\n";

	str = "Scuola 42\t Firenze\nC01: ex06\n";
	printf("strlen:\t\t%ld\n", strlen(str));
	printf("ft_strlen:\t%d\n", ft_strlen(str));
	printf("ft_strlen:\t%d\n", ft_strlen(str_array));
	return (0);
}
