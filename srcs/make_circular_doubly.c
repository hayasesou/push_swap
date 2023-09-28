/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_circular_doubly.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:26:37 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/27 09:28:29 by hfukushi         ###   ########.fr       */
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

//static void malloc_error(t_cd_list *list, int i)
//{

//}

//int main	(void)
//{
//t_cd_list	*list;
//int			*tmp;
//int			count;
//t_ints_info	int_info;

//count = 0;
//int_info.av_num = 1000;
//int_info.number = (int *)malloc(sizeof(int) * int_info.av_num);
//tmp = int_info.number;
//while (count < int_info.av_num)
//{
//*(int_info.number) = count;
////printf("[%p]\n",number;
//// printf("[%d]\n",*number);
//count++;
//int_info.number++;
//}

//int_info.number = tmp;
////ft_printf("[%d]\n",*(int_info.number));
//list = make_circular_doubly(&int_info);
//int i = 0;
////while(i < 1000)
////{
////ft_printf("[%d]\n", (list->content));
////list = list->next;
////i++;
////}
////i = 0 ;
////ft_printf("\n");
//while(i < 1000)
//{
//ft_printf("[%d]\n", (list->content));
//list = list->prev;
//i++;
//}
//return (0);
//}
