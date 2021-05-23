/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_table_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:41:39 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 15:40:35 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	errors_table_6(int error_nb)
{
	if (error_nb == 1)
	{
		ft_putstr_fd("Error\nMap needed!\n", 1);
		exit(-1);
	}
	if (error_nb == 2)
	{
		ft_putstr_fd("Error\nWrong identifier NO\n", 1);
		exit(-1);
	}
	if (error_nb == 3)
	{
		ft_putstr_fd("Error\nWrong identifier SO\n", 1);
		exit(-1);
	}
	if (error_nb == 4)
	{
		ft_putstr_fd("Error\nWrong identifier WE\n", 1);
		exit(-1);
	}
}

void	errors_table_7(int error_nb)
{
	if (error_nb == 1)
	{
		ft_putstr_fd("Error\nWrong identifier EA\n", 1);
		exit(-1);
	}
	if (error_nb == 2)
	{
		ft_putstr_fd("Error\nWrong path NO\n", 1);
		exit(-1);
	}
	if (error_nb == 3)
	{
		ft_putstr_fd("Error\nWrong path SO\n", 1);
		exit(-1);
	}
	if (error_nb == 4)
	{
		ft_putstr_fd("Error\nWrong path WE\n", 1);
		exit(-1);
	}
}

void	errors_table_8(int error_nb)
{
	if (error_nb == 1)
	{
		ft_putstr_fd("Error\nWrong path EA\n", 1);
		exit(-1);
	}
	if (error_nb == 2)
	{
		ft_putstr_fd("Error\nWrong path C\n", 1);
		exit(-1);
	}
	if (error_nb == 3)
	{
		ft_putstr_fd("Error\nWrong path F\n", 1);
		exit(-1);
	}
	if (error_nb == 4)
	{
		ft_putstr_fd("Error\nWrong path S\n", 1);
		exit(-1);
	}
}

void	errors_table_9(int error_nb)
{
	if (error_nb == 1)
	{
		ft_putstr_fd("Error\nSeveral players found in map\n", 1);
		exit(-1);
	}
	if (error_nb == 2)
	{
		ft_putstr_fd("Error\nPlayer not found\n", 1);
		exit(-1);
	}
	if (error_nb == 3)
	{
		ft_putstr_fd("Error\nWrong path F\n", 1);
		exit(-1);
	}
	if (error_nb == 4)
	{
		ft_putstr_fd("Error\nWrong path S\n", 1);
		exit(-1);
	}
}

void	errors_table_10(int error_nb)
{
	if (error_nb == 1)
	{
		ft_putstr_fd("Error\nMemory not allocated\n", 1);
		exit(-1);
	}
}
