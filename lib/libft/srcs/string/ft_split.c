/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:45:42 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:45:43 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_mem.h"

void		ft_splitfree(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		wrfree(ptr[i]);
		i++;
	}
	wrfree(ptr);
}

static int	splitproc(char **ptr, char const *s, char c)
{
	int	i;
	int	row;
	int	start;
	int	end;

	i = -1;
	row = 0;
	start = -1;
	end = 1;
	while (s[++i])
	{
		if (s[i] != c)
		{
			(start == -1) ? start = i : 0;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				if (!(ptr[row++] = ft_substr(s, start, end)))
					return (EXIT_FAILURE);
				start = -1;
				end = 0;
			}
			end++;
		}
	}
	return (EXIT_SUCCESS);
}

char		**ft_split(char const *s, char c)
{
	char	**ptr;
	int		rows;
	int		i;

	if (!s)
		return (0);
	i = 0;
	rows = 0;
	while (s[i])
	{
		(s[i] != c && (s[i + 1] == c || s[i + 1] == '\0')) ? rows++ : 0;
		i++;
	}
	if (!(ptr = wrmalloc((rows + 1) * sizeof(char *))))
		return (0);
	ptr[rows] = 0;
	if (splitproc(ptr, s, c))
	{
		ft_splitfree(ptr);
		return (0);
	}
	return (ptr);
}
