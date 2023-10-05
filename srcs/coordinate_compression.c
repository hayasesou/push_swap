/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:22:04 by hfukushi          #+#    #+#             */
/*   Updated: 2023/10/06 04:47:33 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	coordinate_compression(t_ints_info *info)
{
	int	*coordinate_compression;
	int	smaller_number_counts;
	int	i;
	int	j;

	coordinate_compression = (int *)malloc(sizeof(int) * (info->av_num));
	if (coordinate_compression == NULL)
	{
		free(info->number);
		exit (1);
	}
	i = -1;
	while (++i < info->av_num)
	{
		smaller_number_counts = 0;
		j = -1;
		while (++j < info->av_num)
		{
			if (info->number[i] > info->number[j])
				smaller_number_counts++;
		}
		coordinate_compression[i] = smaller_number_counts;
	}
	free(info->number);
	info->number = coordinate_compression;


	///
	FILE *fp = fopen("s.txt","a");
	if(fp == NULL){
		dprintf(2,"open error\n");
		exit (1);
	}
	fprintf(fp,"\nargument\n");
	for(int k = 0; k < info->av_num ;k++)
	fprintf(fp,"%d ",info->number[k]);
	fclose(fp);
	// exit (0);
	///

}
