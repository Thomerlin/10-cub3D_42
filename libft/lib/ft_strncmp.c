/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:16:57 by llopes-n          #+#    #+#             */
/*   Updated: 2023/03/05 22:32:05 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	int	inx;

	inx = 0;
	if (!len)
		return (0);
	while (s1[inx] && s2[inx] && --len)
	{
		if (s1[inx] != s2[inx])
			break ;
		inx++;
	}
	return ((*(unsigned char *)s1 - *(unsigned char *)s2));
}
