/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:28:53 by lmagalha          #+#    #+#             */
/*   Updated: 2022/06/04 11:21:42 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	if (s1 != 0 && set != 0)
	{
		while (s1[i] != '\0' && ft_strchr(set, s1[i]))
			i++;
		while (j > i && ft_strchr(set, s1[j - 1]))
			j--;
		str = malloc(sizeof(char) * (j - i + 1));
		if (!str)
			return (0);
		ft_strlcpy(str, &s1[i], j - i + 1);
		return (str);
	}
	return (0);
}
