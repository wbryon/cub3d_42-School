/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:02:16 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 23:55:54 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_id(t_all *all)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (++i < begin_map(all))
	{
		count += check_valid_id(all->map.map[i]);
		if (ft_strchr(all->map.map[i], 'N') || ft_strchr(all->map.map[i], 'S')
		|| ft_strchr(all->map.map[i], 'W') || ft_strchr(all->map.map[i], 'E')
		|| ft_strchr(all->map.map[i], 'C') || ft_strchr(all->map.map[i], 'F')
		|| ft_strchr(all->map.map[i], 'R'))
			id_distributor(all->map.map[i], all);
		else if (all->map.map[i][0] != '\0')
			errors_table_1(1);
	}
	if (count != 12)
		errors_table_1(1);
	check_chars_in_map(all);
}

int		check_valid_id(char *line)
{
	int		j;
	int		count;

	j = 0;
	count = 0;
	if (line[0] == ' ')
		errors_table_1(1);
	while (*line)
	{
		if (ft_strchr(line, 'N') || ft_strchr(line, 'S')
		|| ft_strchr(line, 'W') || ft_strchr(line, 'E')
		|| ft_strchr(line, 'C') || ft_strchr(line, 'F')
		|| ft_strchr(line, 'R') || ft_strchr(line, 'O')
		|| ft_strchr(line, 'A'))
			count++;
		line++;
	}
	return (count);
}

void	id_distributor(char *line, t_all *all)
{
	if (ft_strncmp("NO ", line, 3) == 0)
		parse_path_no(line, all);
	else if (ft_strncmp("SO ", line, 3) == 0)
		parse_path_so(line, all);
	else if (ft_strncmp("WE ", line, 3) == 0)
		parse_path_we(line, all);
	else if (ft_strncmp("EA ", line, 3) == 0)
		parse_path_ea(line, all);
	else if (ft_strncmp("S ", line, 2) == 0)
		parse_path_s(line, all);
	else if (ft_strncmp("R ", line, 2) == 0)
		parse_r(line, all);
	else if (ft_strncmp("C ", line, 2) == 0)
		get_colors(line, all);
	else if (ft_strncmp("F ", line, 2) == 0)
		get_colors(line, all);
	else
		errors_table_1(1);
}

void	parse_r(char *line, t_all *all)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = ft_split(line, ' ')))
		errors_table_10(1);
	line++;
	line += skip_spaces(line);
	line += skip_digits(line);
	line += skip_spaces(line);
	line += skip_digits(line);
	if (*line != '\0')
		errors_table_1(2);
	while (tab[i])
		i++;
	if (!(ft_strncmp("R", tab[0], 2) == 0 && all->check.r != 1) || i != 3)
		errors_table_1(2);
	all->check.r++;
	get_resolution(tab, all);
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	get_resolution(char **line, t_all *all)
{
	int		i;

	if (!(ft_isdigit(*line[1])) ||
			((all->win.screen_w = ft_atoi(line[1])) <= 0))
		errors_table_1(3);
	i = skip_digits(line[1]);
	if (line[1][i] != '\0')
		errors_table_1(3);
	if (!(ft_isdigit(*line[2])) ||
			((all->win.screen_h = ft_atoi(line[2])) <= 0))
		errors_table_1(4);
	i = 0;
	i = skip_digits(line[2]);
	if (line[2][i] != '\0')
		errors_table_1(4);
	all->check.id_count++;
	if (all->win.screen_w < all->win.screen_h)
		all->plr.coef = 1.0 * all->win.screen_w / all->win.screen_h;
}
