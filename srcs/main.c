/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:12:45 by shovsepy          #+#    #+#             */
/*   Updated: 2021/06/30 17:02:42 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_error(char *message, int exitcode)
{
	ft_putstr_fd(message, STDOUT_FILENO);
	exit(exitcode);
}

int	main(int argc, char **argv)
{
	int		file1;
	int		file2;
	int		fd[2];
	pid_t	id;

	if (argc == 5)
	{
		file1 = open(argv[1], O_RDONLY);
		file2 = open(argv[argc - 1], O_WRONLY);
		if (file1 == -1)
			ft_error("Failed to open the first file\n", 0);
		if (file2 == -1)
			ft_error("Failed to open the second file\n", 0);
		if (pipe(fd) == -1)
			ft_error("Failed to create a pipe!!!\n", 0);
		id = fork();
		if (id == 0)
			ft_pipe_end(fd, file2, argv[3]);
		else
			ft_pipe_start(fd, file1, argv[2]);
		return (0);
	}
	ft_putstr_fd("The argument count is not five!!!\n", 1);
	return (-1);
}
