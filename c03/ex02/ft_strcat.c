/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:16:17 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/03 17:16:28 by julio.formiga    ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	len = ft_strlen(dest);
	i = -1;
	while (i++, src[i] != '\0')
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}

int	main(void)
{
	char	s1_strcat[100] = "Scuola 42 Firenze";
	char	s2_strcat[] = "\tScuola 42 Roma";
	char	s1[100] = "Scuola 42 Firenze";
	char	s2[] = "\tScuola 42 Roma";

	printf("strcmp:\t\t%s\n", s1_strcat);
	strcat(s1_strcat, s2_strcat);
	printf("strcmp:\t\t%s\n", s1_strcat);
	printf("ft_strcmp:\t%s\n", s1);
	ft_strcat(s1, s2);
	printf("ft_strcmp:\t%s\n", s1);
	return (0);
}
