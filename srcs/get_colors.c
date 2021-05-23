/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:07:49 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 21:22:03 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_c(char *line, t_all *all)
{
	if (all->check.c > 0)
		errors_table_3(1);
	if (!ft_isdigit(*line) || ((all->col.c_r = ft_atoi(line)) < 0) ||
			((all->col.c_r = ft_atoi(line)) > 255))
		errors_table_6(1);
	line += skip_digits(line);
	if (*line != ',')
		errors_table_5(1);
	line++;
	line += skip_spaces(line);
	if (!ft_isdigit(*line) || ((all->col.c_g = ft_atoi(line)) < 0) ||
			((all->col.c_g = ft_atoi(line)) > 255))
		errors_table_5(2);
	line += skip_digits(line);
	if (*line != ',')
		errors_table_5(2);
	line++;
	line += skip_spaces(line);
	if (!ft_isdigit(*line) || ((all->col.c_b = ft_atoi(line)) < 0) ||
			((all->col.c_b = ft_atoi(line)) > 255))
		errors_table_5(3);
	line += skip_digits(line);
	if (*line != '\0')
		errors_table_2(3);
}

void	parse_f(char *line, t_all *all)
{
	if (all->check.f > 0)
		errors_table_3(2);
	if (!ft_isdigit(*line) || ((all->col.f_r = ft_atoi(line)) < 0) ||
			((all->col.f_r = ft_atoi(line)) > 255))
		errors_table_4(1);
	line += skip_digits(line);
	if (*line != ',')
		errors_table_4(1);
	line++;
	line += skip_spaces(line);
	if (!ft_isdigit(*line) || ((all->col.f_g = ft_atoi(line)) < 0) ||
			((all->col.f_g = ft_atoi(line)) > 255))
		errors_table_4(2);
	line += skip_digits(line);
	if (*line != ',')
		errors_table_4(2);
	line++;
	line += skip_spaces(line);
	if (!ft_isdigit(*line) || ((all->col.f_b = ft_atoi(line)) < 0) ||
			((all->col.f_b = ft_atoi(line)) > 255))
		errors_table_4(2);
	line += skip_digits(line);
	if (*line != '\0')
		errors_table_2(4);
}

void	get_colors(char *line, t_all *all)
{
	if (ft_strchr(line, 'C'))
	{
		line++;
		line += skip_spaces(line);
		parse_c(line, all);
		all->check.c++;
		all->check.id_count++;
	}
	if (ft_strchr(line, 'F'))
	{
		line++;
		line += skip_spaces(line);
		parse_f(line, all);
		all->check.f++;
		all->check.id_count++;
	}
	all->tx.ceil_color = (all->col.c_r << 16 |
			all->col.c_g << 8 | all->col.c_b);
	all->tx.floor_color = (all->col.f_r << 16 |
			all->col.f_g << 8 | all->col.f_b);
}
