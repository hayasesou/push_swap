
#include "push_swap.h"

t_cd_list	*make_circular_doubly(t_ints_info *info)
{
	t_cd_list	*list;
	t_cd_list	*new;
	t_cd_list	*tmp;
	int			i;

	i = 0;
	list = new_doubly ();
	if ((info->number) != NULL)
		list->content = *(info->number);
	tmp = list;
	(info->number)++;
	while (i < (info->av_num) - 1)
	{
		new = new_doubly();
		new->content = *(info->number);
		add_front_doubly(&list, new);
		(info->number)++;
		i++;
	}

	tmp->next = list;
	list->prev = tmp;
	return (list);
}

//int main	(void)
//{
	//t_cd_list	*list;
	//int			*tmp;
	//int			count;
	//t_ints_info	int_info;

	//count = 0;
	//int_info.av_num = 1000;
	//int_info.number = (int *)malloc(sizeof(int) * int_info.av_num);
	//tmp = int_info.number;
	//while (count < int_info.av_num)
	//{
		//*(int_info.number) = count;
		////printf("[%p]\n",number);
		//// printf("[%d]\n",*number);
		//count++;
		//int_info.number++;
	//}

	//int_info.number = tmp;
	////ft_printf("[%d]\n",*(int_info.number));
	//list = make_circular_doubly(&int_info);
	//int i = 0;
	////while(i < 1000)
	////{
		////ft_printf("[%d]\n", (list->content));
		////list = list->next;
		////i++;
	////}
	////i = 0 ;
	////ft_printf("\n");
	//while(i < 1000)
	//{
		//ft_printf("[%d]\n", (list->content));
		//list = list->prev;
		//i++;
	//}
	//return (0);
//}
