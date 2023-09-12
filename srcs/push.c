/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:59:17 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/12 15:18:21 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cd_list	*pop_x(t_cd_list **list)
{
	t_cd_list	*tmp;

	tmp = (*list);
	(*list) = (*list)->prev;
	(*list)->next = tmp->next;
	(*list) = (*list)->next;
	(*list)->prev = tmp->prev;
	return (tmp);
}
