/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:40 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:40 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_put.h"
#include "libft_string.h"

void	ft_putstr(char *c)
{
	if (!c)
		return ;
	write(1, c, ft_strlen(c));
}

void	ft_putstr_fd(char *c, int fd)
{
	if (!c || !fd)
		return ;
	write(fd, c, ft_strlen(c));
}

void	ft_putnstr_fd(char *str, int n, int fd)
{
	int i;

	i = -1;
	while (++i < n)
		ft_putchar_fd(str[i], fd);
}
