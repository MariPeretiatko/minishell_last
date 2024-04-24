/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:00:16 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:00:17 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_backup;

	if (!lst || !f)
		return ;
	lst_backup = lst;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
	lst = lst_backup;
}
