/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_order.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:10:48 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 11:56:33 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	stack_a_sort_3number(t_lists *stack)
{
	int	comparison;
	int	i;
	int	tmp;
	t_cd_list **stack_a;

	stack_a = &(stack->stack_a);
	if (stack_a == NULL)
		return ;
	i = -1;
	comparison = 0;
	tmp = (*stack_a)->content;
	while (++i < 2)
	{
		if (tmp > (*stack_a)->next->content)
			comparison++;
		(*stack_a) = (*stack_a)->next;
	}
	while (i-- > 0)
		(*stack_a) = (*stack_a)->prev;
	if (comparison == 0 && (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	else if (comparison == 0)
		return ;
	else if (comparison == 1 && (*stack_a)->content >(*stack_a)->next->content)
		ft_sa(stack);
	else if (comparison == 1)
		ft_rra(stack);
	else if (comparison == 2 && (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else
		ft_ra(stack);
}

void	check_list_order(t_lists *stack, int av_num)
{
	int	i;

	i = -1;
	while (++i < av_num)
	{
		if (i != av_num -1 && stack->stack_a->content + 1 !=
			stack->stack_a->next->content)
			break ;
		stack->stack_a = stack->stack_a->next;
	}
	if (i == av_num)
		exit (0);
	while (i-- > 0)
		stack->stack_a = stack->stack_a->prev;
}
