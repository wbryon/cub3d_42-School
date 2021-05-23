/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 23:21:37 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 23:21:40 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_texture(t_all *all, int x, int y)
{
	all->tx.texx = ((int)(all->plr.wallx * 100) % 100) * all->tx.tx_h / 100;
	all->tx.step = 1.0 * all->tx.tx_h / all->tx.lineheight;
	all->tx.texpos = (all->tx.drawstart - all->win.screen_h / 2
	+ all->tx.lineheight / 2) * all->tx.step;
	all->tx.ceil = 0;
	while (all->tx.ceil < all->tx.drawstart)
		my_mlx_pixel_put(all, x, all->tx.ceil++, all->tx.ceil_color);
	draw_vert_line(all, x, y);
	all->tx.floor = all->tx.drawend;
	while (all->tx.floor < all->win.screen_h)
		my_mlx_pixel_put(all, x, all->tx.floor++, all->tx.floor_color);
	all->sprite.zbuffer[x] = all->plr.pwd;
}
