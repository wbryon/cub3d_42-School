/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:38:38 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 15:21:53 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_all *all)
{
	int i;
	int x;
	int y;

	i = 0;
	y = begin_map(all);
	while (y < end_map(all))
	{
		x = -1;
		while (all->map.map[y][++x])
		{
			if (ft_strchr("SWEN", all->map.map[y][x]))
			{
				all->plr.posx = y + 0.5;
				all->plr.posy = x + 0.5;
				all->plr.plr_count++;
				position_n_s(all->map.map[y], all);
				position_w_e(all->map.map[y], all);
			}
			if (ft_strchr("2", all->map.map[y][x]))
				i++;
		}
		y++;
	}
	all->sprite.nbsprites = i;
}

void	position_n_s(char *line, t_all *all)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (ft_strchr("N", line[i]) || ft_strchr("S", line[i]))
		{
			all->plr.dirx = -1;
			all->plr.diry = 0;
			all->plr.planex = 0;
			all->plr.planey = 0.66 * all->plr.coef;
			if (ft_strchr("S", line[i]))
				all->plr.dirx *= -1;
			if (ft_strchr("S", line[i]))
				all->plr.planey *= -1;
		}
	}
}

void	position_w_e(char *line, t_all *all)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (ft_strchr("W", line[i]) || ft_strchr("E", line[i]))
		{
			all->plr.dirx = 0;
			all->plr.diry = -1;
			all->plr.planex = -0.66 * all->plr.coef;
			all->plr.planey = 0;
			if (ft_strchr("E", line[i]))
				all->plr.diry *= -1;
			if (ft_strchr("E", line[i]))
				all->plr.planex *= -1;
		}
	}
}
