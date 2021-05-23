/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:31:49 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 18:42:34 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int key, t_all *all)
{
	if (key == 13)
		all->key.up = 1;
	if (key == 1)
		all->key.down = 1;
	if (key == 2)
		all->key.right = 1;
	if (key == 0)
		all->key.left = 1;
	if (key == 124 && all->key.look_left != 1)
		all->key.look_right = 1;
	else if (key == 123 && all->key.look_right != 1)
		all->key.look_left = 1;
	if (key == 53)
		all->key.esc = 1;
	return (0);
}

int		key_release(int key, t_all *all)
{
	if (key == 13)
		all->key.up = 0;
	if (key == 1)
		all->key.down = 0;
	if (key == 2)
		all->key.right = 0;
	if (key == 0)
		all->key.left = 0;
	if (key == 124)
		all->key.look_right = 0;
	if (key == 123)
		all->key.look_left = 0;
	if (key == 53)
		all->key.esc = 0;
	return (0);
}

int		rule(t_all *all)
{
	double move_speed;
	double rot_speed;

	move_speed = 0.010 * 10.0;
	rot_speed = 0.010 * 3.0;
	if (all->key.up == 1 || all->key.down == 1)
		move_up_down(all, move_speed);
	if (all->key.right == 1 || all->key.left == 1)
		move_left_right(all, move_speed);
	if (all->key.look_right == 1 || all->key.look_left == 1)
		look_left_right(all, rot_speed);
	if (all->key.esc == 1)
		exit(0);
	mlx_destroy_image(all->win.mlx, all->win.img);
	create_image(all);
	return (0);
}
