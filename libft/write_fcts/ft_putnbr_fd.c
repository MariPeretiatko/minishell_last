/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:08:08 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:08:08 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr_fd(long n, int cnt, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		cnt++;
		n *= -1;
	}
	if (n >= 10)
	{
		cnt = ft_putnbr_fd(n / 10, cnt, fd);
		cnt = ft_putnbr_fd(n % 10, cnt, fd);
	}
	else
	{
		n += 48;
		write(fd, &n, 1);
		cnt++;
	}
	return (cnt);
}
