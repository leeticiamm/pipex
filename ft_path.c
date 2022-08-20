/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:28:12 by lmagalha          #+#    #+#             */
/*   Updated: 2022/08/09 15:49:26 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	*ft_findpath(char *cmd, char **env)
{
	int		i;
	int		j;
	char	**paths;
	char	*final_path;
	char	*temp;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i],"PATH=", 5) == 0)
		{
			paths = ft_split(env[i] + 5, ":");
			printf("%s\n", paths);
			while (paths[j])
			{
				temp = ft_strjoin(paths[j], '/');
				final_path = ft_strjoin(temp, cmd);
				printf("%s\n", final_path);
				j++;
			}
		}
		i++;
	}
	return (final_path);
}

int	main(void)
{
	char	*var;

	var = ft_findpath("cat", (char **)envp);
	return (0);
}
