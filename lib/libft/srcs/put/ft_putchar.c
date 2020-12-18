/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:38 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:39 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_put.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putchar_int(int c)
{
	write(1, &c, 1);
	return (c);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnchar(char c, int n)
{
	while (n-- > 0)
	{
		write(1, &c, 1);
	}
}

void	ft_putnchar_fd(char c, int n, int fd)
{
	while (n-- > 0)
	{
		write(fd, &c, 1);
	}
}
