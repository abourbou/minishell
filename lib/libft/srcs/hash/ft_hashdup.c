/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:03 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:04 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"
#include "libft_hash.h"

t_hash	*ft_hashdup(t_hash *hash)
{
	t_hash *ptr;

	ptr = 0;
	while (hash)
	{
		ft_hashadd_back(&ptr, ft_hashnew(hash->key, hash->value));
		hash = hash->next;
	}
	return (ptr);
}
