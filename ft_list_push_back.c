/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:10:51 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/22 15:12:12 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		ft_list_push_back(t_list **list, void *content)
{
	t_list	*temp;
	t_list	*new;

	temp = *list;
	if (temp == NULL)
	{
		if (!(*list = ft_create_elem(content)))
			return (-1);
		else
			return (0);
	}
	if (!(new = ft_create_elem(content)))
		return (-1);
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	return (1);
}
