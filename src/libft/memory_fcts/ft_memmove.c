/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:01:41 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:01:41 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_cpy;
	char	*src_cpy;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	dest_cpy = (char *)dest;
	src_cpy = (char *)src;
	if (src < dest)
	{
		while (n--)
			*(dest_cpy + n) = *(src_cpy + n);
		dest = (void *)dest_cpy;
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
