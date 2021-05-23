/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_to_tx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:28:32 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 15:49:45 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_path_no(char *line, t_all *all)
{
	char	**tab;
	int		i;

	i = 0;
	if (line[(int)ft_strlen(line) - 1] == ' ')
		errors_table_7(2);
	if (ft_strncmp("NO ", line, 3) != 0)
		errors_table_6(2);
	if (!(tab = ft_split(line, ' ')))
		errors_table_10(1);
	while (tab[i])
		i++;
	if (i != 2)
		errors_table_7(2);
	all->check.no++;
	all->tx.path_no = ft_strdup(tab[1]);
	all->check.id_count++;
	while (tab[--i])
		free(tab[i]);
	free(tab);
}

void	parse_path_so(char *line, t_all *all)
{
	char	**tab;
	int		i;

	i = 0;
	if (line[(int)ft_strlen(line) - 1] == ' ')
		errors_table_7(3);
	if (ft_strncmp("SO ", line, 3) != 0)
		errors_table_6(3);
	if (!(tab = ft_split(line, ' ')))
		errors_table_10(1);
	while (tab[i])
		i++;
	if (i != 2)
		errors_table_7(3);
	all->check.so++;
	all->tx.path_so = ft_strdup(tab[1]);
	all->check.id_count++;
	while (tab[--i])
		free(tab[i]);
	free(tab);
}

void	parse_path_we(char *line, t_all *all)
{
	char	**tab;
	int		i;

	i = 0;
	if (line[(int)ft_strlen(line) - 1] == ' ')
		errors_table_7(4);
	if (ft_strncmp("WE ", line, 3) != 0)
		errors_table_6(4);
	if (!(tab = ft_split(line, ' ')))
		errors_table_10(1);
	while (tab[i])
		i++;
	if (i != 2)
		errors_table_7(4);
	all->check.we++;
	all->tx.path_we = ft_strdup(tab[1]);
	all->check.id_count++;
	while (tab[--i])
		free(tab[i]);
	free(tab);
}

void	parse_path_ea(char *line, t_all *all)
{
	char	**tab;
	int		i;

	i = 0;
	if (line[(int)ft_strlen(line) - 1] == ' ')
		errors_table_8(1);
	if (ft_strncmp("EA ", line, 3) != 0)
		errors_table_7(1);
	if (!(tab = ft_split(line, ' ')))
		errors_table_10(1);
	while (tab[i])
		i++;
	if (i != 2)
		errors_table_8(1);
	all->check.ea++;
	all->tx.path_ea = ft_strdup(tab[1]);
	all->check.id_count++;
	while (tab[--i])
		free(tab[i]);
	free(tab);
}

void	parse_path_s(char *line, t_all *all)
{
	char	**tab;
	int		i;

	i = 0;
	if (line[(int)ft_strlen(line) - 1] == ' ')
		errors_table_8(4);
	if (ft_strncmp("S ", line, 2) != 0)
		errors_table_8(4);
	all->check.s++;
	all->check.id_count++;
	if (!(tab = ft_split(line, ' ')))
		errors_table_10(1);
	while (tab[i])
		i++;
	if (i != 2)
		errors_table_8(4);
	all->sprite.path_s = ft_strdup(tab[1]);
	while (tab[--i])
		free(tab[i]);
	free(tab);
}
