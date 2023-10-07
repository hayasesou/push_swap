/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:08:46 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/08 02:27:15 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	make_tmp_lists(t_cd_list *current, t_cd_list *second,
		t_cd_list **list)
{
	current->next = (*list)->next;
	current->prev = (*list)->prev;
	(*list) = (*list)->next;
	second->next = (*list)->next;
	second->prev = (*list)->prev;
	(*list) = (*list)->prev;
}

static	void	set_ptr(t_cd_list **list, t_cd_list *place, t_cd_list *ptr,
		int direction)
{
	(*list) = place;
	if (direction == NEXT)
		(*list)->next = ptr;
	else if (direction == PREV)
		(*list)->prev = ptr;
}

void	swap_top_2(t_cd_list **list)
{
	t_cd_list	current;
	t_cd_list	second;

	if (*list == NULL || (*list)->next == (*list))
		return ;
	make_tmp_lists(&current, &second, list);
	set_ptr(list, current.prev, current.next, NEXT);
	set_ptr(list, current.next, second.prev, NEXT);
	set_ptr(list, second.prev, second.next, NEXT);
	set_ptr(list, current.next, current.prev, PREV);
	set_ptr(list, second.prev, current.next, PREV);
	set_ptr(list, second.next, second.prev, PREV);
	(*list) = current.next;
}
