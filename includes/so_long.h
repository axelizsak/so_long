/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:12:40 by aizsak            #+#    #+#             */
/*   Updated: 2023/01/28 18:52:04 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307

typedef struct	s_mlx
{
	int	ligne;
	int	colonne;
	int	mouve;
	int	x_ligne;
	int	y_colonne;
	int	e_ligne;
	int	e_colonne;
	int	*win;
	char	**map;
	int	*mlx;
	int	v;
	int	m;
	int	c;
	int	e;
	int	p;
	int	item;
	int	on_item;
	int	*img[5];

}t_mlx;

int	get_map(char *fn, t_mlx *mlx);
void	load_map(char *fn, t_mlx *mlx);
int	check_cont(t_mlx *mlx);
int	check_map(t_mlx *mlx);
void	init_map(char *fn, t_mlx *mlx);
void	pathfinding(char *fn, t_mlx *s);
void	path(t_mlx *s, int x, int y);
void	get_p(t_mlx *s);
void	get_e(t_mlx *s);
int	get_fl(char *str);
int	get_ber(char *fn);
void	clean_map(t_mlx *mlx);
void	windowsing(t_mlx *mlx);
void	imagination(t_mlx *s, char **fi);
void	*typ_img(char c, t_mlx *s);
void	map_img(t_mlx *s);
void	mlx_win_init(t_mlx *mlx);
int	no_event(t_mlx *mlx);
int	count_mouve(int key, t_mlx *s);
int	keypress(int key, t_mlx *s);
void	mlx_hook_init(t_mlx mlx);
void    free_mlx(t_mlx *mlx, int i);
void	swap_contents(t_mlx *s, int ligne, int colonne);
void	mouve_player(int key, t_mlx *s);
void	recolt_contents(int key, t_mlx *s);
void	exit_game(int key, t_mlx *s);
void	game_events(int key, t_mlx *mlx);
int	handle_destroy(t_mlx *mlx);
void	destroy_all_images(t_mlx *mlx, int i);

#endif
