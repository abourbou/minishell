/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlecaill <nlecaill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 09:39:14 by dgascon           #+#    #+#             */
/*   Updated: 2020/12/18 15:57:29 by nlecaill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include "libft_string.h"
#include "libft_printf.h"
#include "syntax_error.h"
#include <signal.h>
#include <stdio.h>
#include "libft_mem.h"
#include "libft_number.h"
#include "exec.h"
#include "signal_manager.h"

/*
 ** Prepare une nouvelle ligne de commande
 ** Return [int] Status de reussite
*/

static int	clear_new_cmd(t_term *term, t_block *copy, int sig, int ret_handle)
{
	if (ft_strlen(copy->str_cmd) != 0)
	{
		if (sig != SIGINT && ret_handle != NEW_COMMAND)
		{
			ft_hashdel_key(&term->historic, "tmp");
			ft_histo_add(term, "h", copy);
		}
		term->current_historic = NULL;
		ft_hashclear(&(term->list_blocks));
		if (!(term->list_blocks = ft_hashnew("block_1", ft_blocknew())))
			return (EXIT_FAILURE);
		term->current_block = term->list_blocks;
		term->original_line = term->ndx_line;
	}
	else
	{
		term->original_line += 1;
		term->cursor_pos = 0;
	}
	return (EXIT_SUCCESS);
}

/*
 ** Instancie une nouvelle ligne de commande split de la commande principal
 ** Return [int] Status de reussite
*/

static int	new_cmd_2(t_term *term, t_block *copy, int sig, int ret_handle)
{
	if (tcsetattr(0, 0, &term->termios) == -1)
		return (EXIT_FAILURE);
	if (g_interrupt && g_passed && g_exit_status != 0)
		ft_printf("\n");
	ft_printf("\033[%dm$ \033[0m", term->colors[term->color]);
	(term->color == NB_COLORS - 1 ? term->color = 0 : term->color++);
	get_pos();
	if (clear_new_cmd(term, copy, sig, ret_handle))
		return (EXIT_FAILURE);
	if (term->cursor_pos == 0)
		term->cursor_pos = PROMPT_SIZE;
	fflush(stdout);
	clear_eos(term, term->ndx_line);
	g_passed = 0;
	return (EXIT_SUCCESS);
}

/*
 ** Instancie une nouvelle ligne de commande
 ** Return [int] Status de reussite
*/

int			new_cmd(t_term *term, int sig, int ret_handle)
{
	t_block *copy;

	if (!(copy = ft_blockhashdup(term->list_blocks)))
		return (EXIT_FAILURE);
	if (put_cursor(0, term->original_line +
		((copy->size + PROMPT_SIZE) / term->nb_cols)) != 0)
		return (EXIT_FAILURE);
	(term->ndx_line < term->nb_lines) ? ft_printf("\n") : 0;
	if (tcsetattr(0, 0, &(*getterm())->termios_backup) == -1)
		return (EXIT_FAILURE);
	if (ret_handle == TO_EXECUTE)
		exec_cmd(term->str_ccmd);
	else if (ret_handle == NCMD_SYNTAX_ERROR)
	{
		ft_printf("minishell: \033[%dmsyntax error\n\033[0m", ERROR_COLOR);
		g_exit_status = 2;
	}
	if (new_cmd_2(term, copy, sig, ret_handle))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
 ** Gere le \n dans le block. Ajoute un block dans la structure.
 ** Return [int] Status de reussite
*/

int			ft_newline(t_term *term)
{
	t_hash	*hash;
	t_block *tmp;

	ft_hashdel_key(&term->historic, "tmp");
	term->current_historic = 0;
	tmp = 0;
	if ((tmp = ft_blockdup(ft_blockstrnew(term->str_ccmd))))
	{
		if (ft_histo_add(term, "tmp", tmp))
			return (EXIT_FAILURE);
		term->original_line++;
	}
	if (!(hash = ft_hashnew(ft_strjoin("block_",
					ft_itoa(ft_hashlen(term->list_blocks))), ft_blocknew())))
		return (EXIT_FAILURE);
	ft_hashadd_back(&(term->list_blocks), hash);
	term->ndx_line++;
	term->cursor_pos = PROMPT_SIZE;
	ft_printf("\033[%dm\n> \033[0m", term->colors[term->color]);
	(term->color == NB_COLORS - 1 ? term->color = 0 : term->color++);
	term->current_block = hash;
	term->ndx_cursor = 0;
	return (PROCESS_SUCCESS);
}
