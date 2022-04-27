/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:05:40 by lrobino           #+#    #+#             */
/*   Updated: 2020/12/18 15:57:43 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

/*
**      REPLACE_SECTION
**      str: String to replace section
**      index: Index of the starting point of the section to replace
**      replace: String to put in str
**      pattern_len: length of the replaced string in str that will be
**		deleted, 0 means insertion mode
**
**      RETURNS: the str with the inserted string replace at position i, with
**		pattern_len characters remplaced after str + i
*/

char	*replace_section
	(char *str, int index, const char *replace, size_t pattern_len)
{
	int		j;
	size_t	out_len;
	size_t	replace_len;
	char	*out;

	replace_len = ft_strlen(replace);
	out_len = ft_strlen(str) - pattern_len + replace_len;
	if (!(out = (char *)wrmalloc(sizeof(char) * (out_len + 1))))
		return (NULL);
	j = -1;
	while (++j < index)
		out[j] = str[j];
	while ((j - index) < (int)replace_len)
	{
		out[j] = replace[j - index];
		j++;
	}
	while (str[index + pattern_len])
		out[j++] = str[index++ + pattern_len];
	out[out_len] = '\0';
	return (out);
}

/*
**      GET_QUOTES
**
**      Description:
**      Little quote handler, call it everytime you loop on your string
**		and give it the current pointer on that string.
**
**      Returns:
**      QUOTE_DOUBLE: the current pointer is bounded by double quotes
**      QUOTE_SINGLE: the current pointer is bounded by single quotes
**      QUOTE_NONE: the current pointer isn't bounded by any quotes
*/

char	get_quotes(char *current)
{
	static char current_quote = QUOTE_NONE;
	static int	last_is_bslash = 0;

	if (*current == '\\' && current_quote != QUOTE_SINGLE)
		last_is_bslash = 1;
	if (ft_strcmp(QUOTE_RESET, current) == 0)
		return (current_quote = QUOTE_NONE);
	if (current_quote == QUOTE_NONE && !last_is_bslash
		&& (*current == QUOTE_SINGLE || *current == QUOTE_DOUBLE))
		current_quote = *current;
	else if (*current == current_quote && !last_is_bslash)
		current_quote = QUOTE_NONE;
	if (last_is_bslash && *current != '\\')
		last_is_bslash = 0;
	return (current_quote);
}
