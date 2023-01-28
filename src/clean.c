/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:16:49 by aizsak            #+#    #+#             */
/*   Updated: 2023/01/28 16:01:05 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_map(t_mlx *mlx)
{
	int	i;

	i = mlx->ligne;
	while (i >= 0)
	{
		free (mlx->map[i]);
		i--;
	}
	free (mlx->map);
}

void	destroy_all_images(t_mlx *mlx, int i)
{
	while (i >= 0)
	{
		mlx_destroy_image(mlx->mlx, mlx->img[i]);
		i--;
	}
}

void	free_mlx(t_mlx *mlx, int i)
{
	destroy_all_images(mlx, i);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	clean_map(mlx);
	exit(0);
}

int	handle_destroy(t_mlx *mlx)
{
	destroy_all_images(mlx, 4);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	clean_map(mlx);
	exit(0);
}
