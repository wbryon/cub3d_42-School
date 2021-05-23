/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:38:38 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 15:28:44 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_map(t_list **head, int size, t_all *all)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *head;
	all->map.map = ft_calloc(size + 1, sizeof(char *));
	while (tmp)
	{
		all->map.map[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	all->map.map[i] = NULL;
	ft_lstclear(head, &free);
}

void	read_map(char *argv, t_all *all)
{
	char	*str;
	t_list	*head;
	int		size;
	int		fd;

	str = 0;
	head = 0;
	size = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		ft_lstadd_back(&head, ft_lstnew(str));
		size++;
		str = NULL;
	}
	close(fd);
	ft_lstadd_back(&head, ft_lstnew(str));
	size++;
	return (make_map(&head, size, all));
}

int		check_chars_in_map(t_all *all)
{
	int		i;
	int		j;
	int		ret;

	i = begin_map(all) - 1;
	j = 0;
	ret = 0;
	while (++i < end_map(all) - 1)
	{
		if (all->map.map[i][0] == '\0')
		{
			ft_putstr_fd("Error\nEmpty line after map\n", 1);
			exit(-1);
		}
		ret = check_chars_joined(i, j, ret, all);
		if (ret != 0)
			errors_table_2(1);
	}
	init_player(all);
	if (all->plr.plr_count > 1)
		errors_table_9(1);
	if (all->plr.plr_count == 0)
		errors_table_9(2);
	return (ret);
}

int		check_chars_joined(int i, int j, int ret, t_all *all)
{
	while (all->map.map[i][j])
	{
		if (ft_strchr("02NSWE", all->map.map[i][0]))
			errors_table_2(1);
		if (!ft_strchr(" 012NSWE", all->map.map[i][j]))
			errors_table_2(1);
		if (all->map.map[i][j] == '0')
			ret = check_around_character(i, j, ret, all);
		if (all->map.map[i][j] == '2')
			ret = check_around_character(i, j, ret, all);
		if (all->map.map[i][j] == 'N')
			ret = check_around_character(i, j, ret, all);
		if (all->map.map[i][j] == 'S')
			ret = check_around_character(i, j, ret, all);
		if (all->map.map[i][j] == 'W')
			ret = check_around_character(i, j, ret, all);
		if (all->map.map[i][j] == 'E')
			ret = check_around_character(i, j, ret, all);
		else
			;
		j++;
	}
	return (ret);
}

int		check_around_character(int i, int j, int ret, t_all *all)
{
	int		up_line;
	int		low_line;

	up_line = (int)ft_strlen(all->map.map[i - 1]);
	low_line = (int)ft_strlen(all->map.map[i + 1]);
	if ((up_line <= j + 1) || (low_line <= j + 1))
		errors_table_2(1);
	if ((all->map.map[i][j + 1] == ' ') || (all->map.map[i][j - 1] == ' '))
		ret++;
	if ((all->map.map[i + 1][j] == ' ') || (all->map.map[i - 1][j] == ' '))
		ret++;
	if ((all->map.map[i - 1][j - 1] == ' ') ||
	(all->map.map[i + 1][j + 1] == ' '))
		ret++;
	if ((all->map.map[i + 1][j - 1] == ' ') ||
	(all->map.map[i - 1][j + 1] == ' '))
		ret++;
	return (ret);
}
