// Fichier push test_variatique.c sur le repo. À compiler de façon standard avec gcc.
//
// variatic_is_limited()
// Premier test de base où il faut stopper avec une condition définie par l'utilisateur, la boucle pour la lecture des arguments de va_arg, ici de même type.
//
// ft_fake_printf()
// Utilisation de va_list avec des spécifications de type. Que se passe t-il si vous commentez certaines conditions ?

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void	variatic_is_limited(char *panda, ...)
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

void	ft_fake_printf(const char *pandastr, ...)
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
    //variatic_is_limited("panda", 1, 2, 4, 8, 16, 32, 64, -1, 128, 255);
    ft_fake_printf("Bonjour %s ! cette belle matinée du %d %s\n", "panda", 4, "kupo!");

    return EXIT_SUCCESS;
}
