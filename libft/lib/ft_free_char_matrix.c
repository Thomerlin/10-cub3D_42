/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-n <llopes-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:35:56 by llopes-n          #+#    #+#             */
/*   Updated: 2023/04/04 23:30:32 by llopes-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_free_char_matrix(char ***matrix)
{
	int	inx;

	inx = 0;
	while (*(*matrix + inx) != NULL)
	{
		free(*(*matrix + inx));
		*(*matrix + inx) = NULL;
		inx++;
	}
	free(*matrix);
	*matrix = NULL;
}
