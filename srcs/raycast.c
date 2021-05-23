/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:43:36 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 03:50:37 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_direction(t_all *all, int x)
{
	all->plr.camerax = 2 * x / (double)all->win.screen_w - 1;
	all->plr.raydirx = all->plr.dirx + all->plr.planex * all->plr.camerax;
	all->plr.raydiry = all->plr.diry + all->plr.planey * all->plr.camerax;
	all->map.mapx = (int)all->plr.posx;
	all->map.mapy = (int)all->plr.posy;
	all->plr.deltadistx = fabs(1 / all->plr.raydirx);
	all->plr.deltadisty = fabs(1 / all->plr.raydiry);
}

void	init_distance(t_all *all)
{
	if (all->plr.raydirx < 0)
	{
		all->plr.stepx = -1;
		all->plr.sidedistx = (all->plr.posx - all->map.mapx) *
			all->plr.deltadistx;
	}
	else
	{
		all->plr.stepx = 1;
		all->plr.sidedistx = (all->map.mapx + 1.0 - all->plr.posx) *
			all->plr.deltadistx;
	}
	if (all->plr.raydiry < 0)
	{
		all->plr.stepy = -1;
		all->plr.sidedisty = (all->plr.posy - all->map.mapy) *
			all->plr.deltadisty;
	}
	else
	{
		all->plr.stepy = 1;
		all->plr.sidedisty = (all->map.mapy + 1.0 - all->plr.posy) *
			all->plr.deltadisty;
	}
}

void	dda_execute(t_all *all)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (all->plr.sidedistx < all->plr.sidedisty)
		{
			all->plr.sidedistx = all->plr.sidedistx + all->plr.deltadistx;
			all->map.mapx = all->map.mapx + all->plr.stepx;
			all->plr.side = 0;
		}
		else
		{
			all->plr.sidedisty = all->plr.sidedisty + all->plr.deltadisty;
			all->map.mapy = all->map.mapy + all->plr.stepy;
			all->plr.side = 1;
		}
		if (all->map.map[all->map.mapx][all->map.mapy] == '1')
			hit = 1;
	}
}

void	cast_rays(t_all *all)
{
	if (all->plr.side == 0)
		all->plr.pwd = (all->map.mapx - all->plr.posx +
		(1 - all->plr.stepx) / 2) / all->plr.raydirx;
	else
		all->plr.pwd = (all->map.mapy - all->plr.posy +
		(1 - all->plr.stepy) / 2) / all->plr.raydiry;
	all->tx.lineheight = (int)(all->win.screen_h / all->plr.pwd);
	if (all->win.screen_w > all->win.screen_h)
	{
		all->plr.diff = 1.0 * all->win.screen_w / all->win.screen_h;
		all->tx.lineheight *= all->plr.diff;
		all->tx.lineheight = (int)all->tx.lineheight;
	}
	all->tx.drawstart = -all->tx.lineheight / 2 + all->win.screen_h / 2;
	if (all->tx.drawstart < 0)
		all->tx.drawstart = 0;
	all->tx.drawend = all->tx.lineheight / 2 + all->win.screen_h / 2;
	if (all->tx.drawend >= all->win.screen_h)
		all->tx.drawend = all->win.screen_h - 1;
	if (all->plr.side == 0)
		all->plr.wallx = all->plr.posy + all->plr.pwd * all->plr.raydiry;
	else
		all->plr.wallx = all->plr.posx + all->plr.pwd * all->plr.raydirx;
}

void	ray_sprite(t_all *all, int y)
{
	int i;

	i = 0;
	while (i < all->sprite.nbsprites)
	{
		all->sprite.spriteorder[i] = i;
		all->sprite.spritedist[i] = ((all->plr.posx - all->sprite.x[i]) *
				(all->plr.posx - all->sprite.x[i]) + (all->plr.posy -
					all->sprite.y[i]) * (all->plr.posy - all->sprite.y[i]));
		i++;
	}
	sortsprites(all);
	i = 0;
	while (i < all->sprite.nbsprites)
	{
		sprite_position(all, i);
		sprite_width(all);
		draw_sprite(all, y);
		i++;
	}
}
