/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:03:35 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/24 16:56:26 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H

# define LIST_H

# include <string.h>

typedef struct		s_list
{
	struct s_list	*prev;
	struct s_list	*next;
	void			*content;
}					t_list;

t_list				*ft_create_elem(void *content);
int					ft_list_push_back(t_list **list, void *content);
void				ft_delete_link(t_list **list);
void				ft_swap_link(t_list **link, t_list **link2);
void				ft_bubble_sort_list(t_list **list, \
										int (*ft_compare)(t_list *, t_list *));
t_list				*ft_split_list(t_list **list, \
									int (*ft_issplit)(t_list *link));
#endif
