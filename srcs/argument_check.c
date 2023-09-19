/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:01:02 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/17 11:55:59 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	check_int_overflow(int sign, long long *num, int digit);
static	void	isinvalid_argument(const char *str);
static	long	get_number(const char **str, int sign);

int	ft_atoi_push_swap(const char *str)
{
	int			sign;
	long	num;

	sign = 1;
	if (*str == '\0')
		display_error();
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	num = get_number(&str, sign);
	isinvalid_argument(str);
	return ((int)(num * sign));
}

static	long	get_number(const char **str, int sign)
{
	long long	num;

	num = 0;

	while ('0' <= **str && **str <= '9')
	{
		check_int_overflow(sign, &num, **str - '0');
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	return (num);

}

static	void	isinvalid_argument(const char *str)
{
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str != '\0')
		display_error();
	return;
}

static void	check_int_overflow(int sign, long long *num, int digit)
{
	if (*num * sign > INT_MAX / 10 || (*num * sign == INT_MAX / 10
			&& digit > INT_MAX % 10))
		display_error();
	if (*num * sign < INT_MIN / 10 || (*num * sign == INT_MIN / 10
			&& (-digit) < INT_MIN % 10))
		display_error();
	return;
}
