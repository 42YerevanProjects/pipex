/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:12:25 by shovsepy          #+#    #+#             */
/*   Updated: 2021/06/30 17:41:16 by shovsepy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "./libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

extern char	**environ;

void		ft_pipe_start(int fd[2], int file1, char *cmd1);
void		ft_pipe_end(int fd[2], int file2, char *cmd2);

#endif
