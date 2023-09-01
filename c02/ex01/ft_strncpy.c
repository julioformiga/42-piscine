/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:09:58 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/01 16:09:58 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <string.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (i++, i < n && src[i] != '\0')
		dest[i] = src[i];
	i--;
	while (i++, i < n)
		dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char	str[14] = "String inicial";
	char	str_final[13] = "String final";

	printf("str: %s\n", str);
	printf("strd: %s\n", str_final);
	ft_strncpy(str_final, str, 8);
	/* strncpy(str_final, str, 8); */
	printf("str: %s\n", str);
	printf("strd: %s\n", str_final);
	return (0);
}
