/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:24:44 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/26 09:24:40 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push_case(t_cd_list **stack_a, t_cd_list **stack_b, int ca)
{
	if (ca == MAX_CASE)
	{
		push_x2y(stack_a, stack_b, B);
		ft_rb(stack_b);
		ft_rb(stack_b);
	}
	else if(ca == MIN_CASE)
	{
		ft_rb(stack_b);
		push_x2y(stack_a, stack_b, B);
		ft_rb(stack_b);
	}
	else if(ca == MIDDLE_CASE)
	{
					push_x2y(stack_a, stack_b, B);
					ft_rb(stack_b);
					ft_rb(stack_b);
	}
	return ;
}

void	insertion_sort(int number_count, t_cd_list **stack_a, t_cd_list **stack_b)
{
	int			i;
	int			j;
	t_cd_list	*tmp;
	t_cd_list	*tmp_a;

	i = 1;
	tmp_a = *stack_a;
	push_x2y(stack_a, stack_b, B);
	while (i < number_count)
	{
		tmp = (*stack_b);
		j = 0;
		while (j < i)
		{
			if (*stack_a != NULL )
			{
				if ((*stack_b) == tmp && (*stack_b)->content < (*stack_a)->content)
				{
					push_case(stack_a, stack_b, MAX_CASE);
					break ;
				}
				else if ((*stack_b)->next == tmp && (*stack_b)->content > (*stack_a)->content)
				{
					push_case(stack_a, stack_b, MIN_CASE);
					break ;
				}
				else if ((*stack_b)->content < (*stack_a)->content)
				{
					push_case(stack_a, stack_b, MIDDLE_CASE);
					break ;
				}
			}
			ft_rb(stack_b);
			j++;
		}
		if (j < (i -1) / 2)
		{
			ft_rrb(stack_b);
			ft_rrb(stack_b);
			while (j-- > 0)
				ft_rrb(stack_b);
		}
		else
		{
		while (j++< i-1)
				ft_rb(stack_b);
		}
		i++;
	}
	i = 0;
	while (i < number_count)
	{
		push_x2y(stack_b, stack_a, A);
		i++;
	}
}

