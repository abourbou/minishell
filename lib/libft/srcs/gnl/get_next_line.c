/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:44:53 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:44:54 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_gnl.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

static t_gnl	*gnl_new(int fd, char *buffer)
{
	t_gnl *current;

	if (!(current = wrmalloc(sizeof(t_gnl))))
		return (0);
	if (!buffer)
	{
		if (!(current->buffer = ft_substr("", 0, 1)))
		{
			wrfree(current);
			return (0);
		}
	}
	else
		current->buffer = buffer;
	current->fd = fd;
	current->next = 0;
	return (current);
}

static t_gnl	*gnl_fct(t_gnl **lsts, int fd)
{
	t_gnl *current;

	if (!(current = (*lsts)))
		return (((*lsts) = gnl_new(fd, 0)));
	while (current)
	{
		if (current->fd == fd)
			break ;
		else if (!(current->next))
		{
			current->next = gnl_new(fd, 0);
			return (current->next);
		}
		(current) = (current)->next;
	}
	return (current);
}

static int		gnl_check(int fd, char **buffer)
{
	char	*str;
	int		read_size;
	int		state;
	char	*buffer_save;

	state = 1;
	if (!(str = wrmalloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	if ((read_size = read(fd, str, BUFFER_SIZE)) == -1)
	{
		wrfree(str);
		return (-1);
	}
	str[read_size] = '\0';
	(!ft_strlen(str)) ? state = 0 : 0;
	buffer_save = *buffer;
	if (!(*buffer = ft_strjoin(*buffer, str)))
	{
		wrfree(str);
		return (-1);
	}
	wrfree(buffer_save);
	wrfree(str);
	return (state);
}

static int		gnl_free_mail(t_gnl **buffer, t_gnl *current, int ret)
{
	t_gnl *tmp;
	t_gnl *tmp_prev;

	tmp_prev = 0;
	if ((tmp = (*buffer)) == current)
		(current->next) ? (*buffer) = current->next : 0;
	while (tmp)
	{
		if (tmp == current)
		{
			if (tmp_prev != 0)
				tmp_prev->next = tmp->next;
			if (current == (*buffer))
				(*buffer) = 0;
			wrfree(current);
			current = 0;
			break ;
		}
		tmp_prev = tmp;
		tmp = tmp->next;
	}
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static t_gnl	*buffer;
	t_gnl			*current;
	char			*n_buff;
	int				i;
	int				state_gnlcheck;

	n_buff = 0;
	if (!(fd >= 0 && BUFFER_SIZE > 0 && (current = gnl_fct(&buffer, fd))))
		return (-1);
	while (!(i = ft_strichr(current->buffer, '\n')))
		if ((state_gnlcheck = gnl_check(fd, &current->buffer)) == -1)
			return (-1);
		else if (state_gnlcheck == 0)
			break ;
	if ((i > 0) &&
		!(n_buff = ft_substr(current->buffer, i, ft_strlen(current->buffer))))
		return (-1);
	if (gnl_line(current->buffer, line, i) == -1)
		return (-1);
	wrfree(current->buffer);
	current->buffer = n_buff;
	return ((i == 0) ? gnl_free_mail(&buffer, current, 0) : 1);
}
