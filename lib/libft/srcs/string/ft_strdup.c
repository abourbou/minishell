/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:49 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:50 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_mem.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		sizes1;

	sizes1 = ft_strlen(s1);
	if (!(ptr = wrmalloc((sizes1 + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(ptr, s1, sizes1 + 1);
	return (ptr);
}
