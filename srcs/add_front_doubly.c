/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:45:32 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/12 14:47:04 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	add_front_doubly(t_cd_list **list, t_cd_list *new)
{
	if (list == NULL || new == NULL)
		return ;
	new->next = (*list);
	(*list)->prev = new;
	*list = new;
}

//test add_front_circular
//int main(void)
//{
	//t_cd_list *list, *new, *second, *third, *tmp;
	//int i,j,k,l;

	//i = 2000;
	//j = 2002;
	//k = 2003;
	//l = 2004;
	//list  = new_doubly(i);
	//new = new_doubly(j);
	//second = new_doubly(k);
	//third = new_doubly(l);
	//tmp = list;

	//add_front_doubly(&list, new);
	//add_front_doubly(&list ,second);
	//add_front_doubly(&list,third);

	//while(list != NULL)
	//{
		//printf("[%d]\n",list->content);
		//list = list->next;
	//}

	//list = tmp;
	//while(list != NULL)
	//{
		//printf("[%d]\n",list->content);
		//list = list->prev;
	//}
	//return(0);
//}