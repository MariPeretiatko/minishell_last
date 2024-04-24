/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:00:45 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:00:46 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	cnt;
	char	*str;

	str = (char *)s;
	cnt = 0;
	while (cnt < n)
	{
		str[cnt] = 0;
		cnt++;
	}
	s = (void *)str;
}
