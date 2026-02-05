/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 08:45:04 by dlanehar          #+#    #+#             */
/*   Updated: 2026/01/26 08:34:56 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

int	ft_atoi_limit_check(const char *str, int *error)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-')
		sign = sign * -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((nb > INT_MAX && sign == 1) || (nb * sign < INT_MIN))
			break ;
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if ((nb > INT_MAX && sign == 1) || (nb * sign < INT_MIN))
	{
		nb = 0;
		*error = -2;
	}
	return (nb * sign);
}
