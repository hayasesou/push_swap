/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:30:44 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/13 00:30:13 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_up(t_cd_list **list)
{
	(*list) = (*list)->next;
}

void	rr(t_cd_list **x, t_cd_list **y)
{
	shift_up(x);
	shift_up(y);
}


//void	func(t_ints_info *inf,int num)
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

//void output(int i, t_cd_list **list)
//{
	//int count;
	//count = 0;
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
	//t_ints_info	int_info1, int_info2;

	//func(&int_info1, 1000);
	//list = make_circular_doubly(&int_info1);
	//func(&int_info2, 1);
	//y = make_circular_doubly(&int_info2);

	////printf("[%d]\n", list->content);
	////shift_up(&list);
	////printf("[%d]\n", list->content);
	////output(1000,&list);
	//push_x2y(&list, &y);
	////shift_up(&y);
	//rr(&list,&y);
	//output(2,&y);
	//output(999,&list);
	//return (0);
//}
