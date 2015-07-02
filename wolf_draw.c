/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 13:08:37 by vame              #+#    #+#             */
/*   Updated: 2015/07/02 15:50:01 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void			wolf_init_struct(t_win *e, t_super_struct *s)
{
	s->hit = 0;
	s->pos_x = e->player_x;
	s->pos_y = e->player_y;
	s->camera_x = (2 * (float)(s->x) / (float)(e->w)) - 1;
	s->rdir_x = e->dir_x + e->plane_x * s->camera_x;
	s->rdir_y = e->dir_y + e->plane_y * s->camera_x;
	s->map_x = (int)s->pos_x;
	s->map_y = (int)s->pos_y;
	s->delta_x = sqrt(1 + (s->rdir_y * s->rdir_y) / (s->rdir_x * s->rdir_x));
	s->delta_y = sqrt(1 + (s->rdir_x * s->rdir_x) / (s->rdir_y * s->rdir_y));
	s->step_x = s->rdir_x < 0 ? -1 : 1;
	s->step_y = s->rdir_y < 0 ? -1 : 1;
	if (s->rdir_x < 0)
		s->d_side_x = (s->pos_x - s->map_x) * s->delta_x;
	else
		s->d_side_x = (s->map_x + 1.0 - s->pos_x) * s->delta_x;
	if (s->rdir_y < 0)
		s->d_side_y = (s->pos_y - s->map_y) * s->delta_y;
	else
		s->d_side_y = (s->map_y + 1.0 - s->pos_y) * s->delta_y;
}

static void			wolf_dda_algo(t_super_struct *s)
{
	while (s->hit == 0)
	{
		if (s->d_side_x < s->d_side_y)
		{
			s->d_side_x += s->delta_x;
			s->map_x += s->step_x;
			s->side = s->step_x < 0 ? 0 : 1;
		}
		else
		{
			s->d_side_y += s->delta_y;
			s->map_y += s->step_y;
			s->side = s->step_y < 0 ? 2 : 3;
		}
		if (s->e->map->points[s->map_y][s->map_x] != 0)
		{
			s->hit = 1;
			s->e->map->mini[s->map_y][s->map_x] = 1;
		}
	}
	if (s->side < 2)
		s->wall_dist = (s->map_x - s->pos_x + (1 - s->step_x) / 2) / s->rdir_x;
	else
		s->wall_dist = (s->map_y - s->pos_y + (1 - s->step_y) / 2) / s->rdir_y;
	s->wall_dist = s->wall_dist < 0 ? -(s->wall_dist) : s->wall_dist;
}

static void			wolf_draw_line(t_super_struct *s, int x, t_win *e)
{
	int				i;
	int				y;
	int				color;

	y = s->draw_start;
	color = s->side == 0 ? 0xFFFF00 : 0x000000;
	color = s->side == 1 ? 0xFF0000 : color;
	color = s->side == 2 ? 0x0066FF : color;
	color = s->side == 3 ? 0x37FF00 : color;
	while (y < s->draw_end)
	{
		i = x * 4 + y * e->len;
		e->img_str[i] = (color & 0xFF);
		e->img_str[i + 1] = (color & 0xFF00) >> 8;
		e->img_str[i + 2] = (color & 0xFF0000) >> 16;
		y++;
	}
}

static void			*wolf_draw_part(void *param)
{
	t_super_struct	*s;
	t_win			*e;

	s = (struct s_super_struct *)param;
	e = s->e;
	while (s->x < s->x_max)
	{
		wolf_init_struct(e, s);
		wolf_dda_algo(s);
		s->line_height = ft_abs((int)(s->e->h * 1.5 / s->wall_dist));
		s->draw_start = ft_max(0, (-(s->line_height) / 2 + e->h / 2));
		s->draw_end = ft_min((s->e->h - 1), (s->line_height / 2 + e->h / 2));
		wolf_draw_line(s, s->x, e);
		wolf_draw_floor(s, s->x, e);
		s->x++;
	}
	pthread_exit(NULL);
}

int					wolf_draw(t_win *e)
{
	int				i;
	pthread_t		thread[8];
	t_super_struct	s[8];

	i = 0;
	while (i < 8)
	{
		s[i].e = e;
		s[i].x = e->w * i / 8;
		s[i].x_max = s[i].x + e->w / 8;
		if (pthread_create(&thread[i], NULL, &wolf_draw_part, (void *)&s[i])
				== -1)
			wolf_print_error(ERR_THD);
		i++;
	}
	i = 0;
	while (i < 8)
		if (pthread_join(thread[i++], NULL) == -1)
			wolf_print_error(ERR_THD);
	return (1);
}
