/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:00:01 by lmagalha          #+#    #+#             */
/*   Updated: 2022/09/05 17:06:18 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>

char	*find_path(char *cmd, char **envp);
void	child1(char *argv[], int fd[], char *envp[]);
void	child2(char *argv[], int fd[], char *envp[]);
void	write_error(char *cmd);

#endif
