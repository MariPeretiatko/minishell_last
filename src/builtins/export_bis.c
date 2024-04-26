/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:22:04 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/26 14:08:10 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*get_var_name(const char *args);

void	export_concatenate(char *args, t_envp **envp, char *var_old_value)
{
	char	*name;
	t_envp	*search;

	name = get_var_name(args);
	search = envlst_search(*envp, name);
	free(name);
	if (search && search->value)
	{
		var_old_value = ft_strdup(search->value);
		free(search->value);
		search->value = ft_strjoin(var_old_value, ft_strchr(args, '=') + 1);
		free(var_old_value);
	}
	else if (search)
	{
		envlst_clearone(envp, search);
		envlstadd_back(envp, envlst_new(args));
	}
	else
		envlstadd_back(envp, envlst_new(args));
}

void	export_assign(char *args, t_envp **envp)
{
	char	*name;
	t_envp	*search;

	name = get_var_name(args);
	search = envlst_search(*envp, name);
	free(name);
	if (search)
	{
		free(search->value);
		search->value = ft_strdup(ft_strchr(args, '=') + 1);
	}
	else
		envlstadd_back(envp, envlst_new(args));
}

void	export_create_var(char *args, t_envp **envp)
{
	char	*name;
	t_envp	*search;

	name = get_var_name(args);
	search = envlst_search(*envp, name);
	free(name);
	if (!search)
		envlstadd_back(envp, (envlst_new(args)));
}

static char	*get_var_name(const char *args)
{
	int		i;
	char	*name;

	i = 0;
	while (args[i])
	{
		if (args[i] == '+' || args[i] == '=')
			break ;
		i++;
	}
	name = malloc(sizeof(char) * i + 1);
	if (!name)
		return (NULL);
	ft_strlcpy(name, args, i + 1);
	return (name);
}
