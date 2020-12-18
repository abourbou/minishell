/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:15 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:16 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_lstadd_front(t_list **alst, t_list *enew)
{
	if (!alst || !enew)
		return ;
	enew->next = *alst;
	*alst = enew;
}
