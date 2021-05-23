/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:04:29 by wbryon            #+#    #+#             */
/*   Updated: 2020/11/10 19:42:18 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *ptr1;
	char *ptr2;

	ptr1 = (char *)dst;
	ptr2 = (char *)src;
	if (ptr1 == 0 && ptr2 == 0)
		return (0);
	else
	{
		while (n > 0)
		{
			ptr1[n - 1] = ptr2[n - 1];
			n--;
		}
	}
	return (dst);
}
