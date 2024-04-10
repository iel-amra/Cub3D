/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:28:26 by glemoine          #+#    #+#             */
/*   Updated: 2023/03/06 13:28:10 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_player(t_program *prog)
{
	int	y;
	int	x;

	y = -1;
	while (prog->map[++y])
	{
		x = -1;
		while (prog->map[y][++x])
		{
			if (prog->map[y][x] == CHAR_P_O_E || prog->map[y][x] == CHAR_P_O_N \
			|| prog->map[y][x] == CHAR_P_O_O || prog->map[y][x] == CHAR_P_O_S)
			{
				prog->player.x = (double) x + 0.5;
				prog->player.y = (double) y + 0.5;
			}
			if (prog->map[y][x] == CHAR_P_O_E)
				prog->player.rot = 0;
			else if (prog->map[y][x] == CHAR_P_O_N)
				prog->player.rot = 90;
			else if (prog->map[y][x] == CHAR_P_O_O)
				prog->player.rot = 180;
			else if (prog->map[y][x] == CHAR_P_O_S)
				prog->player.rot = 270;
		}
	}
}

void	init_map(t_program *prog, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		prog->fullmap = ft_strjoin(prog->fullmap, line, NULL, 1 | 2);
		line = get_next_line(fd);
	}
	ft_errorif(check_map_lines(prog->fullmap, prog), \
		ERR_MAP_INVALID, cleanandexit, prog);
	check_map_chars(prog->fullmap, prog);
	prog->map = ft_split(prog->fullmap, '\n');
	ft_free(&prog->fullmap);
	ft_errifnul(prog->map, ERR_MALLOC, cleanandexit, prog);
	check_map_wall(prog->map, prog);
}

void	init_main_frames(void *mlx, t_img *frames, t_program *prog)
{
	frames[0].sprite_ptr = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	frames[1].sprite_ptr = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	ft_errorif(!frames[0].sprite_ptr || !frames[1].sprite_ptr, \
		ERR_MALLOC, cleanandexit, prog);
	frames[0].width = WIN_WIDTH;
	frames[1].width = WIN_WIDTH;
	frames[0].height = WIN_HEIGHT;
	frames[1].height = WIN_HEIGHT;
	frames[0].addr = mlx_get_data_addr(frames[0].sprite_ptr, \
		&frames[0].bit_per_pixel, &frames[0].size_line,
			&frames[0].endian);
	frames[1].addr = mlx_get_data_addr(frames[1].sprite_ptr, \
		&frames[1].bit_per_pixel, &frames[1].size_line,
			&frames[1].endian);
	ft_errorif(!frames[0].addr || !frames[1].addr, \
	ERR_MALLOC, cleanandexit, prog);
}

void	init_main(t_program *prog, char *map_filename)
{
	int		fd;

	prog->mlx = mlx_init();
	ft_errifnul(prog->mlx, ERR_MLX_INIT, cleanandexit, prog);
	fd = file_open(map_filename, prog);
	init_mapinfos(prog, fd);
	init_map(prog, fd);
	close(fd);
	init_player(prog);
	prog->mouse_rot = 0;
	prog->move_lat = 0;
	prog->move_lon = 0;
	prog->move_rot = 0;
	prog->mlx_win = mlx_new_window(prog->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	ft_errifnul(prog->mlx_win, ERR_MLX_WIN_INIT, cleanandexit, prog);
	init_main_frames(prog->mlx, prog->main_frames, prog);
}
