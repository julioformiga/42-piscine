/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:07:19 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/03 16:07:22 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (s1 == s2)
		return (0);
	i = -1;
	while (i++, *s1)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (-s2[i]);
}

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "Scuola 42 Roma";
	s2 = "Scuola 42 Firenze";
	printf("strcmp:\t\t%d\n", strcmp(s1, s2));
	printf("ft_strcmp:\t%d\n", ft_strcmp(s1, s2));
	return (0);
}
