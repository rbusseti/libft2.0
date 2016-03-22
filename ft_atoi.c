/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:29:10 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/22 12:29:13 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_atoi(char const *str, int i, int n)
{
	int		j;

	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (j != 0)
			n = n * 10;
		n = n + (str[i] - '0');
		i++;
		j++;
	}
	return (n);
}

int			ft_atoi(char const *str)
{
	int		i;
	int		min;
	int		n;

	i = 0;
	min = 1;
	n = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		min = -1;
	}
	n = calc_atoi(str, i, n);
	if (n == 0)
		return (0);
	else
		return (n * min);
}
