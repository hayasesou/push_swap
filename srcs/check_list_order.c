/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_order.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:10:48 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/07 18:52:35 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_list_order(t_lists *stack, int av_num)
{
	int	i;

	i = -1;
	while (++i < av_num)
	{
		if (i != av_num - 1 && stack->stack_a->content
			+ 1 != stack->stack_a->next->content)
			break ;
		stack->stack_a = stack->stack_a->next;
	}
	if (i == av_num)
		exit(0);
	while (i-- > 0)
		stack->stack_a = stack->stack_a->prev;
}
