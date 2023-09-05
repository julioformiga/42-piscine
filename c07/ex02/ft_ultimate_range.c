/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:39:31 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/04 06:06:38 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_ultimate_range(int min, int max)
{
	int	i;
	int	*range;

	if (min >= max)
		return (NULL);
	range = malloc((max - min) * sizeof(int));
	i = -1;
	while (i++, i < (max - min))
		range[i] = min + i;
	return (range);
}

int	main(void)
{
	int	*parray;

	parray = ft_ultimate_range(26, 36);
	if (parray != NULL)
	{
		while (*parray)
		{
			printf("%d ", *parray);
			parray++;
		}
	}
	else
	{
		printf("Vazio");
	}
	printf("\n");
	return (0);
}
