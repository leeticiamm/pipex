/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:37:02 by lmagalha          #+#    #+#             */
/*   Updated: 2022/07/11 15:42:34 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_conv(const char *str, va_list list, int i)
{
	if (str[i] == 'c')
		return (ft_putchar_fd(va_arg(list, int), 1));
	else if (str[i] == 's')
		return (ft_putstr_fd(va_arg(list, char *), 1));
	else if (str[i] == 'p')
		return (ft_putnbr_p(va_arg(list, unsigned long), "0123456789abcdef"));
	else if (str[i] == 'i' || str[i] == 'd')
		return (ft_putnbr_fd(va_arg(list, int)));
	else if (str[i] == 'u')
		return (ft_putnbr_u(va_arg(list, unsigned int)));
	else if (str[i] == 'x')
		return (ft_putnbr_h(va_arg(list, unsigned int), "0123456789abcdef"));
	else if (str[i] == 'X')
		return (ft_putnbr_h(va_arg(list, unsigned int), "0123456789ABCDEF"));
	else if (str[i] == '%')
		return (ft_putchar_fd(str[i], 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			count = count + ft_print_conv(str, list, i + 1);
			i++;
		}
		else
			count = count + ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(list);
	return (count);
}
