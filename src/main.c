/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:43:11 by glemoine          #+#    #+#             */
/*   Updated: 2023/03/06 14:58:51 by iel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include "cube3d.h"

void	cleanandexit(void *data)
{
	t_program	*prog;
	int			i;

	prog = data;
	if (!prog->mlx)
		exit(EXIT_FAILURE);
	ft_mid_free_array(&prog->colorinfos, 0);
	ft_mid_free_array(&prog->mapinfos, 0);
	ft_mid_free_int(&prog->line, ft_mid_free_int(&prog->fullmap, 0));
	if (prog->mlx_win)
		mlx_destroy_window(prog->mlx, prog->mlx_win);
	mlx_do_key_autorepeaton(prog->mlx);
	i = 2;
	while (i-- > 0)
		if (prog->main_frames[i].sprite_ptr)
			mlx_destroy_image(prog->mlx, prog->main_frames[i].sprite_ptr);
	while (++i < 4)
		if (prog->sprites[i].sprite_ptr)
			mlx_destroy_image(prog->mlx, prog->sprites[i].sprite_ptr);
	if (prog->mlx)
		mlx_destroy_display(prog->mlx);
	ft_free(&prog->mlx);
	if (prog->map)
		ft_mid_free_array(&prog->map, 0);
	exit(EXIT_SUCCESS);
}

static void	init_prog(t_program *prog)
{
	prog->mlx = 0;
	prog->map = 0;
	prog->mlx_win = 0;
	prog->sprites[0].sprite_ptr = 0;
	prog->sprites[1].sprite_ptr = 0;
	prog->sprites[2].sprite_ptr = 0;
	prog->sprites[3].sprite_ptr = 0;
	prog->main_frames[0].sprite_ptr = 0;
	prog->main_frames[1].sprite_ptr = 0;
	prog->colorinfos = 0;
	prog->mapinfos = 0;
	prog->line = 0;
	prog->fullmap = 0;
}

int	loop(void *data)
{
	t_program	*prog;
	static int	n_frame;

	prog = data;
	move_player(prog);
	if (!prog->move_lat && !prog->move_lon && \
		!prog->mouse_rot && !prog->move_rot)
		return (0);
	prog->mouse_rot = 0;
	raycasting(prog, prog->main_frames + n_frame);
	mlx_put_image_to_window(prog->mlx, prog->mlx_win, \
		prog->main_frames[n_frame].sprite_ptr, 0, 0);
	n_frame = 1 - n_frame;
	return (0);
}

int	main(int argc, char **argv)
{
	t_program	prog;

	init_prog(&prog);
	ft_errorif(argc != 2, ERR_BAD_ARGS, cleanandexit, &prog);
	init_main(&prog, *(argv + 1));
	mlx_hook(prog.mlx_win, ON_DESTROY, 0, (void *)cleanandexit, &prog);
	mlx_hook(prog.mlx_win, ON_MOUSEMOVE, 1L << 6, onmouse_move, &prog);
	mlx_do_key_autorepeatoff(prog.mlx);
	mlx_hook(prog.mlx_win, ON_KEYUP, 2, onkeyup, &prog);
	mlx_hook(prog.mlx_win, ON_KEYDOWN, 1, onkeydown, &prog);
	mlx_mouse_hide(prog.mlx, prog.mlx_win);
	raycasting(&prog, prog.main_frames + 1);
	mlx_put_image_to_window(prog.mlx, prog.mlx_win, \
		prog.main_frames[1].sprite_ptr, 0, 0);
	mlx_loop_hook(prog.mlx, loop, &prog);
	mlx_loop(prog.mlx);
	cleanandexit(&prog);
	return (EXIT_SUCCESS);
}
