/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:22:53 by kmykhail          #+#    #+#             */
/*   Updated: 2017/10/25 16:22:56 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_double(char **arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == NULL)
			break ;
		ft_strdel(&arr[i++]);
	}
	free(arr);
	arr = NULL;
}
