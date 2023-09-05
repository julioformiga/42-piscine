/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:17:06 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/05 04:23:20 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		argv[0]--;
		while (argv[0]++, *argv[0] != '\0')
			write(1, argv[0], 1);
		write(1, "\n", 1);
	}
	return (0);
}
