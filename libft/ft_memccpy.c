/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:47:45 by wbryon            #+#    #+#             */
/*   Updated: 2020/11/10 19:43:13 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *ptr_dst;
	unsigned char *ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (ptr_dst == 0 && ptr_src == 0)
		return (0);
	while (n > 0)
	{
		if (*ptr_src != (unsigned char)c)
			*ptr_dst++ = *ptr_src++;
		else
		{
			*ptr_dst++ = *ptr_src++;
			return (ptr_dst);
		}
		n--;
	}
	return (0);
}
