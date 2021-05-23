/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:10:32 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 23:26:57 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					sign_checker(const char *str)
{
	int sign;

	sign = 1;
	if (*str == '-')
		sign = -sign;
	return (sign);
}

unsigned long long	skip_zero(unsigned long long res, const char *str)
{
	int i;
	int	zero_count;

	i = 0;
	zero_count = 0;
	if (str[0] == '0')
	{
		while (str[i] == '0' && str[i + 1] != '\0')
		{
			i++;
			zero_count++;
		}
	}
	zero_count = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
		if ((str[i] < '0' && str[i] > '9') || (i - zero_count > 7))
			return (res);
	}
	return (res);
}

int					ft_atoi(const char *str)
{
	unsigned long long	res;
	int					sign;
	int					i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = sign_checker(str);
		i++;
	}
	res = skip_zero(res, str);
	return ((int)res * sign);
}
