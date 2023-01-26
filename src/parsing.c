/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:12:49 by aizsak            #+#    #+#             */
/*   Updated: 2023/01/26 11:23:04 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map(char *fn, t_mlx *mlx)
{
	int	fd;
	int	i;
	char	*str;

	fd = open(fn, O_RDONLY);
	str = get_next_line(fd);
	if (!str || fd < 0)
		return (-1);
	mlx->colonne = ft_strlen(str) - 1;
	i = 0;
	while (str)
	{
		i++;
		if (i == 1 && get_fl(str) == -1)
			return (-1);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	mlx->ligne = i;
	return (0);
}

void	load_map(char *fn, t_mlx *mlx)
{
	int	i;
	int	j;
	int	fd;
	char	*line;

	i = 0;
	fd = open(fn, O_RDONLY);
	mlx->map = malloc(sizeof(char*) * (mlx->ligne + 1));
	if (!mlx->map)
		return;
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		while (line[j] != '\n' && line[j] != '\0')
			j++;
		line[j] = '\0';
		mlx->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	mlx->map[i] = NULL;
	close(fd);
}

int	check_cont(t_mlx *mlx)
{
	t_mlx	check;
	check.v = 0;
	check.c = 0;
	check.e = 0;
	check.p = 0;

	while (mlx->map[check.v] != NULL)
	{
		check.m = 0;
		while (mlx->map[check.v][check.m] != '\0')
		{
			if (mlx->map[check.v][check.m] == 'C')
				check.c++;
			if (mlx->map[check.v][check.m] == 'E')
				check.e++;
			if (mlx->map[check.v][check.m] == 'P')
				check.p++;
			check.m++;
		}
		check.v++;
	}
	mlx->item = check.c;
	if (check.c < 1 || check.e != 1 || check.p != 1)
		return (-1);
	return (0);
}

int	check_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i] != NULL)
	{
		j = 0;
		while (mlx->map[i][j] != '\0')
		{
			if ((mlx->map[i][j] != '0') && (mlx->map[i][j] != '1') && (mlx->map[i][j] != 'C') && (mlx->map[i][j] != 'E') && (mlx->map[i][j] != 'P'))
				return (-1);
			if (((i == 0 || i == mlx->ligne - '1') && (mlx->map[i][j] != '1')) || (mlx->map[i][0] != '1'))
				return (-1);
			j++;
		}
		if (j != mlx->colonne || mlx->map[i][j - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

void	init_map(char *fn, t_mlx *mlx)
{
	get_ber(fn);
	get_map(fn, mlx);
	load_map(fn, mlx);
	if (check_map(mlx) == -1 || check_cont(mlx) == -1)
	{
		clean_map(mlx);
		exit (ft_printf("error dans les checks"));
	}
	pathfinding(fn, mlx);
	get_E(mlx);
	mlx->on_item = 0;
	mlx->mouve = 0;
	mlx->map[mlx->e_ligne][mlx->e_colonne]  = 0;
}
