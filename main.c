/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:31:54 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 23:48:05 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			g_exit_status;

static void	check_args(int argc, char *argv[])
{
	(void)argv;
	if (argc > 1)
	{
		ft_dprintf(2, "minishell> too many args\n");
		exit(127);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd_input;
	t_envp	*env;

	check_args(argc, argv);
	g_exit_status = 0;
	env = get_env_variables(envp);
	handle_sig(SIG_DEFAULT);
	// get_prompt(env);
	cmd_input = readline("minishell> ");
	while (cmd_input)
	{
		if (*cmd_input)
			add_history(cmd_input);
		if (parse_line(cmd_input))
			main_execute(cmd_input, &env);
		// get_prompt(env);
		cmd_input = readline("minishell> ");
	}
	ft_envlst_clear(&env);
	rl_clear_history();
	ft_dprintf(1, "exit\n");
	return (g_exit_status);
}
