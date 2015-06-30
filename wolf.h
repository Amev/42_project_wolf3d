/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 11:51:53 by vame              #+#    #+#             */
/*   Updated: 2015/06/30 16:57:33 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/libft_ext.h"
# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <math.h>
# include <time.h>
# include <stdio.h>

# define ERR_ARG 1
# define ERR_MAP 2
# define ERR_MAL 3
# define ERR_OPN 4
# define ERR_RED 5
# define ERR_CLS 6
# define ERR_GNL 7

# define MAP_NAME "map"

# define KEY_ESC 53
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_7 26
# define KEY_8 28
# define KEY_9 25
# define KEY_0 29
# define KEY_A 0
# define KEY_W 13
# define KEY_D 2
# define KEY_S 1
# define KEY_SPACE 49

typedef struct		s_map
{
	int				**points;
	int				y;
	int				x;
}					t_map;

typedef struct		s_win
{
	int				w;
	int				h;
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_str;
	int				bpp;
	int				len;
	int				endian;
	struct s_map	*map;
	float			player_x;
	float			player_y;
	float			plane_x;
	float			plane_y;
	float			cam_x;
	float			cam_y;
	float			dir_x;
	float			dir_y;
	float			time;
	float			old_time;
}					t_win;

typedef struct		s_super_struct
{
	struct s_win	*e;
	int				x;
	int				x_max;
	float			pos_x;
	float			pos_y;
	float			camera_x;
	float			rdir_x;
	float			rdir_y;
	int				map_x;
	int				map_y;
	float			d_side_x;
	float			d_side_y;
	float			delta_x;
	float			delta_y;
	float			wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
}					t_super_struct;

int					wolf_key_hook(int k, t_win *env);
void				wolf_create_map(t_map *map, char *map_name);
void				wolf_print_error(int err);
int					wolf_expose_hook(t_win *e);
int					wolf_loop_hook(t_win *e);

#endif
