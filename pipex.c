/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:22:23 by lmagalha          #+#    #+#             */
/*   Updated: 2022/08/23 17:10:24 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_pipe[2];
	int	fd[2];
	int	pid[2];

	if (argc != 5)
	{
		ft_printf("Invalid number of arguments\n");
		return (0);
	}
	else
	{
		if (pipe(fd_pipe) == -1)
		{
			return (0); //retornar algum erro aqui
		}
		fd[0] = open(argv[4], O_RDONLY | O_CREAT | O_TRUNC, 0777); //outfile
		fd[1] = open(argv[1], O_WRONLY); //infile
		//creating child proccess 1
		pid[0] = fork();
		if (pid[0] == -1)
		{
			//erro
		}
		else if (pid[0] == 0)
		{
			dup2(fd[1], STDIN_FILENO);
			close(fd[1]);
			execve(find_path(argv[2], envp), *argv[2], **envp);
			dup2(STDOUT_FILENO, fd_pipe[1]);
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
			dup2(fd_pipe[0], STDIN_FILENO);
			close(fd_pipe[0]);
			execve(find_path(argv[3], envp), *argv[3], **envp);
			dup2(STDOUT_FILENO, fd[0]);
			dup2(fd[0], 1);
		}
	}
	return (0);
}
