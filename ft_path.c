/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:28:12 by lmagalha          #+#    #+#             */
/*   Updated: 2022/08/24 17:05:35 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	int		i;
	int		j;
	char	**paths;
	char	*final_path;
	char	*temp;

	i = 0;
	j = 0;
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	while (envp[i])
	{
		if (ft_strncmp(envp[i],"PATH=", 5) == 0)
		{
				paths = ft_split(envp[i] + 5, ':');
			while (paths[j])
			{
				temp = ft_strjoin(paths[j], "/");
				final_path = ft_strjoin(temp, cmd);
				free(temp);
				if (access(final_path, F_OK | X_OK) == 0)
					return (final_path);
				else
					j++;
			}
		}
		i++;
	}
	if (access(final_path, F_OK | X_OK) == -1)
	{
		i = 0;
		write(2, "zsh: command not found: ", 24);
		if (!(cmd))
		{
			write(2, "\n", 1);
			exit(127);
		}
		while (cmd[i])
			write(2, &cmd[i++], 1);
		write(2, "\n", 1);
		exit(127);
	}
	return (final_path);
}
