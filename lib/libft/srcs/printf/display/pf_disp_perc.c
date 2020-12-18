/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_disp_perc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:16:28 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 10:16:29 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_put.h"

void	disp_percent(t_pf *tpf)
{
	int nb_space;

	nb_space = (tpf->width > 0) ? tpf->width - 1 : tpf->width;
	tpf->length += nb_space + 1;
	if (!tpf->fmoins)
	{
		while (nb_space--)
		{
			if (tpf->fzero || tpf->zero == -1)
				ft_putchar_fd('0', tpf->fd);
			else
				ft_putchar_fd(' ', tpf->fd);
		}
		ft_putchar_fd('%', tpf->fd);
	}
	else
	{
		ft_putchar_fd('%', tpf->fd);
		ft_putnchar_fd(' ', nb_space, tpf->fd);
	}
}
