/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:27:44 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/08/30 14:27:44 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main(void)
{
	int	a;
	int	b;
	int	*div;
	int	*mod;
	int	div_init;
	int	mod_init;

	a = 11;
	b = 2;
	div_init = 0;
	mod_init = 0;
	div = &div_init;
	mod = &mod_init;
	printf("%d / %d = %d (%d)\n", a, b, *div, *mod);
	ft_div_mod(a, b, div, mod);
	printf("%d / %d = %d (%d)\n", a, b, *div, *mod);
	return (0);
}
