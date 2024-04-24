/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:22:48 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:22:48 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static bool	parse_env_var_name(const char *args, int *exit_code)
{
	int	i;

	if (!ft_isalpha(args[0]) && args[0] != '_')
	{
		*exit_code = 1;
		ft_dprintf(2, "minishell> unset: `%s': not a valid identifier\n", args);
		return (false);
	}
	i = 0;
	while (args[i])
	{
		if (!ft_isalnum(args[i]) && args[i] != '_')
		{
			*exit_code = 1;
			ft_dprintf(2, "minishell> unset: `%s': not a valid identifier\n",
				args);
			return (false);
		}
		i++;
	}
	return (true);
}

void	unset(t_envp **env, char **args)
{
	int		i;
	int		exit_code;
	t_envp	*to_delete;

	i = 1;
	exit_code = 0;
	while (args[i])
	{
		if (parse_env_var_name(args[i], &exit_code))
		{
			g_exit_status = 0;
			to_delete = envlst_search(*env, args[i]);
			if (to_delete)
			{
				envlst_clearone(env, to_delete);
			}
		}
		i++;
	}
	if (exit_code == 1)
		g_exit_status = 1;
}
