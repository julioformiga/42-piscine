/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:03:31 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/01 18:03:32 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	str--;
	while (str++, *str != '\0')
		if (!(*(str) >= 'A' && *(str) <= 'Z')
			&& !(*(str) >= 'a' && *(str) <= 'z'))
			return (0);
	return (1);
}

int	main(void)
{
	char	*str = "asdsa";
	int		i;

	i = ft_str_is_alpha(str) + 48;
	write(1, &i, 1);
	write(1, "\n", 1);
	return (0);
}
