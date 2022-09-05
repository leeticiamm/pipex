/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_children.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:49:27 by lmagalha          #+#    #+#             */
/*   Updated: 2022/09/05 17:22:23 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(char *argv[], int fd[], char *envp[])
{
	int		fd_in;
	char	**cmd1;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	dup2(fd_in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd_in);
	close(fd[1]);
	close(fd[0]);
	cmd1 = ft_split(argv[2], ' ');
	execve(find_path(cmd1[0], envp), cmd1, envp);
}

void	child2(char *argv[], int fd[], char *envp[])
{
	int		fd_out;
	char	**cmd2;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fd_out);
	cmd2 = ft_split(argv[3], ' ');
	execve(find_path(cmd2[0], envp), cmd2, envp);
}
