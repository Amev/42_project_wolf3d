/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 11:54:32 by vame              #+#    #+#             */
/*   Updated: 2015/06/15 14:17:15 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			main(int ac, char **av)
{
	t_win	env;

	(void)ac;
	(void)av;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 700, 500, "Wolf3D");
	mlx_key_hook(env.win, wolf_key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
