/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_expose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 12:53:03 by vame              #+#    #+#             */
/*   Updated: 2015/07/01 15:41:06 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int					wolf_loop_hook(t_win *e)
{
	wolf_expose_hook(e);
	return (0);
}

int					wolf_expose_hook(t_win *e)
{
	e->img = mlx_new_image(e->mlx, e->w, e->h);
	e->img_str = mlx_get_data_addr(e->img, &e->bpp, &e->len, &e->endian);
	wolf_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (1);
}
