/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 23:42:49 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/04 01:30:30 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "libft.h"

#include <stdio.h> //

#define SPECIFIER "sSpdioOuUxXblablabla"

typedef struct		s_coords
{
	int				x;
	int				y;
}					t_coords;


#endif
