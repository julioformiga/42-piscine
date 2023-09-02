/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 02:17:16 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/02 02:17:24 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <bsd/string.h>
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_src;

	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (size <= 0)
		return (len_src);
	i = -1;
	while (i++, i < size - 1 && i < len_src)
		dest[i] = src[i];
	dest[i] = '\0';
	return (len_src);
}

int	main(void)
{
	unsigned int	i;
	unsigned int	n;
	char			bsd_str[11] = "BS Inicial";
	char			bsd_str_final[9] = "BS Final";
	char			str[11] = "FT Inicial";
	char			str_final[9] = "FT Final";

	n = 1;
	i = strlcpy(bsd_str_final, bsd_str, n);
	printf("strlcpy i:\t%d\n", i);
	printf("strlcpy s:\t%s\n", bsd_str);
	printf("strlcpy d:\t%s\n", bsd_str_final);
	i = ft_strlcpy(str_final, str, n);
	printf("ft_strlcpy i:\t%d\n", i);
	printf("ft_strlcpy s:\t%s\n", str);
	printf("ft_strlcpy d:\t%s\n", str_final);
	return (0);
}
