/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:14:04 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/03 17:14:04 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (s1 == s2)
		return (0);
	i = -1;
	while (i++, i < n && *s1)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	if (i > 0)
		return (0);
	return (-s2[i]);
}

int	main(void)
{
	unsigned int	n;
	char			*s1;
	char			*s2;

	n = 13;
	s1 = "Scuola 42 Firenze";
	s2 = "Scuola 42 Roma";
	printf("strcmp:\t\t%d\n", strncmp(s1, s2, n));
	printf("ft_strcmp:\t%d\n", ft_strncmp(s1, s2, n));
	return (0);
}
