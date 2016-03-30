/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:43:21 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/23 17:59:38 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_browse_list(t_list **list, int *sorted, \
						int (*ft_compare)(t_list *, t_list *))
{
	t_list	*temp;

	temp = (*list)->next;
	while (temp != NULL)
	{
		if (((*ft_compare)(temp->prev, temp)) > 0)
		{
			*sorted = 0;
			ft_swap_link(&(temp->prev), &temp);
		}
		temp = temp->next;
	}
}

void		ft_bubble_sort_list(t_list **list, \
								int (*ft_compare)(t_list *, t_list *))
{
	t_list	*temp;
	int		sorted;

	sorted = 0;
	temp = *list;
	while (!sorted)
	{
		sorted = 1;
		ft_browse_list(list, &sorted, ft_compare);
	}
}
