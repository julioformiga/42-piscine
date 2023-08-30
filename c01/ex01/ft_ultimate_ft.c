/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:36:48 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/08/30 13:00:27 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_ft(int *********nbr)
{
	int	i;

	i = 42;
	*********nbr = i;
}

int	main(void)
{
	int	i;
	int	*********ptr_i;

	i = 10;
	*********ptr_i = i;
	printf("%d != ", *********ptr_i);
	ft_ultimate_ft(ptr_i);
	printf("%d\n", *********ptr_i);
	return (0);
}
