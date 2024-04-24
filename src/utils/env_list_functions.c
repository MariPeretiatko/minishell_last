/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:31:37 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:31:38 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_envp	*ft_envlst_last(t_envp *env)
{
	t_envp	*last;

	last = env;
	if (env == NULL)
		return (NULL);
	while (env != NULL)
	{
		last = env;
		env = env->next;
	}
	return (last);
}

void	envlstadd_back(t_envp **env, t_envp *new_env)
{
	t_envp	*last;

	if (!new_env || !env)
		return ;
	if (*env == NULL)
		*env = new_env;
	else
	{
		last = ft_envlst_last(*env);
		last->next = new_env;
		new_env->prev = last;
	}
}

static void	create_and_assign(char *str, t_envp **new)
{
	int	i;
	int	var_value_size;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			break ;
	}
	if (str[i - 1] == '+')
	{
		(*new)->name = ft_calloc(sizeof(char), i);
		ft_strlcpy((*new)->name, str, i);
	}
	else
	{
		(*new)->name = ft_calloc(sizeof(char), i + 1);
		ft_strlcpy((*new)->name, str, i + 1);
	}
	var_value_size = ft_strlen(str) - ft_strlen((*new)->name);
	(*new)->value = ft_calloc(sizeof(char), var_value_size);
	ft_strlcpy((*new)->value, str + i + 1, var_value_size);
}

t_envp	*envlst_new(char *str)
{
	t_envp	*new;

	new = ft_calloc(sizeof(t_envp), 1);
	if (!new)
		return (0);
	if (!ft_strchr(str, '='))
	{
		new->name = ft_strdup(str);
		if (!new->name)
			return (0);
		new->value = NULL;
	}
	else
		create_and_assign(str, &new);
	return (new);
}

t_envp	*get_env_variables(char **envp)
{
	int		i;
	t_envp	*root;
	t_envp	*new;

	i = 0;
	root = NULL;
	while (envp[i])
	{
		new = envlst_new(envp[i]);
		envlstadd_back(&root, new);
		i++;
	}
	return (root);
}
