/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ctype.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:43:32 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:43:32 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CTYPE_H
# define LIBFT_CTYPE_H

# include "libft_define.h"

int	ft_tolower(int c);
int	ft_toupper(int c);
int	ft_isdigit(int c);
int	ft_isalpha(int c);
int	ft_isalnum(int c);
int	ft_isprint(int c);
int	ft_isspace(int c);
int	ft_isxdigit(int c);
int	ft_islower(int c);
int	ft_isupper(int c);
#endif
