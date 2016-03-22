/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:11:29 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/22 15:57:05 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	ft_delete_link(t_list **list)
{
	t_list	*temp;

	temp = *list;
	free(temp->content);
	if (temp->prev)
		temp->prev->next = temp->next;
	if (temp->next)
	{
		temp->next->prev = temp->prev;
		(*list) = temp->next;
	}
	else if (temp->prev)
		(*list) = temp->prev;
	else
		*list = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	free(temp);
	temp = NULL;
}
