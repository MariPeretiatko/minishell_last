/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:07:50 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:07:50 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	cnt;

	cnt = ft_putstr_fd(s, fd);
	if (s)
	{
		write(fd, "\n", 1);
		return (cnt + 1);
	}
	return (cnt);
}
