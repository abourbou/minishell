/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_gnl.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:43:33 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:43:34 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_GNL_H
# define LIBFT_GNL_H

# include "libft_define.h"
# include "libft_string.h"
# include "libft_mem.h"
# include <unistd.h>

typedef struct	s_gnl
{
	int				fd;
	char			*buffer;
	struct s_gnl	*next;
}				t_gnl;

int				gnl_line(char *buffer, char **line, int index);
int				get_next_line(int fd, char **line);
#endif
