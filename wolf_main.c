/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 11:54:32 by vame              #+#    #+#             */
/*   Updated: 2015/06/30 13:39:59 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			wolf_print_error(int err)
{
	if (err == ERR_ARG)
		ft_printf("{red}Bad number of arguments.{eoc}\n");
	if (err == ERR_MAP)
		ft_printf("{red}Bad format of map.{eoc}\n");
	if (err == ERR_MAL)
		ft_printf("{red}Malloc error.{eoc}\n");
	if (err == ERR_OPN)
		ft_printf("{red}Open error: file not found.{eoc}\n");
	if (err == ERR_RED)
		ft_printf("{red}Read error.{eoc}\n");
	if (err == ERR_CLS)
		ft_printf("{red}Close error.{eoc}\n");
	if (err == ERR_GNL)
		ft_printf("{red}Get_next_line error.{eoc}\n");
	exit(err);
}

static void		wolf_init_params(t_win *env)
{
	env->w = 512;
	env->h = 384;
	env->player_x = 22;
	env->player_y = 12;
	env->dir_x = -1;
	env->dir_y = 0;
	env->plane_x = 0;
	env->plane_y = 0.66;
}

void			wolf_print_map(t_map *map)
{
	int			x;
	int			y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
			ft_printf("%d ", map->points[y][x++]);
		y++;
		ft_printf("\n");
	}
}

int				main(void)
{
	t_win		env;
	t_map		map;

	wolf_create_map(&map, MAP_NAME);
	env.map = &map;
	wolf_print_map(env.map);
	wolf_init_params(&env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.w, env.h, "Wolf3D");
	mlx_expose_hook(env.win, wolf_expose_hook, &env);
	mlx_key_hook(env.win, wolf_key_hook, &env);
	mlx_loop_hook(env.mlx, ftol_loop_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
