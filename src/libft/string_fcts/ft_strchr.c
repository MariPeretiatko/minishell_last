/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:04:44 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:04:45 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		cnt;
	char	*str;

	cnt = 0;
	str = (char *)s;
	while (c > 255)
		c -= 256;
	while (*str)
	{
		if (*str == c)
			return (str + cnt);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}
