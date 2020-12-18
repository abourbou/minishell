/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:43 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:47 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i_s1;
	size_t	i_s2;
	size_t	size_max;

	if (!s1 || !s2)
		return (NULL);
	i_s1 = ft_strlen(s1);
	i_s2 = -1;
	size_max = i_s1 + ft_strlen(s2);
	while (i_s1 < size_max)
		s1[i_s1++] = s2[++i_s2];
	s1[i_s1] = '\0';
	return (s1);
}
