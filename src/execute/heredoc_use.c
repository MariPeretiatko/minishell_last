/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_use.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:29:54 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:29:54 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	idx_last_hd(int *toks);
static int	get_hd_fd(int hd_arr[16][2], int cmd_nb);

int	check_heredoc_use(int fd, t_execute *exec, int cmd_nb)
{
	int	i;

	i = idx_last_hd(exec->toks[cmd_nb]);
	if (i == -1)
		return (fd);
	while (exec->cmds[cmd_nb][i])
	{
		if (exec->toks[cmd_nb][i] == R_IN_FILE)
		{
			sec_close(get_hd_fd(exec->heredoc_fd, cmd_nb));
			return (fd);
		}
		i++;
	}
	i = get_hd_fd(exec->heredoc_fd, cmd_nb);
	if (i == -1)
		return (fd);
	else
	{
		sec_close(fd);
		return (i);
	}
}

static int	idx_last_hd(int *toks)
{
	int	i;
	int	hd;

	i = 0;
	hd = -1;
	while (toks[i])
	{
		if (toks[i] == HEREDOC_LIM)
			hd = i;
		i++;
	}
	return (hd);
}

static int	get_hd_fd(int hd_arr[16][2], int cmd_nb)
{
	int	i;

	i = 0;
	while (i < 16 && hd_arr[i][0] != -1)
	{
		if (hd_arr[i][0] == cmd_nb)
			return (hd_arr[i][1]);
		i++;
	}
	return (-1);
}

bool	stdin_state(void)
{
	int	test;

	test = dup(0);
	if (test == -1)
		return (false);
	close(test);
	return (true);
}

void	close_heredocs(int hd_arr[16][2])
{
	int	i;

	i = 0;
	while (i < 15)
	{
		if (hd_arr[i][0] != -1)
			sec_close(hd_arr[i][1]);
		i++;
	}
}
