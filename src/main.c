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

void	ft_realloc_struct_2(t_dot *dot, t_tool *tool, t_dot *tmp, int i)
{
	int c;
	int l;

	c = 0;
	l = 0;
	while (c < i)
	{
		dot->mass[c] = malloc(sizeof(struct s_dots) * 1);
		dot->mass[c]->x = tmp->mass[c]->x;
		dot->mass[c]->y = tmp->mass[c]->y;
		dot->mass[c]->z = tmp->mass[c]->z;
		dot->mass[c]->color = tmp->mass[c]->color;
		dot->mass[c]->mass = NULL;
		c++;
	}
	ft_fill_dots_2(dot, tool, c, l);
}

void	ft_realloc_struct(t_dot *dot, t_tool *tool)
{
	t_dot	*tmp;
	int		i;
	int		c;

	i = 0;
	c = 0;
	tmp = malloc(sizeof(t_dot));
	while (dot->mass && dot->mass[i])
		i++;
	tmp->mass = (struct s_dots**)malloc(sizeof(struct s_dots*) * (i + 1));
	while (c < i)
	{
		tmp->mass[c] = (struct s_dots*)malloc(sizeof(struct s_dots) * 1);
		tmp->mass[c]->x = dot->mass[c]->x;
		tmp->mass[c]->y = dot->mass[c]->y;
		tmp->mass[c]->z = dot->mass[c]->z;
		tmp->mass[c]->color = dot->mass[c]->color;
		tmp->mass[c]->mass = NULL;
		c++;
	}
	tmp->mass[c] = NULL;
	ft_free_struct(&dot);
	dot->mass = (struct s_dots**)malloc(sizeof(struct s_dots*) * \
	(i + S_BUFF + 1));
	ft_realloc_struct_2(dot, tool, tmp, i);
	ft_free_struct(&tmp);
	free(tmp);
	tmp = NULL;
}

void	ft_add_mass(t_dot *dot, t_tool *tool)
{
	int i;
	int l;
	int c;

	i = 0;
	l = 0;
	c = 0;
	if (!(S_BUFF = ft_cnt_num(tool)))
		return ;
	if (!dot->mass)
		dot->mass = (struct s_dots**)malloc(sizeof(struct s_dots*) * \
		(tool->s_buff + 1));
	else
	{
		ft_realloc_struct(dot, tool);
		ft_free_double(tool->buff, S_BUFF);
		tool->buff = NULL;
		return ;
	}
	ft_fill_dots(dot, tool, l);
	ft_free_double(tool->buff, S_BUFF);
	tool->buff = NULL;
}

int		ft_readfile(t_dot *dot, t_tool *tool, char *file, int c)
{
	int fd;

	fd = open(file, O_RDONLY);
	while (69 && !ERROR)
	{
		if ((c = (get_next_line(fd, &LNE))) <= 0)
			break ;
		if (ft_valid_line(tool))
		{
			ft_strdel(&LNE);
			break ;
		}
		ft_add_mass(dot, tool);
		ft_strdel(&LNE);
		ITR++;
	}
	if (ERROR || (!ERROR && !ITR && c <= 0))
	{
		ft_del_tool(&tool);
		(dot->mass) ? ft_del_struct(&dot) : free(dot);
		ft_putstr("Invalid map\n");
		exit(1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_tool	*tool;
	t_dot	*dot;
	int		i;

	i = 0;
	if (ac != 2)
	{
		ft_putstr("Invalid number of arguments\n");
		ft_putstr("Usage:[./fdf][some map]\n");
		exit(1);
	}
	tool = malloc(sizeof(t_tool));
	dot = malloc(sizeof(t_dot));
	ft_init_var_1(tool, dot);
	ft_init_var_2(tool);
	ft_readfile(dot, tool, av[1], 0);
	tool->s_dot = ITR * S_BUFF;
	tool->mlx_ptr = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, 1600, 900, "FDF");
	tool->str_x = (S_BUFF < ITR) ? 500 / ITR : 600 / S_BUFF;
	tool->cp_org = dot;
	ft_calcul_pixel(dot, tool);
	return (0);
}
