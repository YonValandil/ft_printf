/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 01:43:35 by jjourne           #+#    #+#             */
/*   Updated: 2018/01/16 23:25:26 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parser(t_printf *print, va_list vl)
{
	int i;
	int	ret;
	int state;
	const char* format;

	i = -1;
	ret = 0; //nbr d'incr a passer dans format apres les flag
	state = 0;
	format = va_arg(vl, const char*);
	//print->total = ft_strlen(format);
	while (format[++i]) //main loop
	{
		write(1, "1\n", 2);
		if (format[i] == '%' && format[i + 1] == '%'){ //si il y a 2 % d'affile
			i++;
		}else if(format[i] == '%'){ //si %, rentrer dans un chunk de flag(state == 1)
			//ret = get_flag();
			i = i + ret;
			state = 1;
		}
		if (state == 1){ //si on est dans un chunk de flag(state=1)
			//call the universe
			state = 0;
		}else{ //si on est dans un chunk standard(state=0): caractere simple
			write(1, "2/n", 2);
			print->result.buf[i] = format[i]; //la copie segfault
			write(1, "3/n", 2);
		}
	}
	return (42);
}

int		ft_printf(const char *format, ...)
{
	va_list     vl;
	t_printf	*print;

	va_start(vl, format);
	//init(); //initialise la structure a 0 | list chainee(?)
	parser(print, vl);
	va_end(vl);
	return 42; //return la taille de la chaine(format) final
}

int		main(void)
{
	ft_printf("coucou !");
	return EXIT_SUCCESS;
}
