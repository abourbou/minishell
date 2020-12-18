/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_put.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:43:40 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:44:15 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PUT_H
# define LIBFT_PUT_H

# include "libft_define.h"
# include <unistd.h>

void	ft_putchar(char c);
int		ft_putchar_int(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnchar(char c, int n);
void	ft_putnchar_fd(char c, int n, int fd);
void	ft_putstr(char *c);
void	ft_putstr_fd(char *c, int fd);
void	ft_putnstr_fd(char *str, int n, int fd);
void	ft_putnbr(long n);
void	ft_putnbr_fd(long n, int fd);
void	ft_putnbr_base(long n, char *base);
void	ft_putnbr_base_fd(long n, int fd, char *base);
#endif
