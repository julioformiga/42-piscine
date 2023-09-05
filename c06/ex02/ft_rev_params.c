/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:18:13 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/05 05:23:38 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		while (argc--, argc >= 1)
		{
			argv[argc]--;
			while (argv[argc]++, *argv[argc] != '\0')
				write(1, argv[argc], 1);
			write(1, "\n", 1);
		}
	}
	return (0);
}
