/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:31:42 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:31:42 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	is_pipe(char c)
{
	if (c == '|')
		return (true);
	return (false);
}

bool	is_redirection(char c)
{
	if (c == '<' || c == '>')
		return (true);
	return (false);
}

bool	is_space(char c)
{
	if (c == ' ')
		return (true);
	return (false);
}
