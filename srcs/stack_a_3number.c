/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_3number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:30:11 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 21:40:10 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	instruction_3number(int count_grater_than_top, t_lists *stack)
{
	t_cd_list	**stack_a;

	stack_a = &(stack->stack_a);
	if (count_grater_than_top == 0
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	else if (count_grater_than_top == 0)
		return ;
	else if (count_grater_than_top == 1
		&& (*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack);
	else if (count_grater_than_top == 1)
		ft_rra(stack);
	else if (count_grater_than_top == 2
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else
		ft_ra(stack);
}

static int	count_grater(t_lists *stack)
{
	int			stack_a_top_content;
	t_cd_list	**stack_a;
	int			i;
	int			count;

	count = 0;
	i = -1;
	stack_a = &(stack->stack_a);
	stack_a_top_content = (*stack_a)->content;
	while (++i < 2)
	{
		if (stack_a_top_content > (*stack_a)->next->content)
			count++;
		(*stack_a) = (*stack_a)->next;
	}
	while (i-- > 0)
		(*stack_a) = (*stack_a)->prev;
	return (count);
}

void	stack_a_sort_3number(t_lists *stack)
{
	int			comparison;
	int			i;
	t_cd_list	**stack_a;

	stack_a = &(stack->stack_a);
	if (stack_a == NULL)
		return ;
	i = -1;
	if ((*stack_a)->next == (*stack_a))
		return ;
	if ((*stack_a)->next->next == (*stack_a))
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_sa(stack);
		return ;
	}
	comparison = count_grater(stack);
	instruction_3number(comparison, stack);
}
