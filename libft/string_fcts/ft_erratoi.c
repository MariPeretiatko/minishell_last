/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erratoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:02:31 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:03:54 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_erratoi(const char *nptr, int *err)
{
	long	nb;
	int		sig;

	sig = 1;
	nb = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sig *= -1;
		nptr++;
	}
	*err = 0;
	while (*nptr >= '0' && *nptr <= '9' && *err == 0)
	{
		nb = nb * 10 + (*nptr++ - '0') * sig;
		if (nb > INT_MAX)
			*err = 1;
		else if (nb < INT_MIN)
			*err = 2;
	}
	return (nb);
}
