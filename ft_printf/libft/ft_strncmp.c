/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:18:59 by lmagalha          #+#    #+#             */
/*   Updated: 2022/05/27 11:06:58 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (str1[i] - str2[i]);
	while ((i < n - 1)
		&& (str1[i] == str2[i]) && (str1[i] != '\0' || str2[i] != '\0'))
		i++;
	return (str1[i] - str2[i]);
}
