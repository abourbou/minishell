/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:11 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:12 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hash.h"
#include <stddef.h>

size_t	ft_hashlen(t_hash *hash)
{
	size_t i;

	i = 0;
	if (!hash)
		return (0);
	while (hash)
	{
		i++;
		hash = hash->next;
	}
	return (i);
}
