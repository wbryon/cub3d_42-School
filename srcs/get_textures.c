/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:58:28 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/22 14:24:07 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_tx_no(t_all *all)
{
	if ((all->tx.img_no = mlx_xpm_file_to_image(all->win.mlx, all->tx.path_no,
					&all->tx.tx_h, &all->tx.tx_w)) == NULL)
	{
		ft_putstr_fd("Error\ncannot read path NO\n", 1);
		exit(-1);
	}
	all->tx.addr_no = mlx_get_data_addr(all->tx.img_no, &all->tx.bpp,
			&all->tx.line_l, &all->tx.en);
}

void	get_tx_so(t_all *all)
{
	if ((all->tx.img_so = mlx_xpm_file_to_image(all->win.mlx, all->tx.path_so,
				&all->tx.tx_h, &all->tx.tx_w)) == NULL)
	{
		ft_putstr_fd("Error\ncannot read path SO\n", 1);
		exit(-1);
	}
	all->tx.addr_so = mlx_get_data_addr(all->tx.img_so, &all->tx.bpp,
			&all->tx.line_l, &all->tx.en);
}

void	get_tx_we(t_all *all)
{
	if ((all->tx.img_we = mlx_xpm_file_to_image(all->win.mlx, all->tx.path_we,
					&all->tx.tx_h, &all->tx.tx_w)) == NULL)
	{
		ft_putstr_fd("Error\ncannot read path WE\n", 1);
		exit(-1);
	}
	all->tx.addr_we = mlx_get_data_addr(all->tx.img_we, &all->tx.bpp,
			&all->tx.line_l, &all->tx.en);
}

void	get_tx_ea(t_all *all)
{
	if ((all->tx.img_ea = mlx_xpm_file_to_image(all->win.mlx, all->tx.path_ea,
				&all->tx.tx_h, &all->tx.tx_w)) == NULL)
	{
		ft_putstr_fd("Error\ncannot read path EA\n", 1);
		exit(-1);
	}
	all->tx.addr_ea = mlx_get_data_addr(all->tx.img_ea, &all->tx.bpp,
			&all->tx.line_l, &all->tx.en);
}

void	get_tx_s(t_all *all)
{
	if ((all->sprite.img = mlx_xpm_file_to_image(all->win.mlx,
			all->sprite.path_s, &all->sprite.tx_h, &all->sprite.tx_w)) == NULL)
	{
		ft_putstr_fd("Error\ncannot read path S\n", 1);
		exit(-1);
	}
	all->sprite.addr = mlx_get_data_addr(all->sprite.img, &all->sprite.bpp,
			&all->sprite.line_l, &all->sprite.en);
}
