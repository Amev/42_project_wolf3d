/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_create_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vame <vame@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 14:09:29 by vame              #+#    #+#             */
/*   Updated: 2015/06/22 14:34:44 by vame             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static char			**wolf_read_map(char *map)
{
	int			fd;
	int			res;
	char		*line;
	char		**read;

	line = NULL;
	read = NULL;
	if ((fd = open(map, O_RDONLY)) == -1)
		wolf_print_error(ERR_OPN);
	while ((res = get_next_line_2(fd, &line)) == 1)
		read = wolf_join_line(&line, &read);
	if (res == -1)
		wolf_print_error(ERR_GNL);
	if (close(fd) == -1)
		wolf_print_error(ERR_CLS);
	return (read);
}

static char			**wolf_join_line(char **line, char ***read)
{
	size_t		i;
	size_t		len;
	char		**new;

	i = 0;
	len = 0;
	while (*read && (*read)[len])
		len++;
	if (!(new = (char **)malloc(sizeof(char *) * (len + 2))))
		fdf_print_error(ERR_MAL);
	new[len + 1] = NULL;
	while (i++ < len)
		new[i - 1] = (*read)[i - 1];
	new[len] = *line;
	if (*read)
		free(*read);
	return (new);
}

static void			wolf_malloc_y_map(t_map *map, char **read)
{
	int			y;

	y = 0;
	while (read && read[y])
		y++;
	if (!y)
		wolf_print_error(ERR_MAP);
	if (!(map->points = (int **)malloc(sizeof(int *) * (y))))
		wolf_print_error(ERR_MAL);
	map->x = 0;
	map->y = y;
	map->z_min = INT_MAX;
	map->z_max = INT_MIN;
}

static void			wolf_malloc_x_map(t_map *map, char **split, int y)
{
	int			x;

	x = 0;
	while (split && split[x])
		x++;
	if (!x)
		wolf_print_error(ERR_MAP);
	if (!(map->points[y - 1] = (int *)malloc(sizeof(int) * (x + 1))))
		wolf_print_error(ERR_MAL);
	map->points[y - 1][0] = x + 1;
	if (x > map->x)
		map->x = x;
}

void			wolf_create_map(t_map *map, char *map)
{
	int			y;
	int			x;
	char		**read;
	char		**split;

	read = wolf_read_map(map);
	wolf_malloc_y_map(map, read);
	while (read && read[y++] && !(x = 0))
	{
		if (!(split = ft_nbrsplit(read[y - 1])))
			wolf_print_error(ERR_MAL);
		wolf_malloc_x_map(map, split, y);
		while (split && split[x++])
			map->points[y - 1][x] = wolf_create_alti(split[x - 1], map);
		ft_strdel_double(&split);
	}
	ft_strdel_double(&read);
}
