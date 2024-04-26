/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:30:37 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/26 14:11:31 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*apply_expansion(char *tok, t_envp *env);
static char	*replace_var(char *token, int *i, t_envp *env);
char		*replace_var_wrongname(char *tok, int *i);
char		*replace_var_exitcode(char *tok, int *i);

void	expand_doll(char **cmd, int *tokens, t_envp *env)
{
	int	i;
	int	j;

	i = 0;
	while (cmd[i])
	{
		if (ft_strchr(cmd[i], '$'))
			cmd[i] = apply_expansion(cmd[i], env);
		j = 0;
		while (cmd[i][j])
			if (cmd[i][j] != ' ' || !(cmd[i][j] >= 9 && cmd[i][j] <= 13))
				break ;
		if (!cmd[i][j])
			tokens[i] = EMPTY;
		i++;
	}
}

static char	*apply_expansion_bis(char *tok, int *i, int state, t_envp *env);

static char	*apply_expansion(char *tok, t_envp *env)
{
	int	i;
	int	state;

	i = 0;
	state = 0;
	while (i != -1 && tok[i])
	{
		chg_qte_state(&state, tok[i]);
		if (tok[i] == '$' && state != 1 && tok[i + 1] == '?')
		{
			tok = replace_var_exitcode(tok, &i);
			if (tok[i] == '$' || tok[i] == '"' || tok[i] == '\'')
				continue ;
			else if (tok[i] == 0)
				break ;
		}
		else if (tok[i] == '$' && state != 1 && (tok[i + 1] == ' '
				|| tok[i + 1] == '\'' || tok[i + 1] == '"'
				|| tok[i + 1] == '$' || !tok[i + 1]))
			;
		else
			tok = apply_expansion_bis(tok, &i, state, env);
		i++;
	}
	return (tok);
}

static char	*apply_expansion_bis(char *tok, int *i, int state, t_envp *env)
{
	if ((tok[*i] == '$' && state != 1 && ft_isalpha(tok[*i + 1]))
		|| (tok[*i] == '$' && state != 1 && tok[*i + 1] == '_'))
	{
		tok = replace_var(tok, i, env);
		if (tok[*i] == '$' || tok[*i] == '"' || tok[*i] == '\'')
			*i -= 1;
		else if (tok[*i] == 0)
			*i = -2;
	}
	else if (tok[*i] == '$' && state != 1)
	{
		tok = replace_var_wrongname(tok, i);
		if (tok[*i] == '$' || tok[*i] == '"' || tok[*i] == '\'')
			*i -= 1;
		else if (tok[*i] == 0)
			*i = -2;
	}
	return (tok);
}

static void	ft_free_this(char *tmp, char *tmp2, char *name);

static char	*replace_var(char *token, int *i, t_envp *env)
{
	t_envp	*search;
	char	*tmp;
	char	*tmp2;
	char	*name;
	int		end_var_name;

	end_var_name = (*i) + 1;
	while ((token[end_var_name] && ft_isalnum(token[end_var_name]))
		|| (token[end_var_name] && token[end_var_name] == '_'))
		end_var_name++;
	name = ft_substr(token, (*i) + 1, end_var_name - (*i) - 1);
	search = envlst_search(env, name);
	tmp = ft_substr(token, 0, *i);
	if (search && search->value)
		tmp2 = ft_strjoin(tmp, search->value);
	else
		tmp2 = ft_strjoin(tmp, "");
	free(tmp);
	tmp = ft_substr(token, end_var_name, 1000);
	free(token);
	token = ft_strjoin(tmp2, tmp);
	*i = ft_strlen(tmp2);
	ft_free_this(tmp, tmp2, name);
	return (token);
}

static void	ft_free_this(char *tmp, char *tmp2, char *name)
{
	free(tmp);
	free(tmp2);
	free(name);
}
