/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 01:34:13 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 22:20:44 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_all_vars(t_all *all)
{
	init_plr_vars(all);
	init_sprite_vars(all);
	init_tx_vars(all);
	init_win_check_vars(all);
	parse_id(all);
	init_player(all);
	if (!(all->sprite.x = malloc(sizeof(double) * all->sprite.nbsprites)))
		errors_table_10(1);
	if (!(all->sprite.y = malloc(sizeof(double) * all->sprite.nbsprites)))
		errors_table_10(1);
	if (!(all->sprite.spritedist = malloc(sizeof(double) *
	all->sprite.nbsprites)))
		errors_table_10(1);
	if (!(all->sprite.spriteorder = malloc(sizeof(int) *
	all->sprite.nbsprites)))
		errors_table_10(1);
	if (!(all->sprite.zbuffer = ft_calloc(all->win.screen_w, sizeof(double))))
		errors_table_10(1);
	init_sprite(all);
	all->win.mlx = mlx_init();
	get_tx_no(all);
	get_tx_so(all);
	get_tx_we(all);
	get_tx_ea(all);
	get_tx_s(all);
}

void	init_plr_vars(t_all *all)
{
	all->map.mapx = 0;
	all->map.mapy = 0;
	all->plr.posx = 0;
	all->plr.posy = 0;
	all->plr.dirx = 0;
	all->plr.diry = 0;
	all->plr.olddirx = 0;
	all->plr.olddiry = 0;
	all->plr.movespeed = 0;
	all->plr.planex = 0;
	all->plr.planey = 0;
	all->plr.oldplanex = 0;
	all->plr.camerax = 0;
	all->plr.coef = 1.0;
	all->plr.diff = 1.0;
}

void	init_sprite_vars(t_all *all)
{
	all->sprite.nbsprites = 0;
	all->sprite.spritescreenx = 0;
	all->sprite.vmovescreen = 0;
	all->sprite.spriteheight = 0;
	all->sprite.spritewidth = 0;
	all->sprite.drawstartx = 0;
	all->sprite.drawendx = 0;
	all->sprite.drawstarty = 0;
	all->sprite.drawendy = 0;
	all->sprite.stripe = 0;
	all->sprite.tx_h = 0;
	all->sprite.tx_w = 0;
	all->sprite.texx = 0;
	all->sprite.texy = 0;
	all->sprite.texture = 0;
	all->sprite.nbsprites = 0;
	all->sprite.spriteorder = 0;
	all->sprite.spritedist = 0;
	all->sprite.tmp_dist = 0;
	all->sprite.invdet = 0;
	all->sprite.spritex = 0;
	all->sprite.spritey = 0;
	all->sprite.transformx = 0;
	all->sprite.transformy = 0;
}

void	init_tx_vars(t_all *all)
{
	all->tx.ceil = 0;
	all->tx.floor = 0;
	all->tx.ceil_color = 0;
	all->tx.floor_color = 0;
	all->tx.tx_h = 0;
	all->tx.tx_w = 0;
	all->tx.texx = 0;
	all->tx.texy = 0;
	all->tx.lineheight = 0;
	all->tx.drawstart = 0;
	all->tx.drawend = 0;
	all->tx.step = 0;
	all->tx.texpos = 0;
	all->tx.line_l = 0;
	all->tx.bpp = 0;
	all->tx.en = 0;
	all->tx.img_no = NULL;
	all->tx.img_so = NULL;
	all->tx.img_we = NULL;
	all->tx.img_ea = NULL;
}

void	init_win_check_vars(t_all *all)
{
	all->win.line_l = 0;
	all->win.bpp = 0;
	all->win.endian = 0;
	all->win.screen_w = 0;
	all->win.screen_h = 0;
	all->check.id_count = 0;
	all->check.r = 0;
	all->check.no = 0;
	all->check.so = 0;
	all->check.we = 0;
	all->check.ea = 0;
	all->check.s = 0;
	all->check.f = 0;
	all->check.c = 0;
	if (all->win.screen_w > 16384)
		all->win.screen_w = 16384;
	if (all->win.screen_h > 16384)
		all->win.screen_h = 16384;
}
