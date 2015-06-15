/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 14:01:47 by vame              #+#    #+#             */
/*   Updated: 2015/06/15 14:17:14 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			wolf_key_hook(int k, t_win *env)
{
	(void)env;
	ft_printf("%d\n", k);
	if (k == KEY_ESC)
		exit(0);
	return (0);
}
