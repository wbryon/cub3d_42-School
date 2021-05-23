/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:12:15 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/27 00:40:48 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screenshot(t_all *all)
{
	int		fd_read;

	fd_read = open("screenshot.bmp", O_WRONLY | O_CREAT | O_APPEND, 00666);
	bitmap_header(all, fd_read);
	bitmap_info(all, fd_read);
	fill_color(all, fd_read);
	close(fd_read);
	exit(0);
}

void	bitmap_header(t_all *all, int fd_read)
{
	int				size;
	unsigned char	header[14];
	int				i;

	i = 0;
	while (i < 14)
		header[i++] = (unsigned char)(0);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	size = all->win.screen_w * all->win.screen_h * 4 + 54;
	header[2] = (unsigned char)(size);
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[10] = (unsigned char)(54);
	write(fd_read, header, 14);
}

void	bitmap_info(t_all *all, int fd_read)
{
	int					size;
	unsigned char		header[40];
	int					i;

	i = 0;
	while (i < 40)
		header[i++] = (unsigned char)(0);
	size = all->win.screen_w;
	header[0] = (unsigned char)(40);
	header[4] = (unsigned char)(size);
	header[5] = (unsigned char)(size >> 8);
	header[6] = (unsigned char)(size >> 16);
	header[7] = (unsigned char)(size >> 24);
	size = all->win.screen_h;
	header[8] = (unsigned char)(size);
	header[9] = (unsigned char)(size >> 8);
	header[10] = (unsigned char)(size >> 16);
	header[11] = (unsigned char)(size >> 24);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd_read, header, 40);
}

void	fill_color(t_all *all, int fd_read)
{
	char	*img;
	int		i;

	i = all->win.screen_h;
	img = all->win.addr;
	while (--i)
		img += all->win.line_l;
	while (i < all->win.screen_h)
	{
		write(fd_read, img, all->win.screen_w * 4);
		img -= all->win.line_l;
		i++;
	}
}
