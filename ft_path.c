/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:28:12 by lmagalha          #+#    #+#             */
/*   Updated: 2022/08/21 22:16:43 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, const char **envp)
{
	int		i;
	int		j;
	char	**paths;
	char	*final_path;
	char	*temp;

	i = 0;
	j = 0;
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
	return (final_path);//aqui retorna erro se não achar nada?
}
