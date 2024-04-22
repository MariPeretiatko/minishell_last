/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:30:52 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:30:53 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	check_for_double_operators(int *cmd_type)
{
	int	i;

	i = 0;
	while (cmd_type[i])
	{
		if (cmd_type[i] == PIPE && cmd_type[i + 1] == PIPE)
		{
			ft_dprintf(2,
				"minishell> syntax error near unexpected token `|'\n");
			return (false);
		}
		i++;
	}
	return (true);
}
