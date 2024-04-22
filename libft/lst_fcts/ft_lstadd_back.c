/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:59:57 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 21:59:58 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_backup;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_backup = *lst;
	while ((*lst)->next)
		*(lst) = (*lst)->next;
	(*lst)->next = new;
	*lst = lst_backup;
}
