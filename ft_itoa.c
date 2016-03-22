/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 13:42:42 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/14 11:45:56 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*calc_itoa(int n, int i, char *strnew)
{
	int		mod;
	long	n2;

	n2 = n;
	strnew[i] = '\0';
	if (n2 < 0)
	{
		if (n2 == -2147483648)
			n2 = 2147483648;
		else
			n2 = n2 * (-1);
		strnew[0] = '-';
	}
	while (n2 > 9)
	{
		i--;
		mod = n2 % 10;
		n2 = n2 / 10;
		strnew[i] = mod + '0';
	}
	strnew[i - 1] = n2 + '0';
	return (strnew);
}

char		*ft_itoa(int n)
{
	char	*strnew;
	int		i;
	int		nsave;
	long	n2;

	i = 1;
	nsave = n;
	n2 = n;
	if (n2 < 0)
	{
		if (n2 == -2147483648)
			n2 = 2147483648;
		else
			n2 = n2 * (-1);
		i++;
	}
	while (n2 > 9)
	{
		n2 = n2 / 10;
		i++;
	}
	if ((strnew = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	strnew = calc_itoa(nsave, i, strnew);
	return (strnew);
}
