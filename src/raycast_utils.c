/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:43:08 by glemoine          #+#    #+#             */
/*   Updated: 2023/03/06 14:28:12 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	get_len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	wich_x(t_side *wall, int width)
{
	double	x;

	if (wall->face == 0)
		x = wall->x - trunc(wall->x);
	else
		x = wall->y - trunc(wall->y);
	if ((wall->face == 0 && wall->offset >= 1) || \
		(wall->face == 1 && wall->offset <= 0))
		x = 1 - x;
	return (trunc(x * width));
}

int	get_texture(t_side *wall, double rot)
{
	if (sin(rot * M_PI / 180) > 0 && wall->face == 0)
		return (0);
	if (sin(rot * M_PI / 180) < 0 && wall->face == 0)
		return (1);
	if (cos(rot * M_PI / 180) < 0 && wall->face == 1)
		return (2);
	if (cos(rot * M_PI / 180) > 0 && wall->face == 1)
		return (3);
	return (0);
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	pixel_get(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bit_per_pixel / 8));
	return (*(unsigned int *)dst);
}
