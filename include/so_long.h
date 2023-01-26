/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:12:40 by aizsak            #+#    #+#             */
/*   Updated: 2023/01/26 14:56:00 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>

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
	int	**map;
	int	*mlx;
	int	v;
	int	m;
	int	c;
	int	e;
	int	p;
	int	item;
	int	on_item;
	int	img;

}t_mlx

int	get_map(char *fn, t_mlx *mlx);
void	load_map(char *fn, t_mlx *mlx);
int	check_cont(t_mlx *mlx);
int	check_map(t_mlx *mlx);
void	init_map(char *fn, t_mlx *mlx);
static void	found_line(t_mlx *s);
static void	found_map(t_mlx *s);
static int	check_path(t_mlx *s);
void	pathfinding(char *fn, t_mlx *s);
static void	path_x(t_mlx *s, int x, int y);
static void 	path_y(t_mlx *s, int x, int y);
static void	path(t_mlx *s, int x, int y);
void	get_P(t_mlx *s);
void	get_E(t_mlx *s);
int	get_fl(char *str);
int	get_ber(char *fn);
void	clean_map(t_mlx *mlx);
void	windowsing(t_mlx *mlx);
void	imagination(t_mlx *s, char **fi);
void	typ_img(char c, t_mlx *s);
void	map_img(t_mlx *s);
void	mlx_win_init(t_mlx *mlx);
int	no_event(t_mlx *mlx);
int	count_mouve(int key, t_mlx *s);
int	keypress(int key, t_mlx *s);
void	mlx_hook_init(t_mlx mlx);

#endif
