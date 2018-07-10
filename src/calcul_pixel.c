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

void	ft_rotate(t_dot *dot, t_dot *new, t_tool *tool, int i)
{
	int x;
	int y;
	int z;
	int axle_x;

	new->mass[i]->x = C_X * (tool->str_x + ZOOM);
	new->mass[i]->y = C_Y * (tool->str_x + ZOOM);
	new->mass[i]->z = C_Z * tool->str_x;
	new->mass[i]->z *= DEPTH;
	new->mass[i]->color = dot->mass[i]->color;
	x = new->mass[i]->x;
	y = new->mass[i]->y;
	z = new->mass[i]->z;
	new->mass[i]->y = ((new->mass[i]->y * COS_X) + (new->mass[i]->z * SIN_X));
	new->mass[i]->z = ((new->mass[i]->z * COS_X) - (new->mass[i]->y * SIN_X));
	axle_x = ((x * COS_Y) - (z * SIN_Y));
	new->mass[i]->z = ((new->mass[i]->z * COS_Y) + (x * SIN_Y));
	new->mass[i]->x = ((axle_x * COS_Z) + (new->mass[i]->y * SIN_Z));
	new->mass[i]->y = ((new->mass[i]->y * COS_Z) - (axle_x * SIN_Z));
}

void	ft_brezenhem(t_dot *new, t_tool *tool, int s, int e)
{
	RX = new->mass[s]->x;
	RY = new->mass[s]->y;
	tool->dx = ft_abs(new->mass[s]->x - new->mass[e]->x);
	tool->dy = -ft_abs(new->mass[s]->y - new->mass[e]->y);
	tool->sx = (new->mass[s]->x < new->mass[e]->x) ? 1 : -1;
	tool->sy = (new->mass[s]->y < new->mass[e]->y) ? 1 : -1;
	FAULT = tool->dx + tool->dy;
	while (69)
	{
		mlx_pixel_put(MLX_PTR, WIN_PTR, RX, RY, new->mass[e]->color);
		if (RX == new->mass[e]->x && RY == new->mass[e]->y)
			break ;
		F2 = 2 * FAULT;
		if (F2 >= tool->dy)
		{
			RX += tool->sx;
			FAULT += tool->dy;
		}
		if (F2 <= tool->dx)
		{
			RY += tool->sy;
			FAULT += tool->dx;
		}
	}
}

void	ft_draw_line(t_dot *new, t_tool *tool)
{
	int i;

	i = 0;
	while (i < tool->s_dot)
	{
		if (i + 1 < tool->s_dot && (i + 1) % S_BUFF)
			ft_brezenhem(new, tool, i, i + 1);
		if (i + S_BUFF < tool->s_dot)
			ft_brezenhem(new, tool, i, S_BUFF + i);
		else
			mlx_pixel_put(MLX_PTR, WIN_PTR, new->mass[i]->x, \
			new->mass[i]->y, new->mass[i]->color);
		i++;
	}
}

void	ft_cos_sin(t_tool *tool)
{
	COS_X = cos(tool->ang_x * M_PI / 180);
	COS_Y = cos(tool->ang_y * M_PI / 180);
	COS_Z = cos(tool->ang_z * M_PI / 180);
	SIN_X = sin(tool->ang_x * M_PI / 180);
	SIN_Y = sin(tool->ang_y * M_PI / 180);
	SIN_Z = sin(tool->ang_z * M_PI / 180);
}

void	ft_calcul_pixel(t_dot *dot, t_tool *tool)
{
	int		i;
	int		prx;
	int		pry;
	t_dot	*new;

	i = 0;
	ft_cos_sin(tool);
	prx = (S_BUFF / 2) * tool->str_x;
	pry = (ITR / 2) * tool->str_x;
	new = (t_dot*)malloc(sizeof(t_dot));
	new->mass = (struct s_dots**)malloc(sizeof(struct s_dots*) * \
	(tool->s_dot + 1));
	while (dot->mass && dot->mass[i])
	{
		new->mass[i] = malloc(sizeof(t_dot));
		ft_rotate(dot, new, tool, i);
		new->mass[i]->x = (new->mass[i]->x + 850 - prx) + MVX;
		new->mass[i]->y = (new->mass[i]->y + 500 - pry) + MVY;
		i++;
	}
	new->mass[i] = NULL;
	tool->cp_new = new;
	ft_draw_line(new, tool);
	ft_bind_key(tool);
	mlx_loop(MLX_PTR);
}
