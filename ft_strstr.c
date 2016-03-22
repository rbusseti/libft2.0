/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:56:17 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/10 13:56:55 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[i] != '\0')
	{
		while (str1[i] == str2[j] && str1[i] != '\0')
		{
			i++;
			j++;
		}
		if (str2[j] == '\0')
			return ((char *)str1 + i - j);
		i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
