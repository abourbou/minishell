/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_disp_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:16:29 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 10:16:30 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_put.h"

static void	disp_ptr_2(t_pf *tpf, char *base, unsigned long val)
{
	if (tpf->fmoins == FALSE)
	{
		ft_putnchar_fd(' ', tpf->whitespace, tpf->fd);
		(tpf->specifier == 'p') ? ft_putstr_fd("0x", tpf->fd) : 0;
		ft_putnchar_fd('0', tpf->zero, tpf->fd);
		if (!(tpf->fprecision == 1 && val == 0 && tpf->vprecision <= 0))
			ft_putnbr_ul_base_fd(val, tpf->fd, base);
	}
	else
	{
		(tpf->specifier == 'p') ? ft_putstr_fd("0x", tpf->fd) : 0;
		ft_putnchar_fd('0', tpf->zero, tpf->fd);
		if (!(tpf->fprecision == 1 && val == 0 && tpf->vprecision <= 0))
			ft_putnbr_ul_base_fd(val, tpf->fd, base);
		ft_putnchar_fd(' ', tpf->whitespace, tpf->fd);
	}
}

void		disp_ptr(t_pf *tpf, char *base)
{
	unsigned long	val;
	int				argsize;

	val = va_arg(*(tpf->ap), unsigned long);
	argsize = ft_digit_ul_base(val, base);
	(tpf->specifier == 'p') ? argsize += 2 : 0;
	tpf->zero = (tpf->fprecision) ? tpf->vprecision - argsize : 0;
	(tpf->vprecision > argsize) ? tpf->zero++ : 0;
	tpf->whitespace = pf_prec(tpf, val, argsize);
	if (tpf->fprecision == 1 && val == 0 && tpf->vprecision <= 0)
	{
		tpf->length--;
		tpf->whitespace++;
	}
	if (tpf->zero && tpf->width > tpf->vprecision)
	{
		(tpf->whitespace > 0) ? tpf->zero += tpf->whitespace : 0;
		tpf->whitespace = 0;
	}
	length_calc(tpf, 3, tpf->whitespace, tpf->zero, argsize);
	disp_ptr_2(tpf, base, val);
}
