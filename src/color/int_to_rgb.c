/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 07:59:14 by tyago-ri          #+#    #+#             */
/*   Updated: 2023/04/01 07:59:15 by tyago-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	intorgb(int *r, int *g, int *b, unsigned int *color)
{
	*r = (*color >> 16) & 0xFF;
	*g = (*color >> 8) & 0xFF;
	*b = *color & 0xFF;
}

void	itorgb(int color, t_rgb *result)
{
	result->r = (color >> 16) & 0xFF;
	result->g = (color >> 8) & 0xFF;
	result->b = color & 0xFF;
}
