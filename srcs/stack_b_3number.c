/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_3number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:44:10 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 19:54:28 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	stack_b_sort_3number(t_lists *stack)
{
	int	comparison;
	int	i;
	int	tmp;
	t_cd_list **stack_b;

	stack_b = &(stack->stack_b);
	if (stack_b == NULL)
		return ;
	i = -1;
	if ((*stack_b)->next == (*stack_b))
		return ;
	if ((*stack_b)->next->next == (*stack_b))
	{
		if((*stack_b)->content > (*stack_b)->next->content)
			ft_sb(stack);
		return;
	}
	comparison = 0;
	tmp = (*stack_b)->content;
	while (++i < 2)
	{
		if (tmp > (*stack_b)->next->content)
			comparison++;
		(*stack_b) = (*stack_b)->next;
	}
	while (i-- > 0)
		(*stack_b) = (*stack_b)->prev;

	if (comparison == 0 && (*stack_b)->next->content > (*stack_b)->next->next->content)
	{
		ft_rrb(stack);
		ft_sb(stack);
	}
	else if (comparison == 0)
		return ;
	else if (comparison == 1 && (*stack_b)->content >(*stack_b)->next->content)
		ft_sb(stack);
	else if (comparison == 1)
		ft_rrb(stack);
	else if (comparison == 2 && (*stack_b)->next->content > (*stack_b)->next->next->content)
	{
		ft_sb(stack);
		ft_rrb(stack);
	}
	else
		ft_rb(stack);
}
