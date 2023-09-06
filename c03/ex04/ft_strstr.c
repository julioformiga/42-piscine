/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 03:38:15 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/04 03:38:23 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	const char	*a;
	const char	*b;

	b = to_find;
	if (!*b)
		return (str);
	str--;
	while (str++, *str != '\0')
	{
		if (*str != *b)
			continue ;
		a = str;
		while (*a != '\0')
		{
			if (!*b)
				return (str);
			if (*a++ != *b++)
				break ;
		}
		b = to_find;
	}
	return (NULL);
}

int	main(void)
{
	char	strstr_str[100] = "Scuola 42 Firenze";
	char	strstr_to_find[] = "42";
	char	str[100] = "Scuola 42 Firenze";
	char	to_find[] = "42";

	printf("str:\t%s\nfind:\t%s\n", strstr_str, strstr_to_find);
	printf("strstr:\t%s\n", strstr(strstr_str, strstr_to_find));
	printf("--\nstr:\t\t%s\nfind:\t\t%s\n", str, to_find);
	printf("ft_strstr:\t%s\n", ft_strstr(str, to_find));
	return (0);
}
