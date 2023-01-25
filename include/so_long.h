/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:12:40 by aizsak            #+#    #+#             */
/*   Updated: 2023/01/25 11:40:36 by aizsak           ###   ########.fr       */
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
	int	*win;
	int	**map;
	int	*mlx;
	int	v;
	int	m;
	int	c;
	int	e;
	int	p;
	int	item;

}t_mlx

#endif
