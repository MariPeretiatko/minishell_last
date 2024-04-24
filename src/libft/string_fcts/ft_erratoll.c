/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erratoll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:02:36 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 22:04:19 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int64_t	ft_erratoll(const char *nptr, int *err)
{
	int64_t	nb;
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
		if (nb < 0 && sig == 1)
			*err = 1;
		else if (nb > 0 && sig == -1)
			*err = 2;
	}
	return (nb);
}
