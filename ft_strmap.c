/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 00:51:35 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/10 14:39:55 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*strnew;

	i = 0;
	j = ft_strlen(s);
	if ((strnew = malloc(sizeof(char) * (j + 1))) == NULL)
		return (NULL);
	while (i < j)
	{
		strnew[i] = (*f)(s[i]);
		i++;
	}
	strnew[i] = '\0';
	return (strnew);
}
