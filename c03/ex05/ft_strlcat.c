/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 05:27:44 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/04 05:27:53 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <bsd/string.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	str--;
	while (str++, *str != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	total;
	unsigned int	len_dest;
	unsigned int	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	total = len_src + len_dest;
	if (size <= len_dest)
		return (len_src + size);
	if ((size - len_dest - 1) < len_src)
		len_src = size - len_dest - 1;
	return (total);
}

int	main(void)
{
	unsigned int	n;
	char			s1_strcat[100] = "Scuola 42 Firenze";
	char			s2_strcat[] = "Scuola 42 Roma";
	char			s1[100] = "Scuola 42 Firenze";
	char			s2[] = "Scuola 42 Roma";

	n = 100;
	printf("strlcat:\t%s\n", s1_strcat);
	printf("strlcat: %ld\n", strlcat(s1_strcat, s2_strcat, n));
	printf("strlcat:\t%s\n", s1_strcat);
	printf("strlcat:\t%s\n", s2_strcat);
	printf("ft_strlcat:\t%s\n", s1);
	printf("ft_strlcat: %d\n", ft_strlcat(s1, s2, n));
	printf("ft_strlcat:\t%s\n", s1);
	printf("ft_strlcat:\t%s\n", s2);
	return (0);
}
