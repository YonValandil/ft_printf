/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 23:36:12 by jjourne           #+#    #+#             */
/*   Updated: 2017/09/06 04:18:18 by jjourne          ###   ########.fr       */
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

void		*ft_memjoin(void const *s1, void const *s2, size_t n1, size_t n2)
{
	size_t	i;
	size_t	j;
	void	*ns;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
	{
		ns = ft_memalloc((!s1) ? n2 : n1);
		if (ns == NULL)
			return (NULL);
		ns = ft_memcpy(ns, ((!s1) ? (void*)s2 : (void*)s1), ((!s1) ? n2 : n1));
		return ((unsigned char*)ns);
	}
	i = -1;
	j = -1;
	ns = (unsigned char*)ft_memalloc(n1 + n2);
	if (ns == NULL)
		return (NULL);
	while (++i < n1)
		((unsigned char*)ns)[i] = ((const unsigned char*)s1)[i];
	while (++j < n2)
		((unsigned char*)ns)[i++] = ((const unsigned char*)s2)[j];
	return ((unsigned char*)ns);
}



void	ft_miniprintf(const char *pandastr, ...)
{
    va_list     vl;
    int         i;

    va_start(vl, pandastr);

    i = 0;
    while (pandastr[i])
    {
        if(pandastr[i] == '%')
        {
            if (pandastr[i + 1] == 's')
                printf("%s", va_arg(vl, char*));
            if (pandastr[i + 1] == 'd')
                printf("%d", va_arg(vl, int));
            if (pandastr[i + 1] == 'i')
                printf("%d", va_arg(vl, int));
            if (pandastr[i + 1] == 'u')
                printf("%u", va_arg(vl, unsigned int));
            if (pandastr[i + 1] == 'c')
                printf("%c", (char)va_arg(vl, int));
            i += (pandastr[i + 1] == '\0') ? 1 : 2;
        }
        else
            printf("%c", pandastr[i++]);
    }
    va_end(vl);
}

int		main(void)
{
    //test_variatique("panda", 1, 2, 4, 8, 16, 32, 64, -1, 128, 255);
    //printf("lol spiouc\n", 45);
    ft_miniprintf("Bonjour %s ! cette belle matinée du %d %s ?\n%", "panda", 11, "septembre");
    //ft_miniprintf("\nmy printf ->\n%s\n", argv[1]);

    return (0);
}
