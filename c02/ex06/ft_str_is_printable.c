/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:00:12 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/01 19:00:38 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	str--;
	while (str++, *str != '\0')
		if (!(*(str) >= 32 && *(str) <= 126))
			return (0);
	return (1);
}

int	main(void)
{
	char	*str = "AS\nD";
	int		i;

	i = ft_str_is_printable(str) + 48;
	write(1, &i, 1);
	write(1, "\n", 1);
	return (0);
}
