/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:04:52 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/01 19:05:07 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	str--;
	while (str++, *str != '\0')
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
	return (str);
}

int	main(void)
{
	char	str[] = "ScUOlA 42 Firenze";

	printf("%s\n", str);
	ft_strupcase(str);
	printf("%s\n", str);
	return (0);
}
