/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:03:41 by aizsak            #+#    #+#             */
/*   Updated: 2023/01/26 14:53:40 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	no_event(t_mlx *mlx)
{
	(void)mlx;
	return (0);
}

int	count_mouve(int key, t_mlx *s)
{
	if ((key == W && s->map[s->x_ligne - 1][s->y_colonne] != '1') || (key == S && s->map[s->x_ligne + 1][s->y_colonne] != '1') || (key == A && s->map[s->x_ligne][s->y_colonne - 1] != '1') || (key == D && s->map[s->x_ligne][s->y_colonne + 1]))
		return (1);
	return (0);
}

int	keypress(int key, t_mlx *s)
{
	static unsigned int	i;

	if (key == ESC)
		mlx_destroy_window(s->mlx, s->win);
	if (key == W || key == S || key == A || key == D)
	{
		event(key, s);
		if (count_mouve(key, s))
		{
			i++;
			s->mouve = i;
			ft_printf();//le nombre de mouves
		}
		return (0);
	}
}

void	mlx_hook_init(t_mlx mlx)
{
	mlx_loop_hook(mlx.mlx, &no_event, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, &handle_destroy, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, &keypress, &mlx);
}
