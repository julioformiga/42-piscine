/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 01:38:53 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/02 01:38:53 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

char	*ft_strlowercase(char *str)
{
	str--;
	while (str++, *str != '\0')
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
	return (str);
}

int	main(void)
{
	char	str[] = "ScUOlA 42 Firenze";

	printf("%s\n", str);
	ft_strlowercase(str);
	printf("%s\n", str);
	return (0);
}
