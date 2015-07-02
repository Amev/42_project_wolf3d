/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_expose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 12:53:03 by vame              #+#    #+#             */
/*   Updated: 2015/07/02 15:50:00 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void			wolf_print_wall_minimap(int x, int y, t_win *e)
{
	int				i;
	int				j;
	int				k;
	int				i_max;
	int				j_max;

	j = y * e->h / (8 * e->map->y);
	j_max = j + e->h / (8 * e->map->y) + 1;
	while (j < j_max)
	{
		i = x * e->w / (8 * e->map->x);
		i_max = i + e->w / (8 * e->map->x) + 1;
		while (i < i_max)
		{
			k = i++ * 4 + j * e->len;
			e->img_str[k] = (0xFF0000 & 0xFF);
			e->img_str[k + 1] = (0xFF0000 & 0xFF00) >> 8;
			e->img_str[k + 2] = (0xFF0000 & 0xFF0000) >> 16;
		}
		j++;
	}
}

static void			wolf_draw_minimap(t_win *e)
{
	int				x;
	int				y;

	y = 0;
	while (y < e->map->y)
	{
		x = 0;
		while (x < e->map->x)
		{
			if (e->map->mini[y][x] == 1)
				wolf_print_wall_minimap(x, y, e);
			x++;
		}
		y++;
	}
}

void				wolf_draw_floor(t_super_struct *s, int x, t_win *e)
{
	int				i;
	int				y;
	int				color;

	y = s->draw_end;
	color = 0x505050;
	while (y < e->h)
	{
		i = x * 4 + y * e->len;
		e->img_str[i] = (color & 0xFF);
		e->img_str[i + 1] = (color & 0xFF00) >> 8;
		e->img_str[i + 2] = (color & 0xFF0000) >> 16;
		y++;
	}
}

int					wolf_expose_hook(t_win *e)
{
	e->img = mlx_new_image(e->mlx, e->w, e->h);
	e->img_str = mlx_get_data_addr(e->img, &e->bpp, &e->len, &e->endian);
	wolf_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->w / 8, e->h / 8);
	e->img_str = mlx_get_data_addr(e->img, &e->bpp, &e->len, &e->endian);
	wolf_draw_minimap(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->w * 7 / 8, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (1);
}
