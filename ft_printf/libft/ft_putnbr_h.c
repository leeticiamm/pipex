/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:48:44 by lmagalha          #+#    #+#             */
/*   Updated: 2022/07/11 15:12:06 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_h(unsigned int n, char *hexa)
{
	int		len;
	char	*str;

	str = ft_itoa_h(n, hexa);
	len = ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
