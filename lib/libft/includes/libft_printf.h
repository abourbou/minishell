/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:43:39 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:44:13 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdarg.h>

typedef struct	s_pf
{
	va_list		*ap;
	int			fzero;
	int			fstars;
	int			fmoins;
	int			fprecision;
	int			fdiese;
	int			fplus;
	int			fspace;
	int			fapostrophe;
	int			vprecision;
	int			width;
	int			whitespace;
	int			zero;
	char		specifier;
	int			length;
	int			fd;
}				t_pf;

void			ft_putnbr_format_fd(long n, int fd);
void			ft_putnbr_ul_base_fd(unsigned long nbr, int fd, char *base);
int				ft_digit_format_base(long num, char *base);
int				ft_digit_ul_base(unsigned long num, char *base);
int				ft_printf(const char *str,
				...) __attribute__((format(printf,1,2)));
int				ft_fprintf(int fd, const char *str,
				...) __attribute__((format(printf,2,3)));
int				pf_conv(t_pf *tpf, const char *format);
void			pf_initlst(va_list *ap, t_pf *tpf, int fd);
void			disp_char(t_pf *tpf);
void			disp_str(t_pf *tpf);
void			disp_int(t_pf *tpf, char *base);
void			disp_ptr(t_pf *tpf, char *base);
void			disp_percent(t_pf *tpf);
int				pf_prec(t_pf *tpf, long val, int argsize);
void			length_calc(t_pf *tpf, int count, ...);
void			init_tab(void);

#endif
