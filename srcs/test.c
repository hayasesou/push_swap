/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:59:29 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/29 15:54:48 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static	void	find_first_not_top3(int number_count,
		t_cd_list **stack_b, t_cd_list **stack_a)
{
	ft_rb(stack_b);
	while ((*stack_b)->content >= number_count -3)
		ft_rb(stack_b);
	push_x2y(stack_b, stack_a, A);
}

static	insrtion_sort(int number_count, t_cd_list **stack_b, t_cd_list **stack_a)
{
	int			i;
	int			up;
	int			down;
	t_cd_list	*tmp;

	i = 0;
	if ((*stack_b)->content < number_count - 3)
	{
		push_x2y(stack_b, stack_a, A);
	}
	else
		find_first_not_top3(number_count, stack_b, stack_a);
	while (++i < number_count - 3)
	{
		while ((*stack_b)->content >= number_count - 3)
			ft_rb(stack_b);
		tmp = (*stack_a);
	}
}