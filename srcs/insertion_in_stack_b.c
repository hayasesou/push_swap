/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_in_stack_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:12:47 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/30 13:12:58 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"




static void	from_top(int spot, t_cd_list **stack_b,
		t_cd_list **stack_a, t_cd_list *tmp)
{
	int	j;

	(void)tmp;
	j = -1;
	while (++j < spot)
		ft_ra(stack_a);
	push_x2y(stack_b, stack_a, A);
	//jif (spot != 1)
		//jft_rra(stack_a);
	while (j-- > 0)
		ft_rra(stack_a);
	//if (*stack_a != tmp)
	//	ft_ra(stack_a);
}

static	void	find_first_not_top3(t_top3number top,
		t_cd_list **stack_b, t_cd_list **stack_a)
{
	ft_rb(stack_b);
	while ((*stack_b)->content >= top.top3)
		ft_rb(stack_b);
	push_x2y(stack_b, stack_a, A);
}

static	t_cd_list	*get_position2insert(t_cd_list **stack_b,
		t_cd_list **stack_a, int *spot)
{
	int	distance;

	*spot = 0;
	while ((*stack_b)->content > (*stack_a)->content)
	{
		(*stack_a) = (*stack_a)->next;
		(*spot)++;
	}
	distance = *spot;
	while (distance-- > 0)
	(*stack_a) = (*stack_a)->prev;
	return (*stack_a);
}



void	stack_b_insertion_sort(int number_count, t_cd_list **stack_b,
			t_cd_list **stack_a)
{
	int			i;
	int			spot;
	t_cd_list	*tmp;
	t_top3number top;
	int			group_id;

	if (number_count < 4)
	{

		stack_b_sort_3number(stack_b);
		return;
	}
	group_id = (*stack_b)->group_id;
	i = 0;
	top.top1 = -1;
	top.top2 = -1;
	top.top3 = -1;
	while (i < number_count)
	{
		if (top.top1 < (*stack_b)->content)
		{
			top.top3 = top.top2;
			top.top2 = top.top1;
			top.top1 = (*stack_b)->content;
		}
		else if (top.top2 < (*stack_b)->content)
		{
			top.top3 = top.top2;
			top.top2 = (*stack_b)->content;
		}
		else if (top.top3 < (*stack_b)->content)
			top.top3 = (*stack_b)->content;
		(*stack_b) = (*stack_b)->next;
		i++;
	}

	while (i-- > 0)
		(*stack_b) = (*stack_b)->prev;


	// if ((*stack_b)->next == (*stack_b) || (*stack_b)->next->next == (*stack_b))
	if ((*stack_b)->content < top.top3)
		push_x2y(stack_b, stack_a, A);
	else
		find_first_not_top3(top, stack_b, stack_a);
 	i = 0;
	while (i < number_count - 3)
	{
		while ((*stack_b)->content >= top.top3)
		{
			if ((*stack_b)->next->next->next == (*stack_b))
			{
				stack_b_sort_3number(stack_b);
				return ;
			}
			ft_rb(stack_b);
		}
		tmp = get_position2insert(stack_b, stack_a, &spot);
		if (spot == 0)
		{
			push_x2y(stack_b, stack_a, A);
		}
		else
			from_top(spot, stack_b, stack_a, tmp);
		i++;
	}
	stack_b_sort_3number(stack_b);
	while ((*stack_a)->group_id == group_id)
		ft_ra(stack_a);
	while ((*stack_b) != NULL)
	{
		push_x2y(stack_b, stack_a, A);
		ft_ra(stack_a);
	}
}


//void	stack_b_insertion_sort(int number_count, t_cd_list **stack_b,
			//t_cd_list **stack_a)
//{
	//int			i;
	//int			j;
	//int			spot;
	//t_cd_list	*tmp;

	//i = 0;
	//if ((*stack_b)->content < number_count - 3)
		//push_x2y(stack_b, stack_a, A);
	//else
		//find_first_not_top3(number_count, stack_b, stack_a);
	//while (++i < number_count - 3)
	//{
		//while ((*stack_b)->content >= number_count - 3)
			//ft_rb(stack_b);
		//tmp = get_position2insert(stack_b, stack_a, &spot, i);
		//j = -1;
		//if (spot == 0)
			//push_x2y(stack_b, stack_a, A);
		//else if (spot < (i - 1) / 2)
			//from_top(spot, stack_b, stack_a, tmp);
		//else
			//from_botom(spot, i, stack_b, stack_a);
	//}
	//stack_b_sort_3number(stack_b);
	//while ((*stack_a) != NULL)
		//push_x2y(stack_a, stack_b, B);
//}
