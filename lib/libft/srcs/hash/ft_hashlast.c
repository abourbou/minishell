/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:09 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:11 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hash.h"

t_hash	*ft_hashlast(t_hash *hash)
{
	if (!hash)
		return (0);
	while (hash->next)
		hash = hash->next;
	return (hash);
}
