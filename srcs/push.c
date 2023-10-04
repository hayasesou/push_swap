/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:59:17 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/04 23:21:56 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (*list) is list which you want you pop
// return value is ptr of argument of pop_x
// ptr of list is next ptr of first argument
static t_cd_list	*pop_x(t_cd_list **list)
{
	t_cd_list	*tmp;

	if (*list == NULL)
		return (NULL);
	tmp = (*list);
	if (*list == (*list)->next)
	{
		*list = NULL;
		return (tmp);
	}
	(*list) = (*list)->prev;
	(*list)->next = tmp->next;
	(*list) = (*list)->next;
	(*list)->prev = tmp->prev;
	return (tmp);
}

// you can push x
// ptr of list is x
static void	push_x(t_cd_list **list, t_cd_list *x)
{
	if (x == NULL)
		return ;
	if (*list == NULL)
	{
		(*list) = x;
		(*list)->next = x;
		(*list)->prev = x;
		return ;
	}
	x->next = (*list);
	x->prev = (*list)->prev;
	(*list)->prev = x;
	(*list) = x->prev;
	(*list)->next = x;
	(*list) = x;
}

//x is top of stack
//y is top of stack
//Take the first element at the top of x and put it at the top of y
void	push_x2y(t_cd_list **x, t_cd_list **y, int type)
{
	t_cd_list	*get;

	get = pop_x(x);
	if (get == NULL)
		return ;
	push_x(y, get);
	if (type == A)
		ft_printf("pa\n");
	if (type == B)
		ft_printf("pb\n");
}
