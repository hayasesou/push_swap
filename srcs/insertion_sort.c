/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:24:44 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/28 12:40:20 by hfukushi         ###   ########.fr       */
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
		tmp = (*stack_b);
		spot = 0;
		while (spot < i && (*stack_a)->content < (*stack_b)->content)
		{
			(*stack_b) = (*stack_b)->next;
			spot++;
		}
		(*stack_b) = tmp;


		j = 0;
		if (spot == 0)
		{
			push_x2y(stack_a, stack_b, B);
		}
		else if (spot < (i- 1) / 2)
		{
		while (j < spot)
		{
			ft_rb(stack_b);
			j++;
		}
		push_x2y(stack_a, stack_b, B);
		if (spot != 1 && (i-1) % 2 != 0)
		ft_rrb(stack_b);
		while (j-- > 0)
			ft_rrb(stack_b);
		if (*stack_b != tmp)
			ft_rb(stack_b);
		}
		else
		{
			while (j < i - spot)
			{
				ft_rrb(stack_b);
				j++;
			}
			push_x2y(stack_a, stack_b, B);
			ft_rb(stack_b);
			while (j-- > 0)
				ft_rb(stack_b);
		}
		i++;
	}
	push_all_stack_b(number_count, stack_a, stack_b);
}
