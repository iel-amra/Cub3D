/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:28:58 by glemoine          #+#    #+#             */
/*   Updated: 2023/03/06 13:23:46 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	onkeydown(int keycode, t_program *prog)
{
	if (keycode == KEY_ESC)
		cleanandexit(prog);
	else if (keycode == KEY_W)
		prog->move_lon += 1;
	else if (keycode == KEY_S)
		prog->move_lon -= 1;
	else if (keycode == KEY_A)
		prog->move_lat -= 1;
	else if (keycode == KEY_D)
		prog->move_lat += 1;
	else if (keycode == KEY_LEFT)
		prog->move_rot += 1;
	else if (keycode == KEY_RIGHT)
		prog->move_rot -= 1;
	return (0);
}

int	onkeyup(int keycode, t_program *prog)
{
	if (keycode == KEY_ESC)
		cleanandexit(prog);
	else if (keycode == KEY_W)
		prog->move_lon -= 1;
	else if (keycode == KEY_S)
		prog->move_lon += 1;
	else if (keycode == KEY_A)
		prog->move_lat += 1;
	else if (keycode == KEY_D)
		prog->move_lat -= 1;
	else if (keycode == KEY_LEFT)
		prog->move_rot -= 1;
	else if (keycode == KEY_RIGHT)
		prog->move_rot += 1;
	return (0);
}

int	onmouse_move(int x, int y, t_program *prog)
{
	(void) y;
	prog->mouse_rot += (((double) WIN_WIDTH / 2) - (double)x) * MOUSE_PADDING;
	mlx_mouse_move(prog->mlx, prog->mlx_win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}

static int	is_possible(char **map, double x, double y)
{
	int	i;
	int	j;

	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			if (map[(int)(y + MOV_PADDING * i)][(int)(x + MOV_PADDING * j)]
					== CHAR_WALL)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	move_player(t_program *prog)
{
	double	x_new;
	double	y_new;

	prog->player.rot += prog->mouse_rot + prog->move_rot * ROT_PADDING;
	x_new = prog->player.x + (double)prog->move_lon * MOV_PADDING * \
		cos(prog->player.rot / 180 * M_PI) + (double)prog->move_lat * \
			MOV_PADDING * sin(prog->player.rot / 180 * M_PI);
	y_new = prog->player.y - (double)prog->move_lon * MOV_PADDING * \
		sin(prog->player.rot / 180 * M_PI) + (double)prog->move_lat \
			* MOV_PADDING * cos(prog->player.rot / 180 * M_PI);
	if (is_possible(prog->map, x_new, y_new))
	{
		prog->player.x = x_new;
		prog->player.y = y_new;
	}
	else if (is_possible(prog->map, x_new, prog->player.y))
		prog->player.x = x_new;
	else if (is_possible(prog->map, prog->player.x, y_new))
		prog->player.y = y_new;
}
