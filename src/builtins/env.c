/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:21:26 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:21:26 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	env(t_envp *env, char **args)
{
	if (ft_array_size(args) > 1)
	{
		ft_dprintf(2, "env: ‘%s‘: No such file or directory\n", args[1]);
		g_exit_status = 127;
		return ;
	}
	(void)args;
	while (env != NULL)
	{
		if (env->value)
			ft_dprintf(1, "%s=%s\n", env->name, env->value);
		env = env->next;
	}
	g_exit_status = 0;
}
