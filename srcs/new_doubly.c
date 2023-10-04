/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_doubly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:31:17 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/04 18:08:02 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cd_list	*new_doubly(void)
{
	t_cd_list	*list;

	list = (t_cd_list *)malloc(sizeof(t_cd_list));
	if (list == NULL)
		return (NULL);
	list->prev = NULL;
	list->next = NULL;
	return (list);
}
