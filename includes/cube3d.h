/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:33:39 by glemoine          #+#    #+#             */
/*   Updated: 2023/03/06 14:29:29 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include "mlx.h"
# include "math.h"

# include "config_strings_en.h"

# define TITLE "cube 3d"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define FOV 90
# define MOV_PADDING 0.10
# define ROT_PADDING 1
# define MOUSE_PADDING 0.15

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
};

enum {
	CHAR_EMPTYSPC = '0',
	CHAR_WALL = '1',
	CHAR_P_O_N = 'N',
	CHAR_P_O_S = 'S',
	CHAR_P_O_E = 'E',
	CHAR_P_O_O = 'W',
	CHAR_SPC = ' '
};

typedef struct s_side
{
	double	x;
	double	y;
	int		face;
	int		offset;
	int		is_wall;
	double	dist;
}	t_side;

typedef struct s_player {
	double	x;
	double	y;
	double	rot;
}	t_player;

typedef struct s_img {
	void	*sprite_ptr;
	char	*addr;
	int		width;
	int		height;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

enum {
	I_NO = 0,
	I_SO = 1,
	I_WE = 2,
	I_EA = 3
};

typedef struct s_program
{
	char		**map;
	void		*mlx;
	void		*mlx_win;
	char		**colorinfos;
	char		**mapinfos;
	char		*fullmap;
	char		*line;
	t_img		main_frames[2];
	int			move_lat;
	int			move_lon;
	int			move_rot;
	double		mouse_rot;
	t_img		sprites[4];
	t_player	player;
	int			color_floor;
	int			color_ceilling;
}	t_program;

int					init_texture_info(t_program *prog, void *args);
int					init_color_info(t_program *prog, void *args);

typedef struct s_dict_item
{
	char	*id;
	void	*data;

}	t_dict_item;

static const t_dict_item	g_mapinfosfunctions[] = {
{"NO", init_texture_info},
{"SO", init_texture_info},
{"WE", init_texture_info},
{"EA", init_texture_info},
{"F", init_color_info},
{"C", init_color_info},
{NULL, 0}
};

static const t_dict_item	g_mapinfosspritesindex[] = {
{"NO", (void *)I_NO},
{"SO", (void *)I_SO},
{"WE", (void *)I_WE},
{"EA", (void *)I_EA},
{NULL, NULL}
};

//init.c
void				init_player(t_program *prog);
void				init_map(t_program *prog, int fd);
void				init_main_frames(void *mlx, t_img *frames, t_program *prog);
void				init_main(t_program *prog, char *map_filename);

//init_mapinfos.c
int					init_mapinfos(t_program *prog, int fd);

//check_error.c
int					check_map_lines(char *map, t_program *prog);
void				check_map_chars(char *map, t_program *prog);
void				check_map_wall(char **map, t_program *prog);

//event.c
int					onkeydown(int keycode, t_program *prog);
int					onkeyup(int keycode, t_program *prog);
int					onmouse_move(int x, int y, t_program *prog);
void				move_player(t_program *prog);

//main.c
void				cleanandexit(void *data);

//utils.c
int					file_open(char *map_filename, t_program *prog);
int					convert_from_rgb(int r, int g, int b);
int					ft_atoi_basique_max(char *str, int max);
int					call_mappedfct(t_program *prog, t_dict_item *tab, \
					char *id, void *args);
void				*get_mappedfunction(t_program *prog, t_dict_item *tab, \
					char *id);

//raycasting_utils.c
unsigned int		pixel_get(t_img *img, int x, int y);
void				pixel_put(t_img *img, int x, int y, int color);
int					get_texture(t_side *wall, double rot);
int					wich_x(t_side *wall, int width);
int					get_len_tab(char **tab);
//raycasting.c
void				raycasting(t_program *prog, t_img *image);

#endif
