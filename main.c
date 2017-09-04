/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 23:36:12 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/04 04:20:53 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test_variatique(char *panda, ...)
{
    va_list     vl;
    int         ret;

    va_start(vl, panda);
    ret = 0;
    printf("\npanda = %s\n", panda);
    while (ret != -1)
    {
        ret = va_arg(vl, int);
        printf("\nval = %d\n", ret);
    }
    va_end(vl);
}

int		main(void)
{
    //test_variatique("panda", 1, 2, 4, 8, 16, 32, 64, -1, 128, 255);
    

    return (0);
}
