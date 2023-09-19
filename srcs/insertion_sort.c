/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:24:44 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/19 09:45:01 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(int number_count, t_cd_list **stack_a, t_cd_list **stack_b)
{
	int	i;
	int	j;
	t_cd_list *tmp;

	i = 1;
	push_x2y(stack_a, stack_b,B);
	while (i < number_count)
	{
		tmp = (*stack_b);
		j = 0;
		while (j < i)
		{
			if(*stack_a != NULL )
			{
				if((*stack_b) == tmp && (*stack_b)->content < (*stack_a)->content) //max case
				{
					push_x2y(stack_a, stack_b, B);
					ft_rb(stack_b);
					ft_rb(stack_b);
					break;
				}
				else if((*stack_b)->next == tmp && (*stack_b)->content > (*stack_a)->content) //min case
				{
					ft_rb(stack_b);
					push_x2y(stack_a, stack_b, B);
					ft_rb(stack_b);
					break;
				}
				else if ((*stack_b)->content < (*stack_a)->content && (*stack_b)->prev->content >(*stack_a)->content)
				{
					push_x2y(stack_a, stack_b, B);
					ft_rb(stack_b);
					ft_rb(stack_b);
					break ;
				}
			}
			ft_rb(stack_b);
			j++;
		}
		while (j++ < i - 1)
			ft_rb(stack_b);
		i++;
	}
	i = 0;
}

