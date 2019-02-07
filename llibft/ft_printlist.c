/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:03:53 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/29 21:13:36 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlist(t_list *list)
{
	char	*str;
	size_t	size;

	while (list)
	{
		size = list->content_size;
		str = (char*)(list->content);
		while (size--)
			ft_putchar(*str++);
		ft_putchar('\n');
		list = list->next;
	}
}
