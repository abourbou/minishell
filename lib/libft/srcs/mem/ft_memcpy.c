/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:30 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:31 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*pdst;
	const char	*psrc;

	if (!dest && !src)
		return (NULL);
	pdst = dest;
	psrc = src;
	while (n-- > 0)
		*(pdst + n) = *(psrc + n);
	return (dest);
}
