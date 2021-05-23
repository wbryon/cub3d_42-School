/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:46:15 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/27 00:51:43 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_all all;

	all.map.map = NULL;
	if (argc == 2 || argc == 3)
	{
		check_open(argv[1]);
		check_map_extension(argv[1]);
		read_map(argv[1], &all);
		if (argc == 3)
		{
			if (ft_strncmp(argv[2], "--save", 7) == 0)
				all.check.shot = 1;
			else
				errors_table_4(4);
		}
	}
	else
		errors_table_6(1);
	play_game(&all);
	return (0);
}

void	play_game(t_all *all)
{
	int		screen_size_x;
	int		screen_size_y;

	init_all_vars(all);
	mlx_get_screen_size(all->win.mlx, &screen_size_x, &screen_size_y);
	if (all->check.shot == 1)
	{
		take_shot(all);
	}
	if (all->win.screen_w > screen_size_x)
		all->win.screen_w = screen_size_x;
	if (all->win.screen_h > screen_size_y)
		all->win.screen_h = screen_size_y;
	all->win.win = mlx_new_window(all->win.mlx, all->win.screen_w,
			all->win.screen_h, "cub3D");
	create_image(all);
	mlx_hook(all->win.win, 2, 0, key_press, all);
	mlx_hook(all->win.win, 3, 0, key_release, all);
	mlx_hook(all->win.win, 17, 0, &exit_hook, all);
	mlx_loop_hook(all->win.mlx, rule, all);
	mlx_loop(all->win.mlx);
}

void	check_open(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd <= 0)
		errors_table_5(4);
}

void	take_shot(t_all *all)
{
	if (all->win.screen_w > 16383)
		all->win.screen_w = 16383;
	if (all->win.screen_h > 16383)
		all->win.screen_h = 16383;
	all->win.mlx = mlx_init();
	all->win.win = mlx_new_window(all->win.mlx, all->win.screen_w,
			all->win.screen_h, "cub3D");
	create_image(all);
	screenshot(all);
}
