/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 14:01:47 by vame              #+#    #+#             */
/*   Updated: 2015/07/01 15:53:52 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		wolf_key_rot(float a, t_win *env)
{
	float		tmp;

	tmp = env->dir_x;
	env->dir_x = env->dir_x * cos(a) - env->dir_y * sin(a);
	env->dir_y = tmp * sin(a) + env->dir_y * cos(a);
	tmp = env->plane_x;
	env->plane_x = env->plane_x * cos(a) - env->plane_y * sin(a);
	env->plane_y = tmp * sin(a) + env->plane_y * cos(a);
	wolf_expose_hook(env);
}

static void		wolf_key_move(float a, t_win *env)
{
	if (env->map->points[(int)env->player_y][(int)(env->player_x +
				env->dir_x * a)] == 0)
		env->player_x += env->dir_x * a;
	if (env->map->points[(int)(env->player_y + env->dir_y * a)]
			[(int)env->player_x] == 0)
		env->player_y += env->dir_y * a;
	wolf_expose_hook(env);
}

static void		wolf_key_strafe(float a, t_win *env)
{
	if (env->map->points[(int)env->player_y][(int)(env->player_x +
				env->plane_x * a)] == 0)
		env->player_x += env->plane_x * a;
	if (env->map->points[(int)(env->player_y + env->plane_y * a)]
			[(int)env->player_x] == 0)
		env->player_y += env->plane_y * a;
	wolf_expose_hook(env);
}

int				wolf_key_hook(int k, t_win *env)
{
	if (k == KEY_ESC)
		exit(0);
	if (k == KEY_A)
		wolf_key_rot(0.2, env);
	if (k == KEY_D)
		wolf_key_rot(-0.2, env);
	if (k == KEY_W)
		wolf_key_move(0.5, env);
	if (k == KEY_S)
		wolf_key_move(-0.5, env);
	if (k == KEY_Q)
		wolf_key_strafe(-0.5, env);
	if (k == KEY_E)
		wolf_key_strafe(0.5, env);
	return (0);
}
