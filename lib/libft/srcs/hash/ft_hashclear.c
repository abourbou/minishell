/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:44:57 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:02 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hash.h"

void	ft_hashclear(t_hash **hash)
{
	t_hash *current;
	t_hash *delete;

	current = *hash;
	while (current)
	{
		delete = current;
		ft_hashdel_hash(hash, delete);
		current = current->next;
	}
}
