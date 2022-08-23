/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:22:23 by lmagalha          #+#    #+#             */
/*   Updated: 2022/08/21 22:43:35 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char argv[], char *envp[])
{
	int	fd_pipe[2];
	int	pid[2];

	if (argc != 5)
	{
		ft_printf("Invalid number of arguments\n");
		return (0);
	}
	else
	{
		if (pipe(fd_pipe) == -1)
			//return erro
		fd_pipe[0] = open(argv[4], O_RDONLY | O_CREAT | O_TRUNC);
		fd_pipe[1] = open(argv[1], O_WRONLY);
		//creating child proccess 1
		pid[0] = fork();
		if (pid[0] == -1)
		{
			//erro
		}
		else if (pid[0] == 0)
		{
			close(fd_pipe[0]);
			dup2(fd_pipe[1], STDOUT_FILENO);
			close(fd_pipe[1]);
			//achar o caminho
			//execve cmd1
		}
		waitpid(pid[0], NULL, 0);// as flags são essas??
		//creating child proccess 2
		pid[1] = fork();
		if (pid[1] == -1)
		{
			//erro
		}
		else if (pid[1] == 0)
		{
			close(fd_pipe[1]);
			dup2(fd_pipe[0], STDIN_FILENO);
			close(fd_pipe[0]);
			//cmd2
		}
	}
	return (0);
}
