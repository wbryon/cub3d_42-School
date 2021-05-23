/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 01:42:25 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/22 20:34:55 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	errors_table_1(int error_nb)
{
	if (error_nb == 1)
	{
		ft_putstr_fd("Error\nnot valid identifiers\n", 1);
		exit(-1);
	}
	if (error_nb == 2)
	{
		ft_putstr_fd("Error\nwrong identifier R\n", 1);
		exit(-1);
	}
	if (error_nb == 3)
	{
		ft_putstr_fd("Error\ncannot read argument WIDTH\n", 1);
		exit(-1);
	}
	if (error_nb == 4)
	{
		ft_putstr_fd("Error\ncannot read argument HEIGHT\n", 1);
		exit(-1);
	}
}

void	errors_table_2(int error_nb)
{
	if (error_nb == 1)
	{
		ft_putstr_fd("Error\nnot valid map\n", 1);
		exit(-1);
	}
	if (error_nb == 2)
	{
		ft_putstr_fd("Error\nwrong character in map\n", 1);
		exit(-1);
	}
	if (error_nb == 3)
	{
		ft_putstr_fd("Error\nwrong end of line CEIL\n", 1);
		exit(-1);
	}
	if (error_nb == 4)
	{
		ft_putstr_fd("Error\nwrong end of line FLOOR\n", 1);
		exit(-1);
	}
}

void	errors_table_3(int error_nb)
{
	if (error_nb == 1)
	{
		ft_putstr_fd("Error\nDuplicate identifier CEIL\n", 1);
		exit(-1);
	}
	if (error_nb == 2)
	{
		ft_putstr_fd("Error\nDuplicate identifier FLOOR\n", 1);
		exit(-1);
	}
	if (error_nb == 3)
	{
		ft_putstr_fd("Error\nmust have three colors only\n", 1);
		exit(-1);
	}
	if (error_nb == 4)
	{
		ft_putstr_fd("Error\nToo much identifiers\n", 1);
		exit(-1);
	}
}

void	errors_table_4(int error_nb)
{
	if (error_nb == 1)
	{
		ft_putstr_fd("Error\ncannot read red color of FLOOR\n", 1);
		exit(-1);
	}
	if (error_nb == 2)
	{
		ft_putstr_fd("Error\ncannot read green color of FLOOR\n", 1);
		exit(-1);
	}
	if (error_nb == 3)
	{
		ft_putstr_fd("Error\ncannot read blue color of FLOOR\n", 1);
		exit(-1);
	}
	if (error_nb == 4)
	{
		ft_putstr_fd("Error\nUnknown argument\n", 1);
		exit(-1);
	}
}

void	errors_table_5(int error_nb)
{
	if (error_nb == 1)
	{
		ft_putstr_fd("Error\ncannot read red color of CEIL\n", 1);
		exit(-1);
	}
	if (error_nb == 2)
	{
		ft_putstr_fd("Error\ncannot read green color of CEIL\n", 1);
		exit(-1);
	}
	if (error_nb == 3)
	{
		ft_putstr_fd("Error\ncannot read blue color of CEIL\n", 1);
		exit(-1);
	}
	if (error_nb == 4)
	{
		ft_putstr_fd("Error\nTry to use another map\n", 1);
		exit(-1);
	}
}
