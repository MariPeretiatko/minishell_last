/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:00:21 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:00:21 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr_last;

	if (!lst)
		return (NULL);
	while (lst)
	{
		ptr_last = lst;
		lst = lst->next;
	}
	return (ptr_last);
}
