/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:40:40 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/29 19:32:15 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	ft_move_link(t_list **to_move, t_list **new)
{
	t_list	*temp;

	temp = *to_move;
	if ((*to_move)->next)
		*to_move = (*to_move)->next;
	else if ((*to_move)->prev)
		*to_move = (*to_move)->prev;
	else
		*to_move = NULL;
	if (temp->prev)
		temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	temp->next = NULL;
	temp->prev = NULL;
	if (*new == NULL)
	{
		*new = temp;
		return ;
	}
	while ((*new)->next)
		*new = (*new)->next;
	(*new)->next = temp;
	(*new)->next->prev = (*new);
}

t_list		*ft_split_list(t_list **list, int (*ft_issplit)(t_list *link))
{
	t_list	*temp;
	t_list	*new;

	temp = *list;
	new = NULL;
	while (temp->next)
	{
		if (((*ft_issplit)(temp)) == 1)
			ft_move_link(&temp, &new);
		else
			temp = temp->next;
	}
	*list = temp;
	if (((*ft_issplit)(temp)) == 1)
		ft_move_link(&temp, &new);
	while (new && new->prev)
		new = new->prev;
	*list = temp;
	while (*list != NULL && (*list)->prev)
		(*list) = (*list)->prev;
	return (new);
}
