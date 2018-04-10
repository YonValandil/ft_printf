/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 04:35:39 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/10 04:37:00 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag(t_printf *data)
{
	int i;

	i = -1;
	printf("\n'0'  '-'  '+'  ' '  '#'  'hh' 'h'  'j'  'l'  'z'  'L'  '.'  'w'");
	printf("\n");
	while (++i <= 12)
		printf("[%d]  ", (data->flag[0] & 1 << i) / (1 << i));
	printf("\n\n");
	printf("field with = %d\n", data->flag[1]);
	printf("precision = %d\n\n", data->flag[2]);
}

void	print_lst(t_printf *data)
{
	t_result *curr;

	*curr = data->result_start;
	printf("\nresult: \"");
	while (curr)
	{
		printf("%s", curr->buf);
		curr = curr->next;
	}
	printf("\"\n");
}

void	print_format(t_printf *data)
{
	printf("format: \"%s\"\n", data->format);
}
