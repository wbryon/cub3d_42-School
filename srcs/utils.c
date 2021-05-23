/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:48:01 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 15:27:56 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		begin_map(t_all *all)
{
	int		i;
	int		j;
	int		res;
	int		count;

	i = -1;
	res = 0;
	while (all->map.map[++i])
	{
		j = -1;
		count = 0;
		while (all->map.map[i][++j])
		{
			if (all->map.map[i][j] == ' ' || all->map.map[i][j] == '0' ||
			all->map.map[i][j] == '1' || all->map.map[i][j] == '2' ||
			all->map.map[i][j] == 'N' || all->map.map[i][j] == 'S' ||
			all->map.map[i][j] == 'W' || all->map.map[i][j] == 'E')
				count++;
		}
		if (((int)ft_strlen(all->map.map[i]) - (count) == 0) &&
				(count != 0) && all->map.map[i][0] != '\0')
			return (res = i);
	}
	return (i);
}

int		end_map(t_all *all)
{
	int		i;

	i = -1;
	while (all->map.map[++i])
		;
	return (i);
}

void	check_map_extension(char *str)
{
	int i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(str + i, ".cub", 5) != 0)
	{
		ft_putstr_fd("Error\nThe extension must be '.cub'!\n", 1);
		exit(1);
	}
	if (ft_strlen(str) <= 4)
	{
		ft_putstr_fd("Errror\nWrong map\n", 1);
		exit(-1);
	}
}

int		skip_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	return (i);
}

int		skip_digits(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	return (i);
}
