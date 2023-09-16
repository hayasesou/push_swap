/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:01:02 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/16 11:38:40 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	handle_overflow(int sign, long long *num, int digit);
static	long	isinvalid_argument(const char *str);
static	long	get_number(const char **str, int sign);

long	ft_atof(const char *str)
{
	int			sign;
	long long	num;

	sign = 1;
	if (*str == '\0')
		return (LONG_MAX);
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
	//ft_printf("[%c]\n",(*str));
	if (isinvalid_argument(str) == LONG_MAX)
		return (LONG_MAX);
	return ((num * sign));
}

static	long	get_number(const char **str, int sign)
{
	long long	num;

	num = 0;

	while ('0' <= **str && **str <= '9')
	{
		if (handle_overflow(sign, &num, **str - '0'))
			return (LONG_MAX);
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	return (num);
}

static	long	isinvalid_argument(const char *str)
{
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str != '\0')
		return (LONG_MAX);
	return (0);
}

static int	handle_overflow(int sign, long long *num, int digit)
{
	if (*num * sign > LONG_MAX / 10 || (*num * sign == LONG_MAX / 10
			&& digit > LONG_MAX % 10))
	{
		*num = LONG_MAX;
		return (1);
	}
	if (*num * sign < LONG_MIN / 10 || (*num * sign == LONG_MIN / 10
			&& (-digit) < LONG_MIN % 10))
	{
		*num = LONG_MIN;
		return (1);
	}
	return (0);
}
