/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:00:06 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:00:07 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_backup;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		lst_backup = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_backup;
	}
}
