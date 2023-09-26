/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:27:09 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/25 17:54:16 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void	check_dupulicate(int num, t_ints_info *info, int index, int *tmp);

void	store_int_info(t_ints_info *info, int ac, char **av)
{
	int			*tmp;
	int			index;
	int			num;

	info->av_num = 0;
	tmp = info->number;
	index = 1;
	while (index < ac)
	{
		num = ft_atoi_push_swap(av[index]);
		*(info->number) = num;
		check_dupulicate(num, info, index, tmp);
		(info->number)++;
		(info->av_num)++;
		index++;
	}
	info->number = tmp;
}

void	check_dupulicate(int num, t_ints_info *info, int index, int *tmp)
{
	int	j;
	int	count_number;

	j = 0;
	count_number = 0;
	info->number = tmp;
	while (j < index)
	{
		if (*(info->number) == num)
			count_number++;
		info->number++;
		j++;
	}
	if (count_number >= 2)
		display_error();
	info->number -= 1;
}

void	set_stack(t_lists *stack, t_ints_info *info)
{
	int	*tmp;

	tmp = info->number;
	stack->stack_a = make_circular_doubly(info);
	info->number = tmp;
	free(info->number);
}

int	main(int	ac, char	**av)
{
	t_lists		stack;
	t_ints_info	info;

	if (ac == 1)
		return (1);
	info.number = (int *)malloc(sizeof(int) * (ac -1));
	if (info.number == NULL)
		return (1);
	store_int_info(&info, ac, av);
	set_stack(&stack, &info);
	insertion_sort(ac -1, &(stack.stack_a),&(stack.stack_b));
	ft_printf("\nstack_a\n");
	for (int i =0; i < ac -1; i++)
	{
		if (stack.stack_a == NULL)
		{
			ft_printf("No stack a\n");
			break;
		}
		ft_printf("[%d]\n",stack.stack_a->content);
		stack.stack_a = stack.stack_a->next;
	}
	ft_printf("\nstack_b\n");
	for (int i =0; i < ac -1; i++)
	{
		if (stack.stack_b == NULL)
		{
			ft_printf("No stack b\n");
			break;
		}
		ft_printf("[%d]\n",stack.stack_b->content);
		stack.stack_b = stack.stack_b->next;
	}
	//info.number = tmp;
	//if (info.number != NULL)
		//free(info.number);
	return (0);
}



//__attribute__((destructor))
//static void destructor() {
    //system("leaks -q push_swap");
//}