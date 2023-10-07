/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_circular_doubly.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:26:37 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/08 02:43:03 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	malloc_error_handling(t_cd_list *list, t_ints_info *info,
		int created_node_num)
{
	t_cd_list	*tmp;
	int			i;

	i = 0;
	while (i < created_node_num)
	{
		tmp = list->prev;
		free(list);
		list = tmp;
		i++;
	}
	while (i > 0)
	{
		info->number--;
		i--;
	}
	free(info->number);
	exit(1);
}

static void	first_node_error(t_ints_info *info)
{
	free(info->number);
	exit(1);
}

t_cd_list	*make_circular_doubly(t_ints_info *info)
{
	t_cd_list	*current_list;
	t_cd_list	*new;
	t_cd_list	*list_top;
	int			i;

	current_list = new_doubly();
	if (current_list == NULL)
		first_node_error(info);
	current_list->content = *(info->number);
	list_top = current_list;
	(info->number)++;
	i = 0;
	while (i < (info->av_num) - 1)
	{
		new = new_doubly();
		if (new == NULL)
			malloc_error_handling(current_list, info, i + 1);
		new->content = *(info->number);
		add_back_doubly(&current_list, new);
		(info->number)++;
		i++;
	}
	list_top->prev = current_list;
	current_list->next = list_top;
	return (list_top);
}
