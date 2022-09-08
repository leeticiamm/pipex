/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:48:44 by lmagalha          #+#    #+#             */
/*   Updated: 2022/07/11 14:45:13 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
