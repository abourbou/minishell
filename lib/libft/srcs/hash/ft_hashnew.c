/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:12 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:13 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_hash.h"
#include "libft_mem.h"

t_hash	*ft_hashnew(char *key, void *value)
{
	t_hash *ptr;

	if (!(ptr = wrmalloc(sizeof(t_hash))))
		return (0);
	ptr->key = key;
	ptr->value = value;
	ptr->before = NULL;
	ptr->next = NULL;
	ptr->head = ptr;
	ptr->show = ft_hashprint;
	ptr->last = ft_hashlast;
	ptr->add_back = ft_hashadd_back;
	ptr->add_front = ft_hashadd_front;
	ptr->find = ft_hashfind;
	ptr->delkey = ft_hashdel_key;
	ptr->delhash = ft_hashdel_hash;
	ptr->hclear = ft_hashclear;
	ptr->length = ft_hashlen;
	return (ptr);
}
