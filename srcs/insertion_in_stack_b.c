/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_in_stack_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:12:47 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/03 09:50:51 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <unistd.h>
//static void	from_top(int spot, t_cd_list **stack_b,
		//t_cd_list **stack_a, t_cd_list *tmp)
//{
	//int	j;

	//j = -1;
	//while (++j < spot)
		//ft_ra(stack_a);
	//push_x2y(stack_b, stack_a, A);
	//if (spot != 1)
		//ft_rra(stack_a);
	//while (j-- > 0)
		//ft_rra(stack_a);
	//if (*stack_a != tmp)
		//ft_ra(stack_a);
//}

//static	void	find_first_not_top3(t_top3number top,
		//t_cd_list **stack_b, t_cd_list **stack_a)
//{
	//ft_rb(stack_b);
	//while ((*stack_b)->content >= top.top3)
		//ft_rb(stack_b);
	//push_x2y(stack_b, stack_a, A);
//}

//static	t_cd_list	*get_position2insert(t_cd_list **stack_b,
		//t_cd_list **stack_a, int *spot, int i)
//{
	//int	distance;

	//*spot = 0;
	//while (*spot < i && (*stack_b)->content > (*stack_a)->content)
	//{
		//(*stack_a) = (*stack_a)->next;
		//(*spot)++;
	//}
	//distance = *spot;
	//while (distance-- > 0)
	//(*stack_a) = (*stack_a)->prev;
	//return (*stack_a);
//}



//void	stack_b_insertion_sort(int number_count, t_cd_list **stack_b,
			//t_cd_list **stack_a)
//{
	//int			i;
	//int			spot;
	//t_cd_list	*tmp;
	//t_top3number top;
	//int			group_id;

	//if (number_count < 4)
	//{
		//stack_b_sort_3number(stack_b);
		//return;
	//}
	//group_id = (*stack_b)->group_id;
	//i = 0;
	//top.top1 = -1;
	//top.top2 = -1;
	//top.top3 = -1;
	//while (i < number_count)
	//{
		//if (top.top1 < (*stack_b)->content)
		//{
			//top.top3 = top.top2;
			//top.top2 = top.top1;
			//top.top1 = (*stack_b)->content;
		//}
		//else if (top.top2 < (*stack_b)->content)
		//{
			//top.top3 = top.top2;
			//top.top2 = (*stack_b)->content;
		//}
		//else if (top.top3 < (*stack_b)->content)
			//top.top3 = (*stack_b)->content;
		//(*stack_b) = (*stack_b)->next;
		//i++;
	//}

	//while (i-- > 0)
		//(*stack_b) = (*stack_b)->prev;
	//if ((*stack_b)->content < top.top3)
		//push_x2y(stack_b, stack_a, A);
	//else
		//find_first_not_top3(top, stack_b, stack_a);
 	//i = 0;
	//while (++i < number_count - 2)
	//{
		//while ((*stack_b)->content >= top.top3)
		//{
			//if ((*stack_b)->next->next->next == (*stack_b))
			//{
				//stack_b_sort_3number(stack_b);
				//return ;
			//}
			//ft_rb(stack_b);
		//}
		//tmp = get_position2insert(stack_b, stack_a, &spot, i);
		//if (spot == 0)
		//{
			//push_x2y(stack_b, stack_a, A);
		//}
		//else
			//from_top(spot, stack_b, stack_a, tmp);
	//}
	//stack_b_sort_3number(stack_b);
	//while ((*stack_a)->group_id == group_id)
		//ft_ra(stack_a);
	//while ((*stack_b) != NULL)
	//{
		//push_x2y(stack_b, stack_a, A);
		//ft_ra(stack_a);
	//}
//}

static void set_disatance(t_distance *distance, t_stack_b_info *b_info, t_cd_list **stack_b)
{
	int i;
	t_cd_list *tmp;

	if (*stack_b == NULL)
		return;
	tmp = (*stack_b);
	distance->from_top = 0;
	distance->from_bottom = 0;
	i = 0;

	while(distance->from_top < b_info->node_count)
	{
		if ((*stack_b)->content == b_info->min || (*stack_b)->content == b_info->max)
		{
			distance->top_position = (*stack_b);
			break;
		}
		(*stack_b) = (*stack_b)->next;
		distance->from_top++;
	}
	(*stack_b) = tmp;
	i = 0;
	while (distance->from_bottom < b_info->node_count)
	{
		if ((*stack_b)->content == b_info->min || (*stack_b)->content == b_info->max)
		{
			distance->bottom_postion = (*stack_b);
			break;
		}
		(*stack_b) = (*stack_b)->prev;
		distance->from_bottom++;
	}
	(*stack_b) = tmp;
}

void	stack_b_insertion_sort(int number_count, t_cd_list **stack_b, t_cd_list **stack_a)
{
	t_stack_b_info b_info;
	t_distance distance;
	int i;

	b_info.max = INT_MIN;
	b_info.min = INT_MAX;
	i = -1;
	while(++i < number_count)
	{
		if ((*stack_b)->content < b_info.min)
		b_info.min = (*stack_b)->content;
		if ((*stack_b)->content > b_info.max)
		b_info.max = (*stack_b)->content;
		(*stack_b) = (*stack_b)->next;
	}

	while((*stack_b) != NULL)
	{
	b_info.node_count = number_count;
		set_disatance(&distance, &b_info, stack_b);
		if(distance.from_top <= distance.from_bottom)
		{
			while ((*stack_b) != distance.top_position)
				ft_rb(stack_b);
			if ((*stack_b)->content == b_info.min)
			{
				push_x2y(stack_b, stack_a, A);
				ft_ra(stack_a);
				b_info.min++;
				b_info.node_count--;
			}
			else
			{
				push_x2y(stack_b, stack_a, A);
				b_info.max--;
				b_info.node_count--;
			}
		}
		else
		{
			while ((*stack_b) != distance.bottom_postion)
				ft_rrb(stack_b);
			if ((*stack_b)->content == b_info.min)
			{
				push_x2y(stack_b, stack_a, A);
				ft_ra(stack_a);
				b_info.min++;
				b_info.node_count--;
			}
			else
			{
				push_x2y(stack_b, stack_a, A);
				b_info.max--;
				b_info.node_count--;
			}
		}
	}
}