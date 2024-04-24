/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_areascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:58:39 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 21:58:42 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_areascii(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
	{
		if (!(str[i] >= 0 && str[i] <= 127))
			return (0);
		i++;
	}
	return (1);
}