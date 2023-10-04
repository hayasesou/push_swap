/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_circular_doubly.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:26:37 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/04 18:07:56 by hfukushi         ###   ########.fr       */
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
		tmp = list->next;
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
	t_cd_list	*list;
	t_cd_list	*new;
	t_cd_list	*tmp;
	int			i;

	i = 0;
	list = new_doubly();
	if (list == NULL)
		first_node_error(info);
	list->content = *(info->number);
	tmp = list;
	(info->number)++;
	while (i < (info->av_num) - 1)
	{
		new = new_doubly();
		if (new == NULL)
			malloc_error_handling(list, info, i + 1);
		new->content = *(info->number);
		add_back_doubly(&list, new);
		(info->number)++;
		i++;
	}
	tmp->prev = list;
	list->next = tmp;
	return (tmp);
}
