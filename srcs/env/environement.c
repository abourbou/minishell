/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:21:14 by lrobino           #+#    #+#             */
/*   Updated: 2020/12/18 16:55:26 by lrobino          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "environement.h"

char	**g_envp = NULL;

int			load_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	if (!(g_envp = wrmalloc(sizeof(char *) * (i + 1))))
		return (1);
	g_envp[i] = NULL;
	while (--i + 1)
		g_envp[i] = ft_strdup(envp[i]);
	return (0);
}

char		*get_env(char *var)
{
	int		i;
	int		n;
	char	*buff;

	i = 0;
	if (!g_envp)
		return (NULL);
	while (g_envp && g_envp[i])
	{
		n = ft_strlchr(g_envp[i], '=');
		buff = ft_strndup(g_envp[i], n);
		if (ft_strcmp(buff, var) == 0)
		{
			wrfree(buff);
			return (g_envp[i] + n + 1);
		}
		wrfree(buff);
		i++;
	}
	return (NULL);
}

int			add_var(char *name, char *value)
{
	char	*concat;
	char	**new_envp;
	int		i;

	if (!value)
	{
		value = "";
		name = ft_strjoin("declare -x ", name);
	}
	concat = concat_var(name, value);
	i = 0;
	while (g_envp[i])
		i++;
	if (!(new_envp = wrmalloc(sizeof(char *) * (i + 2))))
		return (1);
	new_envp[i + 1] = NULL;
	new_envp[i] = concat;
	while (--i + 1)
		new_envp[i] = ft_strdup(g_envp[i]);
	i = 0;
	while (g_envp[i])
		wrfree(g_envp[i++]);
	wrfree(g_envp);
	g_envp = new_envp;
	return (0);
}

int			set_var(char *name, char *value)
{
	char	*buffer;
	int		i;

	if (get_env(name) == NULL)
		return (2);
	i = 0;
	if (!g_envp)
		return (1);
	while (g_envp && g_envp[i])
	{
		if (ft_strncmp(g_envp[i], name, ft_strlchr(g_envp[i], '=')) == 0)
		{
			buffer = concat_var(name, value);
			wrfree(g_envp[i]);
			g_envp[i] = ft_strdup(buffer);
		}
		i++;
	}
	return (0);
}

int			del_var(char *name)
{
	char	**new_envp;
	int		i;
	int		j;

	i = 0;
	while (g_envp[i])
		i++;
	if (!(new_envp = wrmalloc(sizeof(char *) * i)))
		return (1);
	new_envp[i - 1] = 0;
	j = --i - 1;
	while (i >= 0)
	{
		if (ft_strncmp(g_envp[i], name, ft_strlchr(g_envp[i], '=')) != 0)
		{
			new_envp[j] = ft_strdup(g_envp[i]);
			j--;
		}
		wrfree(g_envp[i]);
		i--;
	}
	wrfree(g_envp);
	g_envp = new_envp;
	return (0);
}
