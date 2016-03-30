/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:25:58 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/23 14:29:06 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_link(t_list **link1, t_list **link2)
{
	void	*temp;

	temp = (*link1)->content;
	(*link1)->content = (*link2)->content;
	(*link2)->content = temp;
}
