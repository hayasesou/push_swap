/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:27:09 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/08 02:40:12 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	check_duplicate(int num, t_ints_info *info, int index, int *tmp);

void	store_int_info(t_ints_info *info, int ac, char **av)
{
	int	*tmp;
	int	index;
	int	num;

	info->av_num = 0;
	tmp = info->number;
	index = 1;
	while (index < ac)
	{
		num = ft_atoi_push_swap(av[index]);
		*(info->number) = num;
		check_duplicate(num, info, index, tmp);
		(info->number)++;
		(info->av_num)++;
		index++;
	}
	info->number = tmp;
	coordinate_compression(info);
}

static void	check_duplicate(int num, t_ints_info *info, int index, int *tmp)
{
	int	j;
	int	duplicate;

	j = -1;
	duplicate = 0;
	info->number = tmp;
	while (++j < index - 1)
	{
		if (*(info->number) == num)
			display_error();
		info->number++;
	}
}

void	set_stack(t_lists *stack, t_ints_info *info)
{
	int	*tmp;

	tmp = info->number;
	stack->stack_a = make_circular_doubly(info);
	info->number = tmp;
	free(info->number);
}

static void	sort(int av_num, t_lists *stack)
{
	check_list_order(stack, av_num);
	if (av_num == 2)
	{
		ft_ra(stack);
		return ;
	}
	else if (av_num == 3)
	{
		stack_a_sort_3number(stack);
		return ;
	}
	else if (av_num < 10)
		stack_a_insertion_sort(av_num, (stack));
	else
		quick_sort(av_num, (stack));
}

int	main(int ac, char **av)
{
	t_lists		stack;
	t_ints_info	info;

	stack.instruction = NULL;
	stack.list_min = 0;
	if (ac == 1)
		return (1);
	info.number = (int *)malloc(sizeof(int) * (ac - 1));
	if (info.number == NULL)
		return (1);
	store_int_info(&info, ac, av);
	set_stack(&stack, &info);
	sort(info.av_num, &stack);
	optimize_instruction(&stack);
	display_instruction(&stack);
	all_free(&stack);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
// system("leaks -q push_swap");
// }