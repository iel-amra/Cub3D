/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:44:08 by iel-amra          #+#    #+#             */
/*   Updated: 2023/03/06 14:29:48 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cube3d.h"

static void	load_face(t_side	*side, double rot, t_program *prog)
{
	double	adj;
	double	opp;

	side->offset += (cos(rot * M_PI / 180) > 0) * 2 - 1;
	side->x = trunc(prog->player.x + side->offset);
	adj = side->x - prog->player.x;
	opp = tan(rot * M_PI / 180) * adj;
	side->dist = adj / cos(rot * M_PI / 180);
	side->y = prog->player.y - opp;
	side->is_wall = 0;
	if (side->y < 0 || (int)side->x <= 0 || (int)side->y >= get_len_tab(\
	prog->map) || (int)side->x >= (int)ft_strlen(prog->map[(int)side->y]))
		side->is_wall = 1;
	else if (prog->map[(int) side->y][(int) side->x - 1] == CHAR_WALL \
			|| prog->map[(int) side->y][(int) side->x] == CHAR_WALL)
		side->is_wall = 1;
}

static void	load(t_side	*side, double rot, t_program *prog)
{
	double	adj;
	double	opp;

	if (side->face == 1)
		return (load_face(side, rot, prog));
	side->offset += (sin(rot * M_PI / 180) < 0) * 2 - 1;
	side->y = trunc(prog->player.y + side->offset);
	opp = prog->player.y - side->y;
	adj = opp / tan(rot * M_PI / 180);
	side->dist = opp / (sin(rot * M_PI / 180));
	side->x = prog->player.x + adj;
	side->is_wall = 0;
	if ((int)side->y <= 0 || side->x < 0 || (int)side->y >= get_len_tab(\
	prog->map) || (int)side->x >= (int)ft_strlen(prog->map[(int)side->y]) \
		|| (int)side->x >= (int)ft_strlen(prog->map[(int)side->y - 1]))
		side->is_wall = 1;
	else if (prog->map[(int) side->y - 1][(int) side->x] == CHAR_WALL
			|| prog->map[(int) side->y][(int) side->x] == CHAR_WALL)
		side->is_wall = 1;
}

static t_side	get_wall(t_program *prog, double rot)
{
	t_side	v_side;
	t_side	h_side;
	t_side	*min_side;

	h_side.offset = 0;
	v_side.offset = 0;
	if (sin(rot * M_PI / 180) > 0)
		h_side.offset = 1;
	if (cos(rot * M_PI / 180) < 0)
		v_side.offset = 1;
	h_side.face = 0;
	v_side.face = 1;
	load(&v_side, rot, prog);
	load(&h_side, rot, prog);
	min_side = &h_side;
	if (v_side.dist < h_side.dist)
		min_side = &v_side;
	while (!min_side->is_wall)
	{
		load(min_side, rot, prog);
		min_side = &h_side;
		if (v_side.dist < h_side.dist)
			min_side = &v_side;
	}
	return (*min_side);
}

static void	single_ray(t_program *prog, t_img *img, int x, double rot)
{
	int		i;
	t_side	wall;
	int		ln_ht;
	t_img	spr;
	int		start;

	wall = get_wall(prog, rot);
	spr = prog->sprites[get_texture(&wall, rot)];
	ln_ht = 2 * (img->height / (wall.dist * \
		cos((rot - prog->player.rot) / 180 * M_PI)));
	start = (img->height - ln_ht) / 2;
	i = -1;
	while (++i < img->height)
	{
		if (i < start)
			pixel_put(img, x, i, prog->color_ceilling);
		else if (i < start + ln_ht)
			pixel_put(img, x, i, pixel_get(&spr, wich_x(&wall, spr.width), \
			trunc((i + 0.5 - start) / ln_ht * spr.height)));
		else
			pixel_put(img, x, i, prog->color_floor);
	}
}

void	raycasting(t_program *prog, t_img *image)
{
	int		i;
	double	angle;

	i = 0;
	while (i < image->width)
	{
		angle = atan((image->width / 2 - i + 0.5) / image->width / 2) \
		/ M_PI * 180 + prog->player.rot;
		single_ray(prog, image, i, angle);
		i++;
	}
}
