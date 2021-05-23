/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:29:29 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 15:34:09 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprite(t_all *all)
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
			if (ft_strchr("2", all->map.map[y][x]))
			{
				all->sprite.x[i] = (double)(y + 0.5);
				all->sprite.y[i] = (double)(x + 0.5);
				i++;
			}
		}
		y++;
	}
}

void	sprite_position(t_all *all, int i)
{
	all->sprite.spritex = all->sprite.x[i] - all->plr.posx;
	all->sprite.spritey = all->sprite.y[i] - all->plr.posy;
	all->sprite.invdet = 1.0 / (all->plr.planex * all->plr.diry -
			all->plr.planey * all->plr.dirx);
	all->sprite.transformx = all->sprite.invdet * (all->plr.diry *
			all->sprite.spritex - all->plr.dirx * all->sprite.spritey);
	all->sprite.transformy = all->sprite.invdet * (-all->plr.planey *
			all->sprite.spritex + all->plr.planex * all->sprite.spritey);
	all->sprite.spritescreenx = (int)(all->win.screen_w / 2) *
		(1 + all->sprite.transformx / all->sprite.transformy);
	all->sprite.spriteheight = abs((int)((all->win.screen_h /
			all->sprite.transformy) * all->plr.diff));
	all->sprite.drawstarty = -all->sprite.spriteheight / 2 +
		all->win.screen_h / 2;
	if (all->sprite.drawstarty < 0)
		all->sprite.drawstarty = 0;
	all->sprite.drawendy = all->sprite.spriteheight / 2 + all->win.screen_h / 2;
	if (all->sprite.drawendy >= all->win.screen_h)
		all->sprite.drawendy = all->win.screen_h - 1;
}

void	sortsprites(t_all *all)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;

	i = -1;
	while (++i < all->sprite.nbsprites)
	{
		j = i;
		while (++j < all->sprite.nbsprites)
		{
			if (all->sprite.spritedist[j] > all->sprite.spritedist[i])
			{
				all->sprite.tmp_dist = all->sprite.spritedist[j];
				all->sprite.spritedist[j] = all->sprite.spritedist[i];
				tmp_x = all->sprite.x[j];
				tmp_y = all->sprite.y[j];
				all->sprite.x[j] = all->sprite.x[i];
				all->sprite.y[j] = all->sprite.y[i];
				all->sprite.spritedist[i] = all->sprite.tmp_dist;
				all->sprite.x[i] = tmp_x;
				all->sprite.y[i] = tmp_y;
			}
		}
	}
}

void	draw_sprite(t_all *all, int y)
{
	int d;

	d = 0;
	while (all->sprite.stripe < all->sprite.drawendx)
	{
		all->sprite.texx = (int)(256 * (all->sprite.stripe - (-all->sprite.
						spritewidth / 2 + all->sprite.spritescreenx)) *
				all->tx.tx_w / all->sprite.spritewidth) / 256;
		if (all->sprite.transformy > 0 && all->sprite.stripe > 0
				&& all->sprite.stripe < all->win.screen_w && all->sprite.
				transformy < all->sprite.zbuffer[all->sprite.stripe])
		{
			y = all->sprite.drawstarty;
			while (y < all->sprite.drawendy)
			{
				d = y * 256 - all->win.screen_h * 128 +
					all->sprite.spriteheight * 128;
				all->sprite.texy = ((d * all->tx.tx_h) /
						all->sprite.spriteheight) / 256;
				sprite_put(all, all->sprite.stripe, y);
				y++;
			}
		}
		all->sprite.stripe++;
	}
}

void	sprite_width(t_all *all)
{
	all->sprite.spritewidth = abs((int)((all->win.screen_w /
			all->sprite.transformy) / all->plr.coef));
	all->sprite.drawstartx = -all->sprite.spritewidth /
		2 + all->sprite.spritescreenx;
	if (all->sprite.drawstartx < 0)
		all->sprite.drawstartx = 0;
	all->sprite.drawendx = all->sprite.spritewidth /
		2 + all->sprite.spritescreenx;
	if (all->sprite.drawendx >= all->win.screen_w)
		all->sprite.drawendx = all->win.screen_w - 1;
	all->sprite.stripe = all->sprite.drawstartx;
}
