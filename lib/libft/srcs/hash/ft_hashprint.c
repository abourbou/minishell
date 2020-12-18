/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:13 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:14 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hash.h"
#include "libft_printf.h"

void	ft_hashprint(t_hash *hash, char *s)
{
	while (hash)
	{
		ft_printf("%s (%s\t%s)\n", s, hash->key, hash->value);
		hash = hash->next;
	}
}
