/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:49:45 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/09/13 14:50:03 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1

void	ft_display_file(char *file_name)
{
	int		fd;
	char	buf[BUF_SIZE];

	fd = open(file_name, O_RDONLY);
	if (fd == -1 || fd == 4)
		write(1, "Cannot read file.\n", 18);
	else
		while (read(fd, buf, BUF_SIZE) != 0)
			write(1, buf, sizeof(buf));
	close(fd);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	ft_display_file(argv[1]);
	return (0);
}
