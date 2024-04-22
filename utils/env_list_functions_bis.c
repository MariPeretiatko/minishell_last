/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_functions_bis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:31:32 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:31:32 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_envp	*ft_envlst_search(t_envp *env, char *searched)
{
	t_envp	*head;

	head = env;
	while (head != NULL)
	{
		if (!ft_strcmp(head->var_name, searched))
			return (head);
		head = head->next;
	}
	return (NULL);
}

int	ft_envlst_size(t_envp *env)
{
	int	i;

	i = 0;
	while (env != NULL)
	{
		env = env->next;
		i++;
	}
	return (i);
}

static void	ft_delnode(t_envp *node)
{
	if (!node)
		return ;
	free(node->var_name);
	free(node->var_value);
	free(node);
}

void	ft_envlst_clearone(t_envp **root, t_envp *todel)
{
	if (!root || !*root || !todel)
		return ;
	if (*root == todel && !(*root)->next)
	{
		ft_delnode(todel);
		*root = NULL;
		return ;
	}
	else if (*root == todel)
	{
		*root = (*root)->next;
		(*root)->prev = NULL;
		ft_delnode(todel);
		return ;
	}
	todel->prev->next = todel->next;
	if (todel->next)
		todel->next->prev = todel->prev;
	ft_delnode(todel);
}

void	ft_envlst_clear(t_envp **env)
{
	t_envp	*tmp;
	t_envp	*current;

	if (!*env)
		return ;
	current = *env;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp->var_name);
		if (tmp->var_value)
			free(tmp->var_value);
		free(tmp);
	}
	*env = NULL;
}
