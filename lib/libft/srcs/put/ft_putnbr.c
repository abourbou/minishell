/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:39 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:40 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_put.h"
#include "libft_string.h"

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_putnbr_fd(long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putnbr_base(long n, char *base)
{
	int	basesize;

	basesize = ft_strlen(base);
	if (!base || !basesize)
		return ;
	if (ft_strichr(base, '+') || ft_strichr(base, '-'))
		return ;
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n / basesize)
		ft_putnbr_base(n / basesize, base);
	ft_putchar(base[n % basesize]);
}

void	ft_putnbr_base_fd(long n, int fd, char *base)
{
	int	basesize;

	basesize = ft_strlen(base);
	if (!base || !basesize)
		return ;
	if (ft_strichr(base, '+') || ft_strichr(base, '-'))
		return ;
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n / basesize)
		ft_putnbr_base_fd(n / basesize, fd, base);
	ft_putchar_fd(base[n % basesize], fd);
}
