/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:34:52 by aizsak            #+#    #+#             */
/*   Updated: 2023/01/29 14:19:42 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	windowsing(t_mlx *s)
{
	static char	*fi[5] = {"img/v.xpm", "img/m.xpm", "img/c.xpm", "img/e.xpm", "img/p.xpm"};
	s->win = mlx_new_window(s->mlx, s->colonne * 50, s->ligne * 50, "Oz");
	if (!s->win)
	{
		free(s->win);
		exit (-1);
	}
	imagination(s, fi);
}

void	imagination(t_mlx *s, char **fi)
{
	int	i;
	int	j;

	j = 0;
	while (j <= 4)
	{
		s->img[j] = mlx_xpm_file_to_image(s->mlx, fi[j], &i, &i);
		if (j == 0 && !s->img[j])
		{
			mlx_destroy_window(s->mlx, s->win);
			mlx_destroy_display(s->mlx);
			free(s->mlx);
			clean_map(s);
			exit(0);
		}
		else if (!s->img[j])
			free_mlx(s, j - 1);
		j++;
	}
}

void	*typ_img(char c, t_mlx *s)
{
	if (c == '0')
		return (s->img[0]);
	if (c == '1')
		return (s->img[1]);
	if (c == 'C')
		return (s->img[2]);
	if (c == 'E')
		return (s->img[3]);
	if (c == 'P')
		return (s->img[4]);
	return (0);
}

void	map_img(t_mlx *s)
{
	int	x;
	int	y;

	x = 0;
	while (s->map[x] != NULL)
	{
		y = 0;
		while (s->map[x][y] != '\0')
		{
			mlx_put_image_to_window(s->mlx, s->win,
				typ_img(s->map[x][y], s),
				(y * 50), (x * 50));
			y++;
		}
		x++;
	}
}

void	mlx_win_init(t_mlx *mlx)
{
	windowsing(mlx);
	map_img(mlx);
}
