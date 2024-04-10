/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_strings_en.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glemoine <glemoine@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:29 by glemoine          #+#    #+#             */
/*   Updated: 2022/11/30 19:39:27 by glemoine         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_STRINGS_EN_H
# define CONFIG_STRINGS_EN_H

# define ERR_BAD_ARGS "bad number of arguments\nusage: ./cube3d map_filename"

# define ERR_FILE_BAD "can't open the file using provided filename"
# define ERR_FILE_EXTENSION "the filename has to end with .cub"

# define ERR_MALLOC "can't malloc\n"
# define ERR_PARSING_MAPINFOS "there is at least one invalid map info"
# define ERR_PARSING_MAPINFOSTOOMUCH "there is an least one duplicate map info"
# define ERR_PARSING_COLOR "bad color informations"
# define ERR_PARSING_NBRMAPINFOS "there is at least one missing map info"
# define ERR_OPEN_TEXTURE "can't open the texture file"

# define ERR_MAP_NOPLAYER "there is no player start position"
# define ERR_MAP_UNKNOWCHAR "the map has at least one invalid char"
# define ERR_MAP_TOOMUCHPLAYER "there is more than one player start position"
# define ERR_MAP_INVALID "the map is invalid"
# define ERR_MAP_INVALIDWALL "there is a problem with the map's walls"

# define ERR_MLX_INIT "can't init mlx"
# define ERR_MLX_WIN_INIT "can't init mlx window"
#endif