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

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;
	int	*result;

	if (min >= max)
	{
		*range = NULL;
		return (-1);
	}
	size = max - min;
	result = (int *)malloc(size * sizeof(int));
	if (result == NULL)
		return (-1);
	i = -1;
	while (i++, i < size)
		result[i] = min + i;
	*range = result;
	return (i);
}

int	main(void)
{
	int	i;
	int	*arr;
	int	size;

	size = ft_ultimate_range(&arr, 35, 43);
	if (size > 0)
	{
		i = -1;
		while (i++, i < size)
			printf("%d ", arr[i]);
		free(arr);
	}
	else if (size == 0)
		printf("The range is empty.\n");
	else
		printf("Memory allocation failed.\n");
	printf("\n");
	return (0);
}
