/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:37 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:38 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_number.h"
#include "libft_mem.h"
#include "libft_string.h"

char			*ft_itoa_base(int n, char *base)
{
	char	*str;
	int		i;
	int		sign;
	int		sizebase;

	sizebase = ft_strlen(base);
	sign = 1;
	i = ft_digit_base(n, base);
	if (!(str = ft_calloc((i + 1), sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		sign = -1;
	}
	i--;
	if (n == 0)
		str[i] = '0';
	while (n != 0)
	{
		str[i] = base[(n % sizebase) * sign];
		n = n / sizebase;
		i--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	return (ft_itoa_base(n, BASE10));
}
