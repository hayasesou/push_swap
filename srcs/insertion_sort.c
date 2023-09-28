/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:24:44 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/28 20:51:53 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push_all_stack_b(int number_count, t_cd_list **stack_a,
		t_cd_list **stack_b)
{
	int	i;

	i = 0;
	while (i < number_count)
	{
		push_x2y(stack_b, stack_a, A);
		i++;
	}
}

static	t_cd_list	*get_position2insert(t_cd_list **stack_a,
		t_cd_list **stack_b, int *spot, int i)
{
	int	distance;

	*spot = 0;
	while (*spot < i && (*stack_a)->content < (*stack_b)->content)
	{
		(*stack_b) = (*stack_b)->next;
		(*spot)++;
	}
	distance = *spot;
	while (distance-- > 0)
	(*stack_b) = (*stack_b)->prev;
	return (*stack_b);
}


static void	from_top(int spot, t_cd_list **stack_a,
		t_cd_list **stack_b, t_cd_list *tmp)
{
	int	j;

	j = -1;
	while (++j < spot)
		ft_rb(stack_b);
	push_x2y(stack_a, stack_b, B);
	if (spot != 1)
		ft_rrb(stack_b);
	while (j-- > 0)
		ft_rrb(stack_b);
	if (*stack_b != tmp)
		ft_rb(stack_b);
}

static void	from_botom(int spot, int i, t_cd_list **stack_a,
		t_cd_list **stack_b)
{
	int	j;

	j = -1;
	while (++j < i - spot)
		ft_rrb(stack_b);
	push_x2y(stack_a, stack_b, B);
	ft_rb(stack_b);
	while (j-- > 0)
		ft_rb(stack_b);
}

//void	insertion_sort(int number_count, t_cd_list **stack_a,
		//t_cd_list **stack_b)
//{
	//int			i;
	//int			j;
	//int			spot;
	//t_cd_list	*tmp;

	//i = 1;
	//push_x2y(stack_a, stack_b, B);
	//while (i < number_count)
	//{
		//tmp = get_position2insert(stack_a, stack_b, &spot, i);
		//j = -1;
		//if (spot == 0)
			//push_x2y(stack_a, stack_b, B);
		//else if (spot < (i - 1) / 2)
			//from_top(spot, stack_a, stack_b, tmp);
		//else
			//from_botom(spot, i, stack_a, stack_b);
		//i++;
	//}
	//push_all_stack_b(number_count, stack_a, stack_b);
//}


void	insertion_sort(int number_count, t_cd_list **stack_a,
		t_cd_list **stack_b)
{
	int			i;
	int			j;
	int			spot;
	t_cd_list	*tmp;

	i = 1;
	push_x2y(stack_a, stack_b, B);
	while (i < number_count)
	{
		tmp = get_position2insert(stack_a, stack_b, &spot, i);
		j = -1;
		if (spot == 0)
			push_x2y(stack_a, stack_b, B);
		else if (spot < (i - 1) / 2)
			from_top(spot, stack_a, stack_b, tmp);
		else
			from_botom(spot, i, stack_a, stack_b);
		i++;
	}
	//sort_3number(stack_a);
	push_all_stack_b(number_count, stack_a, stack_b);
}
