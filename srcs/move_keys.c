/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:17:46 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 18:56:44 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up_down(t_all *all, double speed)
{
	if (all->key.up == 1)
	{
		if (all->map.map[(int)(all->plr.posx + all->plr.dirx *
		speed * 5)][(int)all->plr.posy] != '1')
			all->plr.posx = all->plr.posx + all->plr.dirx * speed;
		if (all->map.map[(int)all->plr.posx][(int)(all->plr.posy + all->plr.diry
		* speed * 5)] != '1')
			all->plr.posy = all->plr.posy + all->plr.diry * speed;
	}
	if (all->key.down == 1)
	{
		if (all->map.map[(int)(all->plr.posx - all->plr.dirx *
		speed)][(int)all->plr.posy] != '1')
			all->plr.posx = all->plr.posx - all->plr.dirx * speed;
		if (all->map.map[(int)all->plr.posx][(int)(all->plr.posy -
		all->plr.diry * speed)] != '1')
			all->plr.posy = all->plr.posy - all->plr.diry * speed;
	}
}

void	move_left_right(t_all *all, double speed)
{
	all->plr.movespeed = all->plr.movespeed / 2;
	if (all->key.right == 1)
	{
		if (all->map.map[(int)(all->plr.posx + all->plr.diry *
		speed * 3)][(int)(all->plr.posy)] != '1')
			all->plr.posx += all->plr.diry * speed;
		if (all->map.map[(int)(all->plr.posx)][(int)(all->plr.posy -
		all->plr.dirx * (speed * 3))] != '1')
			all->plr.posy -= all->plr.dirx * speed;
	}
	if (all->key.left == 1)
	{
		if (all->map.map[(int)(all->plr.posx - all->plr.diry *
		speed * 3)][(int)(all->plr.posy)] != '1')
			all->plr.posx -= all->plr.diry * speed;
		if (all->map.map[(int)(all->plr.posx)][(int)(all->plr.posy -
		-all->plr.dirx * (speed * 3))] != '1')
			all->plr.posy -= -all->plr.dirx * speed;
	}
}

void	look_left_right(t_all *all, double rs)
{
	if (all->key.look_right == 1)
	{
		all->plr.olddirx = all->plr.dirx;
		all->plr.dirx = all->plr.dirx * cos(-rs) - all->plr.diry * sin(-rs);
		all->plr.diry = all->plr.olddirx * sin(-rs) + all->plr.diry * cos(-rs);
		all->plr.oldplanex = all->plr.planex;
		all->plr.planex = all->plr.planex * cos(-rs) -
				all->plr.planey * sin(-rs);
		all->plr.planey = all->plr.oldplanex * sin(-rs) +
				all->plr.planey * cos(-rs);
	}
	if (all->key.look_left == 1)
	{
		all->plr.olddirx = all->plr.dirx;
		all->plr.dirx = all->plr.dirx * cos(rs) - all->plr.diry * sin(rs);
		all->plr.diry = all->plr.olddirx * sin(rs) + all->plr.diry * cos(rs);
		all->plr.oldplanex = all->plr.planex;
		all->plr.planex = all->plr.planex * cos(rs) -
				all->plr.planey * sin(rs);
		all->plr.planey = all->plr.oldplanex * sin(rs) +
				all->plr.planey * cos(rs);
	}
}

int		exit_hook(void)
{
	exit(0);
	return (0);
}
