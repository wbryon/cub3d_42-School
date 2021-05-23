/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:27:10 by wbryon            #+#    #+#             */
/*   Updated: 2020/12/11 14:42:58 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	len += i;
	if (!(dstsize == 0 || dstsize < ft_strlen(dst)))
	{
		while (i < (dstsize - 1) && src[0] != '\0')
		{
			dst[i] = (char)src[0];
			i++;
			src++;
		}
		dst[i] = '\0';
	}
	return (len);
}

char		*ft_strchr(const char *s, int c)
{
	char	*tmp_s;
	int		i;

	tmp_s = (char*)s;
	i = 0;
	while (tmp_s[i] != c)
	{
		if (tmp_s[i] == '\0')
			return (NULL);
		i++;
	}
	return (&tmp_s[i]);
}
