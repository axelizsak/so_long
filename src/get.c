/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:56:07 by aizsak            #+#    #+#             */
/*   Updated: 2023/01/28 17:01:31 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_p(t_mlx *s)
{
	int	x;
	int	y;

	x = 0;
	while (s->map[x] != NULL)
	{
		y = 0;
		while (s->map[x][y] != '\0')
		{
			if (s->map[x][y] == 'P')
			{
				s->x_ligne = x;
				s->y_colonne = y;
			}
			y++;
		}
		x++;
	}
}

void	get_e(t_mlx *s)
{
	int	x;
	int	y;

	x = 0;
	while (s->map[x] != NULL)
	{
		y = 0;
		while (s->map[x][y] != '\0')
		{
			if (s->map[x][y] == 'E')
			{
				s->e_ligne = x;
				s->e_colonne = y;
			}
			y++;
		}
		x++;
	}
}

int	get_fl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
		{
			free(str);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	get_ber(char *fn)
{
	int	i;
	int	j;

	if (!fn)
		exit (-1);
	i = ft_strlen(fn);
	if (i <= 4)
		return (-1);
	j = 0;
	while (fn[j] != '.')
		j++;
	if (fn[j + 1] != 'b' || fn[j + 2] != 'e' || fn[j + 3] != 'r')
		return (-1);
	return (0);
}
