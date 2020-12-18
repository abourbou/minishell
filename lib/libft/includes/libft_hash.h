/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_hash.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgascon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:43:34 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/02 09:43:36 by dgascon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_HASH_H
# define LIBFT_HASH_H

# include <stddef.h>

typedef struct		s_hash
{
	char			*key;
	void			*value;
	struct s_hash	*head;
	struct s_hash	*before;
	struct s_hash	*next;
	void			(*show)(struct s_hash *, char *);
	struct s_hash	*(*last)(struct s_hash *);
	void			(*add_back)(struct s_hash **, struct s_hash *);
	void			(*add_front)(struct s_hash **, struct s_hash *);
	struct s_hash	*(*find)(struct s_hash *, char *);
	void			(*delkey)(struct s_hash **, char *);
	void			(*delhash)(struct s_hash **, struct s_hash *);
	void			(*hclear)(struct s_hash **);
	size_t			(*length)(struct s_hash *);
}					t_hash;

t_hash				*ft_hashnew(char *key, void *value);
void				ft_hashprint(t_hash *hash, char *s);
t_hash				*ft_hashlast(t_hash *hash);
void				ft_hashadd_back(t_hash **hash, t_hash *new);
void				ft_hashadd_front(t_hash **hash, t_hash *new);
t_hash				*ft_hashfind(t_hash *hash, char *key);
void				ft_hashdel_key(t_hash **hash, char *key);
void				ft_hashdel_hash(t_hash **hash, t_hash *delete);
void				ft_hashclear(t_hash **hash);
size_t				ft_hashlen(t_hash *hash);
t_hash				*ft_hashdup(t_hash *hash);
#endif
