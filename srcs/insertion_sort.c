/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:24:44 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/19 16:56:09 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(int number_count, t_cd_list **stack_a, t_cd_list **stack_b)
{
	int	i;
	int	j;
	t_cd_list *tmp;
	t_cd_list *tmp_a;

	i = 1;
	tmp_a = *stack_a;
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
				else if ((*stack_b)->content < (*stack_a)->content)
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
		if( j < (i -1)/ 2)
		{
			ft_rrb(stack_b);
			ft_rrb(stack_b);
			while (j-- > 0)
				ft_rrb(stack_b);
		}
		else
		{
		while (j++ < i - 1)
			ft_rb(stack_b);
		}
		i++;
	}
	i = 0;
	*stack_a = tmp_a;
	//while( i++ < number_count)
		//push_x2y(stack_b, stack_a, A);
}

