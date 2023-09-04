/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 03:33:44 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/04 03:33:54 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				len;

	len = ft_strlen(dest);
	i = -1;
	while (i++, i < nb && src[i] != '\0')
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}

int	main(void)
{
	unsigned int	n;
	char			s1_strcat[100] = "Scuola 42 Firenze";
	char			s2_strcat[] = "\tScuola 42 Roma";
	char			s1[100] = "Scuola 42 Firenze";
	char			s2[] = "\tScuola 42 Roma";

	n = 6;
	printf("strcmp:\t\t%s\n", s1_strcat);
	strncat(s1_strcat, s2_strcat, n);
	printf("strcmp:\t\t%s\n", s1_strcat);
	printf("ft_strcmp:\t%s\n", s1);
	ft_strncat(s1, s2, n);
	printf("ft_strcmp:\t%s\n", s1);
	return (0);
}
