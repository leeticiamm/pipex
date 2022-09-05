/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:22:23 by lmagalha          #+#    #+#             */
/*   Updated: 2022/09/05 15:55:13 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc != 5)
		ft_printf("Invalid number of arguments\n");
	else
	{
		if (pipe(fd) == -1)
			exit (EXIT_FAILURE);
		pid1 = fork();
		if (pid1 == -1)
			exit (EXIT_FAILURE);
		else if (pid1 == 0)
			child1(argv, fd, envp);
		waitpid(pid1, NULL, 0);
		pid2 = fork();
		if (pid2 == -1)
			exit (EXIT_FAILURE);
		else if (pid2 == 0)
			child2(argv, fd, envp);
	}
	return (0);
}
