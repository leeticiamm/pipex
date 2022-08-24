/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:22:23 by lmagalha          #+#    #+#             */
/*   Updated: 2022/08/24 16:53:02 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_in;
	int	fd[2];
	int	pid1;
	int	pid2;
	int	fd_out;

	if (argc != 5)
	{
		ft_printf("Invalid number of arguments\n");
		return (0);
	}
	else
	{
		if (pipe(fd) == -1)
		{
			return (0); //retornar algum erro aqui
		}
//		fd[0] = open(airgv[4], O_RDONLY | O_CREAT | O_TRUNC, 0777); //outfile
		//creating child proccess 1
		pid1 = fork();
		if (pid1 == -1)
			return (0);
			//erro
		else if (pid1 == 0)
		{
			fd_in = open(argv[1], O_RDONLY); //infile
			dup2(fd_in, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			//close(fd_in);
			//close(fd[1]);
			close(fd[0]);
			char ** ola;
			ola = ft_split(argv[2], ' ');
	//		printf("%s\n", find_path(argv[2], envp));
			execve(find_path(ola[0], envp), ola, envp);	
		}
		//waitpid(pid1, NULL, 0);// as flags são essas??
		//creating child proccess 2
		//pid2 = fork();
		//if (pid2 == -1)
		//{
		//	return (0);
			//erro
		//}
		//else if (pid2 == 0)
		else
		{
			fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664); //outfile
			dup2(fd[0], STDIN_FILENO);
			dup2(fd_out, STDOUT_FILENO);
			//close(fd[0]);
			close(fd[1]);
			//close(fd_out);
			char ** dope;
			dope = ft_split(argv[3], ' ');
			execve(find_path(dope[0], envp), dope, envp);
		}
	}
	return (0);
}
