/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 04:43:27 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/08/25 04:30:03 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
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

	parray = ft_range(35, 36);
	if (parray != NULL)
	{
		while (*parray)
		{
			printf("%d ", *parray);
			parray++;
		}
	}
	else
		printf("Vazio");
	printf("\n");
	return (0);
}
