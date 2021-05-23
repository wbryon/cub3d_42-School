/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:29:08 by wbryon            #+#    #+#             */
/*   Updated: 2020/12/21 18:06:56 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		char_count(long long number)
{
	int i;

	i = 0;
	if (number == 0)
	{
		i++;
		return (i);
	}
	else if (number < 0)
	{
		i++;
		number = -number;
	}
	while (number > 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

static	void	reverse_str(char *s, long long sign, int x)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	if (sign < 0)
	{
		s[x++] = '-';
		s[x] = '\0';
	}
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

char			*ft_itoa(long long n)
{
	int			i;
	long long	sign;
	char		*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * (char_count(n) + 1))))
		return (NULL);
	if (n == 0)
		str[i++] = '0';
	if ((sign = n) < 0)
		n = -n;
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = '\0';
	reverse_str(str, sign, i);
	return (str);
}
