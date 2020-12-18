/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_disp_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:16:26 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 10:16:27 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_put.h"

void	disp_char(t_pf *tpf)
{
	char	value;
	int		whitespace;

	whitespace = 0;
	value = va_arg(*(tpf->ap), int);
	(tpf->width > 0) ? whitespace = tpf->width - 1 : 0;
	length_calc(tpf, 1, whitespace + 1);
	if (tpf->fmoins == FALSE)
	{
		ft_putnchar_fd(' ', whitespace, tpf->fd);
		ft_putchar_fd(value, tpf->fd);
	}
	else
	{
		ft_putchar_fd(value, tpf->fd);
		ft_putnchar_fd(' ', whitespace, tpf->fd);
	}
}
