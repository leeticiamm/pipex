/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:26:40 by lmagalha          #+#    #+#             */
/*   Updated: 2022/07/11 14:53:35 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_len(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n = (n / 10);
		count++;
	}
	return (count);
}

char	*ft_itoa_u(unsigned int n)
{
	int		len;
	char	*str;

	len = n_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		str[len--] = 48 - (n % 10);
		n = (n / 10) * (-1);
	}
	while (n)
	{
		str[len--] = 48 + (n % 10);
		n = (n / 10);
	}
	return (str);
}
