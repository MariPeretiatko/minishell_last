/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:59:29 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/22 21:59:30 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isblank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
