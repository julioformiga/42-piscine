/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 01:40:13 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/02 01:40:39 by julio.formiga    ###   ########.fr       */
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

char	*ft_strcapitalize(char *str)
{
	ft_strlowercase(str);
	if (*str >= 'a' && *str <= 'z')
		*str -= 32;
	while (str++, *str != '\0')
	{
		if ((*str <= 32 || *str == '+' || *str == '-')
			&& *(str + 1) >= 'a' && *(str + 1) <= 'z')
		{
			*(str + 1) -= 32;
			continue ;
		}
	}
	return (str);
}

int	main(void)
{
	char	str[] = "saLut, coMMent tu vas ? 42mots quARAnte-deux; cinquaNTe+eT+un";

	printf("%s\n", str);
	ft_strcapitalize(str);
	printf("%s\n", str);
	return (0);
}
