/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:44:56 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:44:57 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hash.h"

void	ft_hashadd_back(t_hash **hash, t_hash *new)
{
	t_hash *hashlast;
	t_hash *hashbefore;

	if (new == 0)
		return ;
	if (*hash == 0)
		*hash = new;
	else
	{
		hashbefore = *hash;
		while (hashbefore->next)
			hashbefore = hashbefore->next;
		hashlast = ((*hash)->last(*hash));
		hashlast->next = new;
		new->head = *hash;
		new->before = hashbefore;
	}
}

void	ft_hashadd_front(t_hash **hash, t_hash *new)
{
	t_hash *tmp;

	if (!hash || !new)
		return ;
	new->next = *hash;
	(*hash)->before = new;
	*hash = new;
	tmp = *hash;
	while (tmp)
	{
		tmp->head = *hash;
		tmp = tmp->next;
	}
}
