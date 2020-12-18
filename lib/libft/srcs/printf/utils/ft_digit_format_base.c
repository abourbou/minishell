/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_format_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:16:32 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 10:16:33 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int	ft_digit_format_base(long num, char *base)
{
	int i;
	int	j;
	int moins;
	int sbase;

	moins = 0;
	j = 0;
	sbase = ft_strlen(base);
	i = 0;
	if (num < 0)
		moins = 1;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / sbase;
		if (i % 3 == 1 && num / sbase != 0 && i > 0)
			j++;
		i++;
	}
	return (i + j + moins);
}
