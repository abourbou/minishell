/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:16:20 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 10:16:22 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft_put.h"

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int		i;
	t_pf	tpf;

	i = 0;
	va_start(ap, str);
	tpf.length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			pf_initlst(&ap, &tpf, 1);
			i += pf_conv(&tpf, str + i + 1);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			tpf.length++;
		}
		i++;
	}
	va_end(ap);
	return (tpf.length);
}

int	ft_fprintf(int fd, const char *str, ...)
{
	va_list	ap;
	int		i;
	t_pf	tpf;

	i = 0;
	va_start(ap, str);
	tpf.length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			pf_initlst(&ap, &tpf, fd);
			i += pf_conv(&tpf, str + i + 1);
		}
		else
		{
			ft_putchar_fd(str[i], fd);
			tpf.length++;
		}
		i++;
	}
	va_end(ap);
	return (tpf.length);
}
