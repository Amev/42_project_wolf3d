/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 11:51:53 by vame              #+#    #+#             */
/*   Updated: 2015/06/15 14:04:58 by vame             ###   ########.fr       */
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
	float			player_x;
	float			player_y;
	float			cam_x;
	float			cam_y;
	float			dir_x;
	float			dir_y;
	float			time;
	float			old_time;
}					t_win;

int			wolf_key_hook(int k, t_win *env);

#endif
