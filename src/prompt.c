/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:31:59 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/26 14:19:18 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// static void	prompt_get_user(t_envp *env);
// static void	prompt_get_path(t_envp *env);
// static void	prompt_get_exitc(int exitc);

// void	get_prompt(t_envp *env)
// {
// 	prompt_get_user(env);
// 	prompt_get_path(env);
// 	prompt_get_exitc(g_exit_status);
// 	printf("\n");
// }

// static void	prompt_get_exitc(int exit_stat)
// {
// 	if (exit_stat == 0)
// 		return ;
// 	printf(RED "%d " NC, exit_stat);
// }

// static void	prompt_get_path(t_envp *env)
// {
// 	t_envp	*home;
// 	char	*pwd;
// 	char	*tmp;
// 	int		home_length;

// 	pwd = getcwd(NULL, 4096);
// 	home = envlst_search(env, "HOME");
// 	if (home && ft_strlen(home->value) > 0)
// 	{
// 		home_length = ft_strlen(home->value);
// 		if (ft_strncmp(pwd, home->value, home_length) == 0)
// 		{
// 			tmp = ft_substr(pwd, home_length, ft_strlen(pwd) - home_length);
// 			printf(GREEN "~%s " NC, tmp);
// 			free(pwd);
// 			free(tmp);
// 			return ;
// 		}
// 	}
// 	printf(GREEN "[%s]" NC, pwd);
// 	free(pwd);
// }

// static void	prompt_get_user(t_envp *env)
// {
// 	t_envp	*env_tmp;
// 	char	*tmp;

// 	env_tmp = envlst_search(env, "USER");
// 	if (!env_tmp)
// 	{
// 		printf(CYAN ":" NC);
// 		return ;
// 	}
// 	if (env_tmp->value)
// 		printf(CYAN "%s@" NC, env_tmp->value);
// 	env_tmp = envlst_search(env, "SESSION_MANAGER");
// 	if (!env_tmp)
// 		return ;
// 	tmp = ft_substr(env_tmp->value, 6, 3);
// 	if (tmp)
// 		printf(CYAN "%s:", tmp);
// 	free(tmp);
// }
