/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:44:54 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:44:56 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_gnl.h"

int		gnl_line(char *buffer, char **line, int index)
{
	if (index > 0)
		(*line) = ft_substr(buffer, 0, index - 1);
	else
		(*line) = ft_substr(buffer, 0, ft_strlen(buffer));
	if (!(*line))
		return (-1);
	return (0);
}
