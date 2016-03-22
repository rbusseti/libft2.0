/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:03:35 by rbusseti          #+#    #+#             */
/*   Updated: 2016/03/22 15:16:24 by rbusseti         ###   ########.fr       */
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

#endif
