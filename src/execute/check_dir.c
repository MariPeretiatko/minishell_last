/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:25:24 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:25:32 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	check_dir(char *cmd)
{
	DIR	*dirp;

	if (!cmd)
		return (false);
	dirp = opendir(cmd);
	if (dirp)
	{
		ft_dprintf(2, "minishell> %s: Is a directory\n", cmd);
		g_exit_status = 126;
		closedir(dirp);
		return (true);
	}
	return (false);
}
