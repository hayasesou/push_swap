/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_in_stack_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:12:47 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/29 14:40:41 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

//static	void	push_all_stack(int number_count, t_cd_list **stack_b,
		//t_cd_list **stack_a)
//{
	//int	i;

	//i = 0;
	//while (i < number_count)
	//{
		//push_x2y(stack_a, stack_b, B);
		//i++;
	//}
//}

static	t_cd_list	*get_position2insert(t_cd_list **stack_b,
		t_cd_list **stack_a, int *spot, int i)
{
	int	distance;

	*spot = 0;
	while (*spot < i && (*stack_b)->content < (*stack_a)->content)
	{
		(*stack_a) = (*stack_a)->next;
		(*spot)++;
	}
	distance = *spot;
	while (distance-- > 0)
	(*stack_a) = (*stack_a)->prev;
	return (*stack_a);
}


static void	from_top(int spot, t_cd_list **stack_b,
		t_cd_list **stack_a, t_cd_list *tmp)
{
	int	j;

	j = -1;
	while (++j < spot)
		ft_ra(stack_a);
	push_x2y(stack_b, stack_a, A);
	if (spot != 1)
		ft_rra(stack_a);
	while (j-- > 0)
		ft_rra(stack_a);
	if (*stack_a != tmp)
		ft_ra(stack_a);
}

static void	from_botom(int spot, int i, t_cd_list **stack_b,
		t_cd_list **stack_a)
{
	int	j;

	j = -1;
	while (++j < i - spot)
		ft_rra(stack_a);
	push_x2y(stack_b, stack_a, A);
	ft_ra(stack_a);
	while (j-- > 0)
		ft_ra(stack_a);
}

static	void	find_first_not_top3(int number_count,
		t_cd_list **stack_b, t_cd_list **stack_a)
{
	ft_rb(stack_b);
	while ((*stack_b)->content >= number_count -3)
		ft_rb(stack_b);
	push_x2y(stack_b, stack_a, A);
}

void	stack_b_insertion_sort(int number_count, t_cd_list **stack_b,
			t_cd_list **stack_a)
{
	int			i;
	int			j;
	int			spot;
	t_cd_list	*tmp;

	i = 0;
	if ((*stack_b)->content < number_count - 3)
		push_x2y(stack_b, stack_a, A);
	else
		find_first_not_top3(number_count, stack_b, stack_a);
	while (++i < number_count - 3)
	{
		while ((*stack_b)->content >= number_count - 3)
			ft_rb(stack_b);
		tmp = get_position2insert(stack_b, stack_a, &spot, i);
		j = -1;
		if (spot == 0)
			push_x2y(stack_b, stack_a, A);
		else if (spot < (i - 1) / 2)
			from_top(spot, stack_b, stack_a, tmp);
		else
			from_botom(spot, i, stack_b, stack_a);
	}
	stack_b_sort_3number(stack_b);
	//push_all_stack(number_count -2, stack_b, stack_a);
}
