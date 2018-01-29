/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 01:43:35 by jjourne           #+#    #+#             */
/*   Updated: 2018/01/21 08:40:42 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flag(t_printf *data, int j, int i)
{
	data->flag[0] = 0;
	while (ft_strchr(FLAG, data->format[++j]) && !(i = 0))
	{
		while (i < 5)
			data->flag[0] |= (data->format[j] == FLAG[i]) << e_flag_zero + i++;
		if (ft_isdigit(data->format[j]) && (data->format[j] != '0') && (--j) &&
			(data->flag[0] |= (1 << e_flag_with)) && !(data->flag[1] = 0))
			while (ft_isdigit(data->format[j + 1]) && (++j))
				data->flag[1] = data->flag[1] * 10 + data->format[j] - '0';
		if ((data->format[j] == '.') && !(data->flag[2] = 0) &&
			(data->flag[0] |= (1 << e_flag_pre)))
			while (ft_isdigit(data->format[j + 1]) && (++j))
				data->flag[2] = data->flag[2] * 10 + data->format[j] - '0';
	}
	return (j);
}

int 	add_str_to_buf(t_printf *data, int i, int j)
{
	t_result *new;

	if ((i == 0) || (i == BUFF_SIZE))
	{
		if (!(new = (t_result*)ft_memalloc(sizeof(t_result))))
			exit(EXIT_FAILURE);
		ft_bzero(new->buf, BUFF_SIZE + 1);
		if (i == 0)
			data->res_begin = new;
		else if (!(i = 0))
			data->res_end->next = new;
		data->res_end = new;
		new->next = NULL;
	}
	data->res_end->buf[i] = data->format[j];
	return (i);
}

void	parser(t_printf *data, va_list vl) //dereferrencer ou par adresse?
{
	int i;
	int j;
	int state;

	i = -1;
	j = -1;
	while ((data->format[++j]) && !(state = 0))
	{
		if(data->format[j] == '%' && data->format[j + 1] != '%' && (state = 1))
			j = get_flag(data, j, i);
		if (state)
			printf("\ncall the universe\n");
		else
			i = add_str_to_buf(data, ++i, (data->format[j] == '%') ? ++j : j);
	}
}

//injection ? / pourquoi le vrais printf affiche quand il veut (\n?)
int		ft_printf(const char *format, ...)
{
	va_list     vl;
	t_printf	data;

	data.format = ft_strdup(format);
	va_start(vl, format);
	parser(&data, vl);
	va_end(vl);
	print_flag(&data);
	print_format(&data);
	print_lst(&data);
	ft_memdel((void **)&(data.format)); //cast * ou ** ?
	del_list(data.res_begin);
	return (42);
}
