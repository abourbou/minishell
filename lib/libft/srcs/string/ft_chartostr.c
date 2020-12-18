/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:41 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:42 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_mem.h"

char	*ft_chartostr(int c)
{
	char *str;

	if (!(str = ft_calloc(2, sizeof(char))))
		return (0);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
