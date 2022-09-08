/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmagalha <lmagalha@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:54:59 by lmagalha          #+#    #+#             */
/*   Updated: 2022/06/03 15:37:56 by lmagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (ft_strlen(src) + 1 < dstsize)
		ft_memcpy(dst, src, ft_strlen(src) + 1);
	else if (dstsize > 0)
		ft_memcpy(dst, src, dstsize - 1);
	dst[dstsize - 1] = '\0';
	return (ft_strlen(src));
}
