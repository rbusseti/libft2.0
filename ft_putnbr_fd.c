/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:36:57 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/14 11:55:37 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	long	n2;

	n2 = n;
	if (n2 < 0)
	{
		ft_putchar_fd('-', fd);
		if (n2 == -2147483648)
			n2 = 2147483648;
		else
			n2 = n2 * (-1);
	}
	i = n2 % 10;
	if (n2 < 10)
		ft_putchar_fd(i + '0', fd);
	else
	{
		n2 = n2 / 10;
		ft_putnbr_fd(n2, fd);
		ft_putchar_fd(i + '0', fd);
	}
}
