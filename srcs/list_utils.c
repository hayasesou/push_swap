/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:07:04 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/12 14:56:55 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cd_list *new_doubly(int content)
{
    t_cd_list *list;

    list = (t_cd_list *)malloc(sizeof(t_cd_list));
    if (list == NULL)
        return(NULL);
    list->content = content;
    list->prev = NULL;
    list->next = NULL;
    return (list);
}

//test new_circular_dpoubly

//int main(void)
//{
   //t_cd_list *list, *new;
    //int i = 1000000;
    //int j = 9999999;
    //list = new_doubly(i);
    //printf("%d\n", list->content);
    //new = new_doubly(j);
    //printf("%d\n",new->content);

    //return(0);
//}

