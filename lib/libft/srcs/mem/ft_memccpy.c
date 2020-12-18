/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:24 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:28 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	unsigned char const	*psrc;
	char				*pdst;
	size_t				i;

	if (!dst && !src)
		return (0);
	i = 0;
	psrc = src;
	pdst = dst;
	while (i < n)
	{
		*(pdst + i) = *(psrc + i);
		if (*(psrc + i) == (unsigned char)c)
			return (&(*(pdst + i + 1)));
		i++;
	}
	return (NULL);
}
