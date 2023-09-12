/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:08:46 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/12 15:20:02 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_2(t_cd_list **list)
{
	t_cd_list	*tmp;

	tmp = new_doubly(1);
	tmp->prev = (*list)->prev;
	(*list)->prev = (*list)->next;
	(*list) = (*list)->next;//3
	tmp->next = (*list)->next;
	(*list)->prev = tmp->prev;
	(*list) = (*list)->prev->next;      //2
	(*list)->next = tmp->next;
	(*list) = (*list)->next; //4
	tmp->next = (*list)->prev;
	(*list) = (*list)->prev->prev; //1
	tmp->prev = (*list)->next;
	(*list)->next = tmp->next;
	(*list) = (*list)->next; //3
	(*list)->next = tmp->prev;
	(*list) = (*list)->next->next;//4
	(*list)->prev = tmp->prev;
	(*list) = (*list)->prev->prev;//2
	free(tmp);
}


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
		////printf("[%p]\n",number);
		//// printf("[%d]\n",*number);
		//count++;
		//int_info.number++;
	//}

	//int_info.number = tmp;
	//list = make_circular_doubly(&int_info);
	//swap_top_2(&list);
	//int i = 0;
	//while(i < 1000)
	//{
		//printf("[%d]\n", (list->content));
		//list = list->next;
		//i++;
	//}
	//ft_printf("hello\n");
    //i = 0;
	////while(i < 1000)
	////{
		////printf("[%d]\n", (list->content));
		////list = list->prev;
		////i++;
	////}
	//return (0);
//}
