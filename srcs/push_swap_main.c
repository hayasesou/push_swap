/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:27:09 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/16 11:53:03 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int			i;
	long		num;
	t_ints_info	info;

	info.number = (int *)malloc(sizeof(int) * (ac -1));
	i = 1;
	int *tmp = info.number;
	if (ac == 1)
		return (1);
	while (i < ac)
	{
		num = ft_atof(av[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_printf("Error\n");
			return (1);
		}
		//ft_printf("[%d]\n", num);
		*(info.number) = (int)num;
		(info.number)++;
		i++;
	}
	info.number = tmp;
	for(int j = 0; j < ac -1; j++)
	{
		ft_printf("[%d]\n", *(info.number));
		info.number++;
	}
	return (0);
}