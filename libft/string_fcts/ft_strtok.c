/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:06:46 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:06:47 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*buf = NULL;

	if (str)
		buf = str;
	if (!buf || !delim)
		return (NULL);
	while (*buf && ft_strchr(delim, *buf))
		buf++;
	str = buf;
	if (!*str)
		return (NULL);
	while (*buf && !ft_strchr(delim, *buf))
		buf++;
	if (*buf)
		*buf++ = 0;
	if (!*buf)
		buf = NULL;
	return (str);
}
