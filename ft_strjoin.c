/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:58:38 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/11 20:32:09 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*strnew;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	j = i + j;
	if ((strnew = malloc(sizeof(char) * (j + 1))) == NULL)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
	{
		strnew[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		strnew[j] = s2[i];
		i++;
		j++;
	}
	strnew[j] = '\0';
	return (strnew);
}
