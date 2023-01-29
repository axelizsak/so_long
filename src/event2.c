/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:19:30 by aizsak            #+#    #+#             */
/*   Updated: 2023/01/29 14:20:21 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap_contents(t_mlx *s, int ligne, int colonne)
{
	char	tmp;

	tmp = s->map[s->x_ligne][s->y_colonne];
	s->map[s->x_ligne][s->y_colonne] = s->map[ligne][colonne];
	s->map[ligne][colonne] = tmp;
}

void	mouve_player(int key, t_mlx *s)
{
	if (key == W && s->map[s->x_ligne - 1][s->y_colonne] != '1')
		swap_contents(s, s->x_ligne - 1, s->y_colonne);
	if (key == S && s->map[s->x_ligne + 1][s->y_colonne] != '1')
		swap_contents(s, s->x_ligne + 1, s->y_colonne);
	if (key == A && s->map[s->x_ligne][s->y_colonne - 1] != '1')
		swap_contents(s, s->x_ligne, s->y_colonne - 1);
	if (key == D && s->map[s->x_ligne][s->y_colonne + 1] != '1')
		swap_contents(s, s->x_ligne, s->y_colonne + 1);
	if (s->on_item == s->item)
		s->map[s->e_ligne][s->e_colonne] = 'E';
}

void	recolt_contents(int key, t_mlx *s)
{
	if (key == D && s->map[s->x_ligne][s->y_colonne + 1] == 'C')
	{
		s->on_item++;
		s->map[s->x_ligne][s->y_colonne + 1] = '0';
	}
	if (key == A && s->map[s->x_ligne][s->y_colonne - 1] == 'C')
	{
		s->on_item++;
		s->map[s->x_ligne][s->y_colonne - 1] = '0';
	}
	if (key == S && s->map[s->x_ligne + 1][s->y_colonne] == 'C')
	{
		s->on_item++;
		s->map[s->x_ligne + 1][s->y_colonne] = '0';
	}
	if (key == W && s->map[s->x_ligne - 1][s->y_colonne] == 'C')
	{
		s->on_item++;
		s->map[s->x_ligne - 1][s->y_colonne] = '0';
	}
}

void	exit_game(int key, t_mlx *s)
{
	if (key == A && s->map[s->x_ligne][s->y_colonne - 1] == 'E')
		free_mlx(s, 4);
	if (key == D && s->map[s->x_ligne][s->y_colonne + 1] == 'E')
		free_mlx(s, 4);
	if (key == S && s->map[s->x_ligne + 1][s->y_colonne] == 'E')
		free_mlx(s, 4);
	if (key == W && s->map[s->x_ligne - 1][s->y_colonne] == 'E')
		free_mlx(s, 4);
}

void	game_events(int key, t_mlx *mlx)
{
	get_p(mlx);
	exit_game(key, mlx);
	recolt_contents(key, mlx);
	mouve_player(key, mlx);
	map_img(mlx);
}
