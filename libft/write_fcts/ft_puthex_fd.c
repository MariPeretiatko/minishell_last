/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:08:00 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:08:01 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_puthex_fd(unsigned long n, int lowcase, int cnt, int fd)
{
	char	to_wrt;
	char	*base;

	base = "0123456789abcdef";
	if (!lowcase)
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		cnt += ft_puthex_fd(n / 16, lowcase, 0, fd);
		cnt += ft_puthex_fd(n % 16, lowcase, 0, fd);
	}
	else
	{
		to_wrt = base[n];
		write(fd, &to_wrt, 1);
		cnt++;
	}
	return (cnt);
}
