/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:59:17 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/13 12:22:57 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (*list) is list which you want you pop
// return value is ptr of argument pop_x
// ptr of list is next ptr of first argument
static	t_cd_list	*pop_x(t_cd_list **list)
{
	t_cd_list	*tmp;

	tmp = (*list);
	(*list) = (*list)->prev;
	(*list)->next = tmp->next;
	(*list) = (*list)->next;
	(*list)->prev = tmp->prev;
	return (tmp);
}

// you can push x
// ptr of list is x
static	void	push_x(t_cd_list **list, t_cd_list *x)
{
	x->next = (*list)->next;
	(*list) = (*list)->next;
	x->prev = (*list)->prev;
	(*list)->prev = x;
	(*list) = x->prev;
	(*list)->next = x;
	(*list) = (*list)->next;
}

//x is top of stack
//y is top of stack
//Take the first element at the top of x and put it at the top of y
void	push_x2y(t_cd_list **x, t_cd_list **y)
{
	t_cd_list	*get;

	if ( x == NULL)
		return;
	get = pop_x(x);
	push_x(y, get);
}


//int	main	(void)
//{
	//t_cd_list	*list;
	//int			*tmp;
	//int			count;
	//t_ints_info	int_info1,int_info2;

	//count = 0;
	//int_info1.av_num = 1000;
	//int_info2.av_num = 1;
	//int_info1.number = (int *)malloc(sizeof(int) * int_info1.av_num);
	//int_info2.number = (int *)malloc(sizeof(int) * int_info2.av_num);
	//tmp = int_info1.number;
	//while (count < int_info1.av_num)
	//{
		//*(int_info1.number) = count;
		//count++;
		//int_info1.number++;
	//}

	//int_info1.number = tmp;
	//list = make_circular_doubly(&int_info1);
	//int i = 0;
	//t_cd_list *y;
	//count = 0;
	//while (count < int_info2.av_num)
	//{
		//*(int_info2.number) = count;
		//count++;
	//}
	//y = make_circular_doubly(&int_info2);

	//push_x2y(&list, &y);
	////ft_printf("[%d]\n",list->content);
	//while(i< 4)
	//{
		//printf("[%d]\n",y->content);
		//y = y->next;
		//i++;
	//}

	//i = 0;
	////while(i < 1000)
	////{
		////printf("[%d]\n", (list->content));
		////list = list->prev;
		////i++;
	////}
	//ft_printf("hello\n");
	//while(i < 1000)
	//{
		//printf("[%d]\n", (list->content));
		//list = list->prev;
		//i++;
	//}
	//return (0);
//}
