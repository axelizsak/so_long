/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:06:25 by aizsak            #+#    #+#             */
/*   Updated: 2023/01/28 19:24:32 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argc;
	init_map(argv[1], &mlx);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
	{
		free(mlx.mlx);
		exit(-1);
	}
	mlx_win_init(&mlx);
	mlx_hook_init(mlx);
	mlx_loop(mlx.mlx);
	destroy_all_images(&mlx, 4);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
	clean_map(&mlx);
}
