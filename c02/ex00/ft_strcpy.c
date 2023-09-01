/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 04:37:15 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/08/31 14:04:26 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <string.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (i++, src[i] != '\0')
		dest[i] = src[i];
	i--;
	while (i++, dest[i] != '\0')
		dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char	str[15] = "String ini\tcial";
	char	str_final[13] = "String fin\tal";

	printf("str: %s\n", str);
	printf("strd: %s\n", str_final);
	ft_strcpy(str_final, str);
	/* strcpy(str_final, str); */
	printf("str: %s\n", str);
	printf("strd: %s\n", str_final);
	return (0);
}
