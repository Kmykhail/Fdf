/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:13:00 by kmykhail          #+#    #+#             */
/*   Updated: 2018/03/15 21:13:02 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_struct(t_dot **dot)
{
	int i;

	i = 0;
	while ((*dot)->mass && (*dot)->mass[i])
	{
		free((*dot)->mass[i]);
		(*dot)->mass[i] = NULL;
		i++;
	}
	free((*dot)->mass);
	(*dot)->mass = NULL;
}

int		ft_cnt_num(t_tool *tool)
{
	int		i;

	i = 0;
	tool->buff = ft_strsplit(LNE, ' ');
	while (tool->buff[i])
		i++;
	if (S_BUFF && (i < S_BUFF || i > S_BUFF))
	{
		ERROR += 1;
		ft_free_double(tool->buff, i);
		ARR = NULL;
		return (0);
	}
	return (i);
}

void	ft_fill_dots_2(t_dot *dot, t_tool *tool, int c, int l)
{
	int rm;

	rm = 0;
	while (l < S_BUFF)
	{
		dot->mass[c] = malloc(sizeof(struct s_dots) * 1);
		dot->mass[c]->x = l;
		dot->mass[c]->y = ITR;
		if ((rm = ft_z_color(tool, l)))
		{
			dot->mass[c]->z = ft_atoi(ARR[l]);
			dot->mass[c]->color = rm;
		}
		else
		{
			dot->mass[c]->z = ft_atoi(ARR[l]);
			dot->mass[c]->color = 0xFFFFFF;
		}
		c++;
		l++;
	}
	dot->mass[c] = NULL;
}

void	ft_fill_dots(t_dot *dot, t_tool *tool, int l)
{
	int i;

	i = 0;
	while (i < tool->s_buff)
	{
		dot->mass[i] = malloc(sizeof(struct s_dots) * 1);
		dot->mass[i]->x = i;
		dot->mass[i]->y = ITR;
		if ((l = ft_z_color(tool, i)))
		{
			dot->mass[i]->z = ft_atoi(ARR[i]);
			dot->mass[i]->color = l;
		}
		else
		{
			dot->mass[i]->z = ft_atoi(ARR[i]);
			dot->mass[i]->color = 0xFFFFFF;
		}
		dot->mass[i]->mass = NULL;
		i++;
	}
	dot->mass[i] = NULL;
}

void	ft_print_about(t_tool *tool)
{
	mlx_string_put(MLX_PTR, WIN_PTR, 780, 10, 0xFFFFFF, "POW:69");
	mlx_string_put(MLX_PTR, WIN_PTR, 1300, 10, 0xFF0000, "Move: use arrow");
	mlx_string_put(MLX_PTR, WIN_PTR, 1300, 35, 0xFF8C00, "Rotate for Y: 4, 1");
	mlx_string_put(MLX_PTR, WIN_PTR, 1300, 60, 0x00FF00, "Rotate for X: 5, 2");
	mlx_string_put(MLX_PTR, WIN_PTR, 1300, 85, 0x20B2AA, "Rotate for Z: 6, 3");
	mlx_string_put(MLX_PTR, WIN_PTR, 1300, 110, 0x87CEFA, "Zoom: +, -");
	mlx_string_put(MLX_PTR, WIN_PTR, 1300, 135, 0x1E90FF, "Depth: 7, 8");
	mlx_string_put(MLX_PTR, WIN_PTR, 1300, 160, 0xFF00FF, \
	"Default picture: Enter");
}
