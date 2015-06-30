/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 13:08:37 by vame              #+#    #+#             */
/*   Updated: 2015/06/30 16:57:32 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void			wolf_init_struct(t_win *e, t_super_struct *s)
{
	s->hit = 0;
	s->pos_x = e->player_x;
	s->pos_y = e->player_y;
	s->camera_x = 2 * s->x / (float)e->w - 1;
	s->rdir_x = e->dir_x + e->plane_x * s->camera_x;
	s->rdir_y = e->dir_y + e->plane_y * s->camera_x;
	s->map_x = (int)s->pos_x;
	s->map_y = (int)s->pos_y;
	s->delta_x = sqrt(1 + (s->rdir_y * s->rdir_y) / (s->rdir_x * s->rdir_x));
	s->delta_y = sqrt(1 + (s->rdir_x * s->rdir_x) / (s->rdir_y * s->rdir_y));
	s->step_x = e->dir_x < 0 ? -1 : 1;
	s->step_y = e->dir_y < 0 ? -1 : 1;
	if (e->dir_x < 0)
		s->d_side_x = (s->pos_x - s->map_x) * s->delta_x;
	else
		s->d_side_x = (s->map_x + 1.0 - s=>pos_x) * s->delta_x;
	if (e->dix_y < 0)
		s->d_side_y = (s->pos_y - s->map_y) * s->delta_y;
	else
		s->d_side_y = (s->map_y + 1.0 - s=>pos_y) * s->delta_y;
}

static void			wolf
		while (s->hit == 0)
		{
			if (s->d_side_x < s->d_side_y)
			{
				
			}
		}
static int			wolf_draw_part(void *param)
{
	t_super_struct	*s;
	t_win			*e;

	s = (struct s_super_struct *)param;
	e = s->e;
	while (s->x < s->x_max)
	{
		wolf_init_struct(e, s);
	}
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
		s[i].x_max = s[i].x + e->w * i / 8;
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
