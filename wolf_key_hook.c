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

int			wolf_key_hook(int k, t_win *env)
{
	float	tmp;

	if (k == KEY_ESC)
		exit(0);
	if (k == KEY_A)
	{
		tmp = env->dir_x;
		env->dir_x = env->dir_x * cos(0.314) - env->dir_y * sin(0.314);
		env->dir_y = tmp * sin(0.314) + env->dir_y * cos(0.314);
		tmp = env->plane_x;
		env->plane_x = env->plane_x * cos(0.314) - env->plane_y * sin(0.314);
		env->plane_y = tmp * sin(0.314) + env->plane_y * cos(0.314);
		wolf_expose_hook(env);
	}
	if (k == KEY_D)
	{
		tmp = env->dir_x;
		env->dir_x = env->dir_x * cos(-0.314) - env->dir_y * sin(-0.314);
		env->dir_y = tmp * sin(-0.314) + env->dir_y * cos(-0.314);
		tmp = env->plane_x;
		env->plane_x = env->plane_x * cos(-0.314) - env->plane_y * sin(-0.314);
		env->plane_y = tmp * sin(-0.314) + env->plane_y * cos(-0.314);
		wolf_expose_hook(env);
	}
	if (k == KEY_W)
	{
		if (env->map->points[(int)env->player_y][(int)(env->player_x +
					env->dir_x * 0.5)] == 0)
			env->player_x += env->dir_x + 0.5;
		if (env->map->points[(int)(env->player_y + env->dir_y * 0.5)]
				[(int)env->player_x] == 0)
			env->player_y += env->dir_y + 0.5;
		wolf_expose_hook(env);
	}
	return (0);
}
