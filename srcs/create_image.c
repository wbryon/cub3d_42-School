/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:38:29 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/27 00:51:38 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_image(t_all *all)
{
	int x;
	int y;

	x = 0;
	y = 0;
	all->win.img = mlx_new_image(all->win.mlx, all->win.screen_w,
		all->win.screen_h);
	all->win.addr = mlx_get_data_addr(all->win.img, &all->win.bpp,
		&all->win.line_l, &all->win.endian);
	while (++x < all->win.screen_w - 1)
	{
		ray_direction(all, x);
		init_distance(all);
		dda_execute(all);
		cast_rays(all);
		draw_texture(all, x, y);
	}
	ray_sprite(all, y);
	if (all->check.shot == 0)
		mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img, 0, 0);
}

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->win.addr + (y * all->win.line_l + x * (all->win.bpp / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_texel_put(t_all *all, int x, int y)
{
	char	*src;
	char	*dst;

	if (all->plr.side == 0 && all->plr.posx > all->map.mapx)
		src = all->tx.addr_no + (all->tx.texy * all->tx.line_l +
		all->tx.texx * (all->tx.bpp / 8));
	if (all->plr.side == 0 && all->plr.posx < all->map.mapx)
		src = all->tx.addr_so + (all->tx.texy * all->tx.line_l +
		all->tx.texx * (all->tx.bpp / 8));
	if (all->plr.side == 1 && all->plr.posy < all->map.mapy)
		src = all->tx.addr_ea + (all->tx.texy * all->tx.line_l +
		all->tx.texx * (all->tx.bpp / 8));
	if (all->plr.side == 1 && all->plr.posy > all->map.mapy)
		src = all->tx.addr_we + (all->tx.texy * all->tx.line_l +
		all->tx.texx * (all->tx.bpp / 8));
	dst = all->win.addr + (y * all->win.line_l + x * (all->win.bpp / 8));
	*(unsigned int*)dst = *(unsigned int*)src;
}

void	sprite_put(t_all *all, int x, int y)
{
	char	*src;
	char	*dst;

	src = NULL;
	if (all->sprite.transformy > 0 && all->sprite.stripe > 0 &&
	all->sprite.stripe < all->win.screen_w && all->sprite.transformy
	< all->sprite.zbuffer[all->sprite.stripe])
		src = all->sprite.addr + (all->sprite.texy *
		all->sprite.line_l + all->sprite.texx *
		(all->sprite.bpp / 8));
	if (*(unsigned int*)src == 0x000000)
		return ;
	dst = all->win.addr + (y * all->win.line_l + x * (all->win.bpp / 8));
	*(unsigned int*)dst = *(unsigned int*)src;
}

void	draw_vert_line(t_all *all, int x, int y)
{
	y = all->tx.drawstart;
	while (y <= all->tx.drawend)
	{
		all->tx.texy = (int)all->tx.texpos;
		all->tx.texpos = all->tx.texpos + all->tx.step;
		my_mlx_texel_put(all, x, y);
		y++;
	}
}
