/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:08:46 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/16 23:10:45 by hfukushi         ###   ########.fr       */
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

static void	set_ptr(t_cd_list **list, t_cd_list *place, t_cd_list *ptr,
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


void	ft_ss(t_cd_list **x, t_cd_list **y)
{
	swap_top_2(x);
	swap_top_2(y);
}


//static void	func(t_ints_info *inf, int num)
//{
	//int			*tmp;
	//int count = 0;
	//inf->av_num = num;
	//inf->number = (int *)malloc(sizeof(int) * inf->av_num);
	//tmp = inf->number;
	//while (count < inf->av_num)
	//{
		//*tmp = count;
		//count++;
		//tmp++;
	//}
//}

//static void output(int i, t_cd_list **list)
//{
	//int count;
	//count = 0;

	//if (*list == NULL)
		//return ;
	//while (count < i)
	//{
		//ft_printf("[%d]\n",(*list)->content);
		//(*list) = (*list)->next;
		//count++;
	//}
//}

//int	main	(void)
//{
	//t_cd_list	*list;
	//t_cd_list	*y;
	//t_cd_list	*z;
	//t_ints_info	int_info1, int_info2;

	//func(&int_info1, 1000);
	//list = make_circular_doubly(&int_info1);
	//func(&int_info2, 1);
	//y = make_circular_doubly(&int_info2);

	//swap_top_2(&z);
	//push_x2y(&list,&z);
	//push_x2y(&list,&z);
	////push_x2y(&list,&z);
	////push_x2y(&list,&z);
	//push_x2y(&z,&list);
	////swap_top_2(&y);
	////ft_ss(&list, &z);
	//ft_rr(&list,&z);
	//ft_rrr(&list,&z);
	//output(2,&z);
	////output(2,&y);
	//ft_printf("\n");
	//output(1000,&list);
	//return (0);
//}
