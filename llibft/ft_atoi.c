/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:44:42 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/29 21:40:07 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	n;
	unsigned long long	maxll;
	int					sign;

	maxll = 9223372036854775807;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\r' ||
			*str == '\f' || *str == '\n' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-' ? -1 : 1;
	n = 0;
	while (ft_isdigit((int)*str))
		if ((n = n * 10 + *str++ - '0') >
			(unsigned long long)(sign == 1 ? maxll : ~maxll))
			return (sign == 1 ? -1 : 0);
	return ((int)(n * sign));
}
