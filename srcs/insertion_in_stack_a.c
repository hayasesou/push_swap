/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_in_stack_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:24:44 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/05 13:40:33 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


static void	from_top(int spot, t_lists *stack, t_cd_list *tmp)
{
	int	j;

	j = -1;
	while (++j < spot)
		ft_rb(stack);
	push_x2y(&(stack->stack_a), &(stack->stack_b), B, stack);
	if (spot != 1)
		ft_rrb(stack);
	while (j-- > 0)
		ft_rrb(stack);
	if (stack->stack_b != tmp)
		ft_rb(stack);
}

static void	from_botom(int spot, int i, t_lists *stack)
{
	int	j;

	j = -1;
	while (++j < i - spot)
		ft_rrb(stack);
	push_x2y(&(stack->stack_a), &(stack->stack_b), B, stack);
	ft_rb(stack);
	while (j-- > 0)
		ft_rb(stack);
}

static	void	find_first_not_top3(int number_count,
		t_lists *stack)
{
	ft_ra(stack);
	while (stack->stack_a->content >= number_count -3)
		ft_ra(stack);
	push_x2y(&(stack->stack_a),&(stack->stack_b), B, stack);
}

void	stack_a_insertion_sort(int number_count, t_lists *stack)
{
	int			i;
	int			j;
	int			spot;
	t_cd_list	*tmp;

	i = 0;
	if (stack->stack_a->content < number_count - 3)
		push_x2y(&(stack->stack_a), &(stack->stack_b), B, stack);
	else
		find_first_not_top3(number_count, stack);
	while (++i < number_count - 3)
	{
		while (stack->stack_a->content >= number_count - 3)
			ft_ra(stack);
		tmp = get_position2insert(&(stack->stack_a), &(stack->stack_b), &spot, i);
		j = -1;
		if (spot == 0)
			push_x2y(&(stack->stack_a), &(stack->stack_b), B, stack);
		else if (spot < (i - 1) / 2)
			from_top(spot, stack, tmp);
		else
			from_botom(spot, i, stack);
	}
	stack_a_sort_3number(stack);
	while (stack->stack_b != NULL)
		push_x2y(&(stack->stack_b), &(stack->stack_a), A, stack);
}
