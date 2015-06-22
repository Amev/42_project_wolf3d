/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:15:22 by vame              #+#    #+#             */
/*   Updated: 2014/11/12 10:28:35 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 10 || n <= -10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(ft_abs(n % 10), fd);
	}
	else
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		ft_putchar_fd('0' + ft_abs(n), fd);
	}
}