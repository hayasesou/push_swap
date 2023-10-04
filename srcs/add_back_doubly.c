/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back_doubly.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:45:32 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/04 18:07:12 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back_doubly(t_cd_list **list, t_cd_list *new)
{
	if (list == NULL || new == NULL)
		return ;
	new->prev = (*list);
	(*list)->next = new;
	*list = new;
}
