/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:37:52 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/09 01:54:54 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		isep;
	char	*str;

	str = (char *)malloc(size * sizeof(char));
	i = -1;
	j = 0;
	while (i++, i < size)
	{
		strs[i]--;
		while (strs[i]++, *strs[i] != 0)
			str[j++] = *strs[i];
		isep = -1;
		while (isep++, i < size - 1 && sep[isep] != 0)
			str[j++] = sep[isep];
	}
	return (str);
}

int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*sep;
	char	*str[3];

	str1 = "Scuola";
	str2 = "42";
	str3 = "Firenze";
	sep = " - ";
	str[0] = str1;
	str[1] = str2;
	str[2] = str3;
	printf("Sep: %s\n", sep);
	printf("String 1: %s\n", *str);
	printf("String 2: %s\n", *(str + 1));
	printf("String 3: %s\n", *(str + 2));
	printf("Final String: %s\n", ft_strjoin(3, str, " - "));
	return (0);
}
