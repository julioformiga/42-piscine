/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:59:13 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/01 18:59:13 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	str--;
	while (str++, *str != '\0')
		if (!(*(str) >= 'A' && *(str) <= 'Z'))
			return (0);
	return (1);
}

int	main(void)
{
	char	*str = "ASD";
	int		i;

	i = ft_str_is_uppercase(str) + 48;
	write(1, &i, 1);
	write(1, "\n", 1);
	return (0);
}
