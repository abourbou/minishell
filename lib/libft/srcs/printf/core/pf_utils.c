/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:16:24 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 10:16:25 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_string.h"

int	pf_prec(t_pf *tpf, long val, int argsize)
{
	int length;

	length = argsize;
	if (tpf->fprecision && tpf->specifier == 's')
	{
		(tpf->vprecision == -1) ? tpf->vprecision = 0 : 0;
		return (tpf->vprecision < argsize) ? tpf->vprecision : argsize;
	}
	else if (!ft_charstr(tpf->specifier, "duixXp"))
	{
		length = tpf->width;
		length -= (tpf->vprecision <= argsize) ? argsize : tpf->vprecision;
		length -= (tpf->width > tpf->vprecision &&
					tpf->vprecision >= argsize && val < 0) ? 1 : 0;
	}
	return (length);
}
