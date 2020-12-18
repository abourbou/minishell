/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_disp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:16:25 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 10:16:26 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

void	length_calc(t_pf *tpf, int count, ...)
{
	int		x;
	va_list ap;

	va_start(ap, count);
	while (count--)
	{
		x = va_arg(ap, int);
		tpf->length += (x > 0) ? x : 0;
	}
	va_end(ap);
}
