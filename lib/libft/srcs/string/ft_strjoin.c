/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:51 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:52 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_mem.h"
#include "libft_number.h"
#include "libft_ctype.h"
#include <stdarg.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	sizes1;
	size_t	sizes2;
	size_t	i;

	if (s1 == 0 && s2 != 0)
		return (ft_strdup(s2));
	if (s2 == 0 && s1 != 0)
		return (ft_strdup(s1));
	if (s2 == 0 && s1 == 0)
		return (0);
	sizes1 = ft_strlen(s1);
	sizes2 = ft_strlen(s2);
	if ((s1 == 0 && s2 == 0)
	|| !(ptr = wrmalloc((sizes1 + sizes2 + 1) * sizeof(char))))
		return (0);
	i = -1;
	while (++i < sizes1)
		ptr[i] = s1[i];
	i = -1;
	while (++i < sizes2)
		ptr[i + sizes1] = s2[i];
	ptr[sizes2 + sizes1] = '\0';
	return (ptr);
}

char	*ft_strmjoin(char *format, ...)
{
	va_list ap;
	char	*tmp;
	char	*ret;

	tmp = 0;
	ret = ft_strdup("");
	if (!format)
		return (0);
	va_start(ap, format);
	while (*format)
	{
		if (*format == 's')
			tmp = ft_strjoin(ret, va_arg(ap, char *));
		else if (*format == 'd')
			tmp = ft_strjoin(ret, ft_itoa(va_arg(ap, int)));
		else if (*format == 'c')
			tmp = ft_strjoin(ret, ft_chartostr(va_arg(ap, int)));
		else if (ft_isspace(*format))
			tmp = ft_strjoin(ret, ft_chartostr(*format));
		wrfree(ret);
		ret = tmp;
		format++;
	}
	va_end(ap);
	return (ret);
}
