/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:12:55 by shovsepy          #+#    #+#             */
/*   Updated: 2021/06/30 17:46:04 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_get_path(void)
{
	int		i;
	char	**path;

	path = NULL;
	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "PATH", 4) == 0)
		{
			environ[i] += 5;
			path = ft_split(environ[i], ':');
			break ;
		}
		i++;
	}
	return (path);
}

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

static void	ft_exec(char **args, char *cmd)
{
	char	**path;
	char	*temp;
	char	*newcmd;
	int		i;

	i = 0;
	path = ft_get_path();
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		newcmd = ft_strjoin(temp, cmd);
		if (execve(newcmd, args, environ) == -1)
		{
			free(newcmd);
			free(temp);
			i++;
			continue ;
		}
		free(newcmd);
		free(temp);
		ft_free(path);
		break ;
	}
	ft_putstr_fd("Failed to execute the command!!!\n", 1);
	exit(0);
}

void	ft_pipe_start(int fd[2], int file1, char *cmd1)
{
	char	**args;

	close(fd[0]);
	args = ft_split(cmd1, ' ');
	if (dup2(file1, 0) == -1)
	{
		ft_putstr_fd("Failed to link file1 to STDIN!!!\n", 1);
		exit(0);
	}
	if (dup2(fd[1], 1) == -1)
	{
		ft_putstr_fd("Failed to link the pipe to STDOUT!!!\n", 1);
		exit(0);
	}
	if (args[0][0] == '/')
	{
		if (execve(args[0], args, environ) == -1)
			ft_putstr_fd("Invalid absolute path!!!\n", 1);
	}
	else
		ft_exec(args, args[0]);
	ft_free(args);
	close(file1);
	close(fd[1]);
	wait(NULL);
}

void	ft_pipe_end(int fd[2], int file2, char *cmd2)
{
	char	**args;

	close(fd[1]);
	args = ft_split(cmd2, ' ');
	if (dup2(file2, 1) == -1)
	{
		ft_putstr_fd("Failed to link file2 to STDOUT!!!", 1);
		exit(0);
	}
	if (dup2(fd[0], 0) == -1)
	{
		ft_putstr_fd("Failed to link the pipe to STDIN!!!", 1);
		exit(0);
	}
	if (args[0][0] == '/')
	{
		if (execve(args[0], args, environ) == -1)
			ft_putstr_fd("Invalid absolute path!!!\n", 1);
	}
	else
		ft_exec(args, args[0]);
	ft_free(args);
	close(file2);
	close(fd[0]);
}
