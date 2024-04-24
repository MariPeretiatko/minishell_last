/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:52:33 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 21:50:18 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_gnl(char *static_buff, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!static_buff)
	{
		free(static_buff);
		static_buff = (char *)malloc(1 * sizeof(char));
		static_buff[0] = '\0';
	}
	if (!static_buff || !buff)
		return (NULL);
	str = malloc(((ft_strlen(static_buff) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (static_buff)
		while (static_buff[++i] != '\0')
			str[i] = static_buff[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(static_buff) + ft_strlen(buff)] = '\0';
	free(static_buff);
	return (str);
}

