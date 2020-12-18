/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:23 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:24 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"
#include "libft_string.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*m;

	if (!(m = wrmalloc(count * size)))
		return (NULL);
	ft_bzero(m, size * count);
	return (m);
}
