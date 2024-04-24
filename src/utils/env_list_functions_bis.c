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

t_envp	*envlst_search(t_envp *env, char *searched)
{
	t_envp	*head;

	head = env;
	while (head != NULL)
	{
		if (!ft_strcmp(head->name, searched))
			return (head);
		head = head->next;
	}
	return (NULL);
}

int	envlst_size(t_envp *env)
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
	free(node->name);
	free(node->value);
	free(node);
}

void	envlst_clearone(t_envp **root, t_envp *todel)
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

void	envlst_clear(t_envp **env)
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
		free(tmp->name);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
	*env = NULL;
}
