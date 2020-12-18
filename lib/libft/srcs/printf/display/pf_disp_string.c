/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_disp_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:16:30 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 10:16:30 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"
#include "libft_put.h"

void	disp_str(t_pf *tpf)
{
	int				argsize;
	char			*value;
	int				tronc;

	if (!(value = va_arg(*(tpf->ap), char *)))
		value = "(null)";
	if (tpf->fprecision && tpf->vprecision == -1)
		argsize = 0;
	else
		argsize = ft_strlen(value);
	tronc = pf_prec(tpf, 0, argsize);
	(tpf->width > 0) ? tpf->whitespace = tpf->width - tronc : 0;
	length_calc(tpf, 2, tronc, tpf->whitespace);
	if (tpf->fmoins == FALSE)
	{
		ft_putnchar_fd(' ', tpf->whitespace, tpf->fd);
		ft_putnstr_fd(value, tronc, tpf->fd);
	}
	else
	{
		ft_putnstr_fd(value, tronc, tpf->fd);
		ft_putnchar_fd(' ', tpf->whitespace, tpf->fd);
	}
}
