/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 18:24:45 by skerkour          #+#    #+#             */
/*   Updated: 2015/05/02 18:25:41 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstlen(t_list *lst)
{
	unsigned int	ret;

	ret = 0;
	if (lst)
	{
		while (lst)
			++ret, lst = lst->next;
	}
	return (ret);
}
