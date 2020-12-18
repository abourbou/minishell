/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:02 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:03 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hash.h"
#include "libft_string.h"
#include "libft_mem.h"

static void		ft_head_change(t_hash **hash)
{
	t_hash *tmp;

	tmp = *hash;
	while (tmp)
	{
		tmp->head = *hash;
		tmp = tmp->next;
	}
}

static void		ft_delete(t_hash *hash)
{
	wrfree(hash->value);
	wrfree(hash->key);
	wrfree(hash);
}

static void		ft_delete_elem(t_hash **hash, t_hash *current)
{
	if (!current->before)
	{
		if (current->next)
		{
			*hash = current->next;
			current->next->before = 0;
			ft_head_change(hash);
		}
		else
		{
			ft_delete(current);
			*hash = 0;
			return ;
		}
	}
	else
	{
		current->before->next = current->next;
		if (current->next)
			current->next->before = current->before;
		ft_delete(current);
	}
}

void			ft_hashdel_key(t_hash **hash, char *key)
{
	t_hash *current;

	current = *hash;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
		{
			ft_delete_elem(hash, current);
		}
		current = current->next;
	}
}

void			ft_hashdel_hash(t_hash **hash, t_hash *del)
{
	t_hash *current;

	current = *hash;
	while (current)
	{
		if (current == del)
		{
			ft_delete_elem(hash, current);
		}
		current = current->next;
	}
}
