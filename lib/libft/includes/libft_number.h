/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_number.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:43:38 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:43:39 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_NUMBER_H
# define LIBFT_NUMBER_H

# include "libft_define.h"

int		ft_atoi(const char *str);
char	*ft_itoa_base(int n, char *base);
char	*ft_itoa(int n);
int		ft_digit_base(long num, char *base);
int		ft_digit(long num);
#endif
