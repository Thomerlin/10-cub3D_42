/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:28:07 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/01 17:08:32 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *string, int c)
{
	while (*string)
	{
		if (*string == (unsigned char)c)
			return ((char *)string);
		string++;
	}
	if (*string == (unsigned char)c)
		return (NULL);
	return (NULL);
}
