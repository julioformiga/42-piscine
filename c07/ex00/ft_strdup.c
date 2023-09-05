/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:39:50 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/08/25 04:28:46 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *src)
{
	char	*strout;

	strout = malloc(strlen(src) + 1);
	if (strout == NULL)
		return (NULL);
	strcpy(strout, src);
	return (strout);
}

int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "Hello, world!";
	str2 = ft_strdup(str1);
	if (str2 == NULL)
	{
		printf("Error allocating memory.\n");
		return (1);
	}
	printf("String 1: %s\n", str1);
	printf("String 2: %s\n", str2);
	free(str2);
	return (0);
}
