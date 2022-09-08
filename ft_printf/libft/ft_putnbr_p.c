/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:48:44 by lmagalha          #+#    #+#             */
/*   Updated: 2022/07/11 15:37:27 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_p(unsigned long n, char *hexa)
{
	int				len;
	char			*str;
	unsigned long	nb;

	nb = (unsigned long) n;
	write (1, "0x", 2);
	str = ft_itoa_h(n, hexa);
	len = ft_putstr_fd(str, 1);
	free(str);
	return (len + 2);
}
