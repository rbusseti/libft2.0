/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:20:33 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/10 14:07:35 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	if (ft_strlen((char *)s2) == 0)
		return ((char *)s1);
	i = 0;
	j = 0;
	while (s1[i] && n > 0)
	{
		while ((s1[i] == s2[j]) && (s1[i] != '\0') && n > 0)
		{
			i++;
			j++;
			n--;
		}
		if (s2[j] == '\0')
			return ((char *)(s1 + i - j));
		i = i - j + 1;
		n = n + j - 1;
		j = 0;
	}
	return (NULL);
}
