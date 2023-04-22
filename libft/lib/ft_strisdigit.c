/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:31:41 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/22 13:49:02 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strisdigit(char *str)
{
	int	inx;

	inx = 0;
	while (str[inx])
	{
		if (!ft_isdigit(str[inx]))
			return (-1);
		inx++;
	}
	return (0);
}
