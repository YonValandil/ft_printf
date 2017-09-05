/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 23:36:12 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/05 01:53:27 by jjourne          ###   ########.fr       */
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

void	ft_miniprintf(const char *pandastr, ...)
{
    va_list     vl;
    int         i;

    va_start(vl, pandastr);

    i = -1;
    while (pandastr[++i])
    {
        if (pandastr[i] == 's')
        {
            printf("%s\n", va_arg(vl, char*));
        }
        if (pandastr[i] == 'd')
        {
            printf("%d\n", va_arg(vl, int));
        }
        if (pandastr[i] == 'i')
        {
            printf("%d\n", va_arg(vl, int));
        }
        if (pandastr[i] == 'u')
        {
            printf("%u\n", va_arg(vl, unsigned int));
        }
        if (pandastr[i] == 'c')
        {
            printf("%c\n", (char)va_arg(vl, int));
        }
    }
    va_end(vl);
}

int		main(void)
{
    //test_variatique("panda", 1, 2, 4, 8, 16, 32, 64, -1, 128, 255);
    printf("lol prout\n", 45);
    ft_miniprintf("ceci est %s du %d texte %u simple %c", "panda", -42, 1337, 'x');
    //ft_miniprintf("\nmy printf ->\n%s\n", argv[1]);

    return (0);
}
