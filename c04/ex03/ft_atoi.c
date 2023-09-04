/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:57:55 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/04 16:00:26 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int		i;
	int		result;
	int		minus;
	char	strnbr[11];

	i = 0;
	minus = 0;
	str--;
	while (str++, *str != '\0')
	{
		if (i == 0 && *str == '-')
			minus++;
		else if (*str >= '0' && *str <= '9')
			strnbr[i++] = *str;
		else if (i > 0 && !(*str >= '0' && *str <= '9'))
			break ;
	}
	result = 0;
	i = -1;
	while (i++, strnbr[i] != '\0')
		result = (result * 10) + (strnbr[i] - '0');
	if (minus % 2 != 0)
		result = -result;
	return (result);
}

int	main(void)
{
	char	*str;

	str = " - -   ---+--+1234ab567";
	printf("%d", ft_atoi(str));
	return (0);
}
