/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_areblank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:58:47 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 21:58:48 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_areblank(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
	{
		if (!(str[i] == ' ' || str[i] == '\t'))
			return (0);
		i++;
	}
	return (1);
}
