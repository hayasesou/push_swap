/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_3number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:30:11 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/02 10:32:39 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "push_swap.h"

void	stack_a_sort_3number(t_cd_list **stack_a)
{
	int	comparison;
	int	i;
	int	tmp;

	if (stack_a == NULL)
		return ;
	i = -1;
	if ((*stack_a)->next == (*stack_a))
		return ;
	if ((*stack_a)->next->next == (*stack_a))
	{
		if((*stack_a)->content > (*stack_a)->next->content)
			ft_sa(stack_a);
		return;
	}
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
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
	else if (comparison == 0)
		return ;
	else if (comparison == 1 && (*stack_a)->content >(*stack_a)->next->content)
		ft_sa(stack_a);
	else if (comparison == 1)
		ft_rra(stack_a);
	else if (comparison == 2 && (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else
		ft_ra(stack_a);
}
