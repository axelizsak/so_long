/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:11:05 by aizsak            #+#    #+#             */
/*   Updated: 2023/01/28 17:00:11 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	path_x(t_mlx *s, int x, int y)
{
	int	x1;

	x1 = x;
	while (s->map[x][y] != '1' && x <= s->ligne)
	{
		s->map[x][y] = '#';
		x++;
	}
	x = x1;
	while (s->map[x][y] != '1' && x >= 0)
	{
		s->map[x][y] = '#';
		x--;
	}
	x = x1;
}

static void	path_y(t_mlx *s, int x, int y)
{
	int	y1;

	y1 = y;
	while (s->map[x][y] != '1' && y <= s->colonne)
	{
		s->map[x][y] = '#';
		y++;
	}
	y = y1;
	while (s->map[x][y] != '1' && y >= 0)
	{
		s->map[x][y] = '#';
		y--;
	}
	y = y1;
}

void	path(t_mlx *s, int x, int y)
{
	path_x(s, x, y);
	path_y(s, x, y);
}
