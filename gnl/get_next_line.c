/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:23:41 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 04:25:52 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	size_t		br;
	char		*ptr_to_n;
	char		*tmp;
	static char	line_remainder[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || (read(fd, buf, 0) == -1))
		return (-1);
	ptr_to_n = checker(line_remainder, line);
	while ((ptr_to_n == NULL) && (br = read(fd, buf, BUFFER_SIZE)))
	{
		buf[br] = '\0';
		if ((ptr_to_n = ft_strchr(buf, '\n')))
		{
			*ptr_to_n = '\0';
			ft_strlcpy(line_remainder, ++ptr_to_n, BUFFER_SIZE);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return ((ft_strlen(line_remainder) || br || ptr_to_n) ? 1 : 0);
}

char		*checker(char *line_remainder, char **line)
{
	char		*ptr_to_n;

	ptr_to_n = NULL;
	if (line_remainder)
		if ((ptr_to_n = ft_strchr(line_remainder, '\n')))
		{
			*ptr_to_n = '\0';
			*line = ft_strdup(line_remainder);
			ptr_to_n++;
			ft_strlcpy(line_remainder, ptr_to_n, ft_strlen(ptr_to_n) + 1);
		}
		else
		{
			*line = ft_strdup(line_remainder);
			while (*line_remainder)
				*line_remainder++ = '\0';
		}
	else
		*line = ft_strdup("");
	return (ptr_to_n);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	char *str;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (str);
}

char		*ft_strdup(const char *s1)
{
	char		*s2;
	int			len;

	len = ft_strlen(s1);
	if (!(s2 = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s2[len] = '\0';
	while (len-- != 0)
		(s2[len] = s1[len]);
	return (s2);
}
