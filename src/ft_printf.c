/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 01:43:35 by jjourne           #+#    #+#             */
/*   Updated: 2018/03/04 21:30:10 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	del_list(t_result *lst)
{
	t_result *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		ft_memdel((void **)&lst);
		lst = tmp;
	}
	ft_memdel((void **)&tmp);
}

void 	add_to_result(t_printf *data, char c, int flag)
{
	t_result *new;

	if ((data->result_i == 0) || (data->result_i == BUF_SIZE))
	{
		if (!(new = (t_result*)ft_memalloc(sizeof(t_result))))
			exit(EXIT_FAILURE);
		if (data->result_i == 0)
			data->result_start = new;
		else if (!(data->result_i = 0))
			data->result_end->next = new;
		data->result_end = new;
		new->next = NULL;
	}
	if (flag == 0)
		data->result_end->buf[data->result_i] = data->format[data->format_i];
	else
		data->result_end->buf[data->result_i] = c;
	++(data->result_i);
}

//faire un printf qui "bufferise"?
int		ft_printf(const char *format, ...)
{
	va_list     vl;
	t_printf	data;

	//initialisation
	data.format = ft_strdup(format);
	data.result_i = 0;
	data.format_i = -1;

	//code reel ft_printf
	va_start(vl, format);
	parser(&data, vl);
	printf("lol\n");
	va_end(vl);

	//affichage de debug
	print_flag(&data);
	print_format(&data);
	print_lst(&data);

	//free
	ft_memdel((void **)&(data.format));
	del_list(data.result_start);
	return (42);
}