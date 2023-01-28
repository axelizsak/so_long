/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:26:49 by aizsak            #+#    #+#             */
/*   Updated: 2023/01/28 19:07:30 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *rdr, char *buff)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!rdr && !buff)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen1(rdr) + ft_strlen1(buff)) + 1);
	if (!str)
		return (NULL);
	if (buff)
	{
		while (buff[i] != '\0')
		{
			str[i] = buff[i];
			i++;
		}
	}
	while (rdr[++j] != '\0')
		str[i + j] = rdr[j];
	if (buff)
		free(buff);
	str[i + j] = '\0';
	return (str);
}

int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}
