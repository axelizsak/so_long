/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:14:25 by aizsak            #+#    #+#             */
/*   Updated: 2023/01/28 12:52:29 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	found_line(t_mlx *s)
{
	int	x;
	int	y;

	x = s->x_ligne;
	y = s->y_colonne;
	while (s->map[x][y] != '\0')
	{
		if (s->map[x][y] == '#')
			path(s, x, y);
		y++;
	}
}

static void	found_map(t_mlx *s)
{
	int	x;
	int	y;
	int	z;

	z = 0;
	while (z <= s->ligne * s->colonne)
	{
		x = 0;
		while (s->map[x] != NULL)
		{
			y = 0;
			while (s->map[x][y] != '\0')
			{
				if (s->map[x][y] == '#')
					path(s, x, y);
				y++;
			}
			x++;
		}
		z++;
	}
}

static int	check_path(t_mlx *s)
{
	int	x;
	int	y;

	x = 0;
	while (s->map[x] != NULL)
	{
		y = 0;
		while (s->map[x][y] != '\0')
		{
			if (s->map[x][y] == 'E' || s->map[x][y] == 'C')
				return (-1);
			y++;
		}
		x++;
	}
	return (0);
}

void	pathfinding(char *fn, t_mlx *s)
{
	get_p(s);
	path(s, s->x_ligne, s->y_colonne);
	found_line(s);
	found_map(s);
	if (check_path(s) == -1)
	{
		ft_printf("path error");
		clean_map(s);
		exit(1);
	}
	clean_map(s);
	load_map(fn, s);
}
