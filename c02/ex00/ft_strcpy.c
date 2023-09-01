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
	char	str[6] = "Final";
	char	str_destino[8] = "Destino";

	printf("str: %s\n", str);
	printf("strd: %s\n", str_destino);
	/* ft_strcpy(str_destino, str); */
	strcpy(str_destino, str);
	printf("str: %s\n", str);
	printf("strd: %s\n", str_destino);
	return (0);
}
