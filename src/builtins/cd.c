/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:28:14 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 21:55:25 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static bool	check_nb_args(char **args)
{
	if (args[1] == NULL)
	{
		g_exit_status = 1;
		ft_dprintf(2, "minishell> cd: too few arguments\n");
		return (false);
	}
	if (ft_array_size(args) > 2)
	{
		g_exit_status = 1;
		ft_dprintf(2, "minishell> cd: too many arguments\n");
		return (false);
	}
	return (true);
}

static void	set_oldpwd(char *oldpwd, t_envp *env)
{
	char	*tmp;
	t_envp	*pwdsearch;

	pwdsearch = envlst_search(env, "OLDPWD");
	if (pwdsearch)
		envlst_clearone(&env, pwdsearch);
	if (oldpwd)
	{
		tmp = ft_strjoin("OLDPWD=", oldpwd);
		free(oldpwd);
		envlstadd_back(&env, envlst_new(tmp));
		free(tmp);
	}
	else
		envlstadd_back(&env, envlst_new("OLDPWD"));
}

static void	set_error(char *args, char *old_pwd)
{
	g_exit_status = 1;
	free(old_pwd);
	ft_dprintf(2, "minishell> cd: ");
	perror(args);
}

void	cd(char **args, t_envp *env)
{
	char	pwd[4097];
	char	*oldpwd;
	t_envp	*pwdsearch;
	t_envp	*beforesearch;
	char	*tmp;

	if (!check_nb_args(args))
		return ;
	beforesearch = envlst_search(env, "PWD");
	oldpwd = NULL;
	if (beforesearch && beforesearch->value)
		oldpwd = ft_strdup(beforesearch->value);
	if (!chdir(args[1]))
	{
		getcwd(pwd, 4096);
		pwdsearch = envlst_search(env, "PWD");
		if (pwdsearch)
			envlst_clearone(&env, pwdsearch);
		tmp = ft_strjoin("PWD=", pwd);
		envlstadd_back(&env, envlst_new(tmp));
		free(tmp);
		set_oldpwd(oldpwd, env);
	}
	else
		set_error(args[1], oldpwd);
}
