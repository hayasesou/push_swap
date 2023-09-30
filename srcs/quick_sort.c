/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:45:17 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/01 02:59:46 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void print_stack(t_cd_list *stack)
{
	int x = stack->content;

	dprintf(STDERR_FILENO, "[");
	do {
		dprintf(STDERR_FILENO, "%dg%d, ", stack->content, stack->group_id);
		stack = stack->next;
	} while(stack->content != x);
	dprintf(STDERR_FILENO, "]\n");
}

void	stack_b_quick_sort(int av_num, t_cd_list **stack_b, t_cd_list **stack_a, int *group_id_max)
{
	int	pivot;
	int	i;
	// int	j;
	// int	sum;
	int count_stack_b_node;
	int count_ra;
	int group_id;

	// j = -1;
	// sum = 0;
	if (av_num < 12)
	{
		stack_b_insertion_sort(av_num, stack_b, stack_a);
		print_stack(*stack_a);
		print_stack(*stack_b);
		dprintf(STDERR_FILENO, "---\n");
		if (av_num >3)
		{
			while ((*stack_a)->group_id == (*stack_a)->next->group_id)
			{
				ft_ra(stack_a);
			}
			ft_ra(stack_a);
		}
		while ((*stack_b) != NULL)
		{
			push_x2y(stack_b, stack_a, A);
			ft_ra(stack_a);
		}
		return ;
	}
	//while (++j < av_num)
	//{
		//sum += (*stack_b)->content;
		//(*stack_b) = (*stack_b)->next;
	//}
	//while (j-- > 0)
		//(*stack_b) = (*stack_b)->prev;
	//pivot = sum / av_num;
	pivot = get_pivot(av_num, stack_b);
	i = -1;
	count_stack_b_node = 0;
	while (++i < av_num)
	{
		if ((*stack_b)->content >= pivot)
		{
			(*stack_b)->group_id = *group_id_max + 1;
			push_x2y(stack_b, stack_a, A);
		}
		else
		{
			ft_rb(stack_b);
			count_stack_b_node++;
		}
	}
	group_id = *group_id_max;
	*group_id_max += 1;
	stack_b_quick_sort(count_stack_b_node, stack_b, stack_a, group_id_max);

	count_ra = 0;
	while ((*stack_a)->group_id == group_id + 1)
	{
		push_x2y(stack_a, stack_b, B);
		count_ra++;
	}
	if ((*stack_b) != NULL)
		stack_b_quick_sort(count_ra, stack_b, stack_a, group_id_max);
}


void	quick_sort(int av_num, t_cd_list **stack_a, t_cd_list **stack_b)
{
	int max;
	max = 0;
	stack_small_quick_sort(av_num, stack_a, stack_b, &max);
	stack_large_quick_sort(av_num, stack_a, stack_b, &max);
}