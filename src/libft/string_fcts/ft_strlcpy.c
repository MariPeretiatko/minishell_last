/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:05:40 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:05:41 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	cnt;

	cnt = 0;
	while (cnt + 1 < (int)size && src[cnt])
	{
		dst[cnt] = src[cnt];
		cnt++;
	}
	if (size)
		dst[cnt] = 0;
	return (ft_strlen(src));
}
