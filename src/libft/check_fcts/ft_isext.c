/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:59:41 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/26 14:06:09 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isext(char *file, char *ext)
{
	int	l_ext;
	int	l_file;

	if (!file || !ext)
		return (0);
	l_ext = ft_strlen(ext);
	l_file = ft_strlen(file);
	if (l_ext >= l_file)
		return (0);
	return (ft_strncmp(file + l_file - l_ext, ext, l_ext) == 0 && file[l_file
			- l_ext - 1] != '/');
}
