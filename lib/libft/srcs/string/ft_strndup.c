/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:55 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:55 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_mem.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ptr;
	size_t	sizes1;

	sizes1 = ft_strlen(s1);
	if (sizes1 < n)
		n = sizes1;
	if (!(ptr = wrmalloc((n + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(ptr, s1, n);
	ptr[n] = '\0';
	return (ptr);
}
