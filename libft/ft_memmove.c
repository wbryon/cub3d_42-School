/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:27:21 by wbryon            #+#    #+#             */
/*   Updated: 2020/11/10 19:43:44 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_dst;
	char	*last_dst;
	char	*ptr_src;
	char	*last_src;

	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	if (ptr_dst == 0 && ptr_src == 0)
		return (0);
	if (ptr_dst <= ptr_src)
	{
		while (len > 0)
		{
			*ptr_dst++ = *ptr_src++;
			len--;
		}
	}
	else
	{
		last_src = ptr_src + (len - 1);
		last_dst = ptr_dst + (len - 1);
		while (len--)
			*last_dst-- = *last_src--;
	}
	return (dst);
}
