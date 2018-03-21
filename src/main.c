#include "ft_printf.h"
#include <stdio.h>

#define printest(...) \
		dprintf(2, __VA_ARGS__); \
		ft_printf(__VA_ARGS__);

int		main(void)
{
	// int ret;

	// ret = ft_printf("send : |%0-#15hz.7zc| |%.9#019ls| |%.9-0hhd| |%0lu| pandas sauvages!",
		// 'j', "tsubotsubo", 512, 73422);
	// ret = printf("\nprintf : |%0-#15hz.7zc| |%.9#019ls| |%.9-0hhd| |%0lu| pandas sauvages!",
		// 'j', "tsubotsubo", 512, 73422);

	//TEST MODIFIERS sur d/D/i
	//-----nbr negatif :
		// ft_printf("send : |%D| |%LD| |%jD| |%hhD| |%hD| |%zD| |%lD| !", -501, (long long)-502, (long)-503, (char)-504, (short)-505, (long)-506, (long)-507);
		// printf("\nprintf: \"send : |%D| |%LD| |%jD| |%hhD| |%hD| |%zD| |%lD| !\"\n", -501, (long long)-502, (long)-503, (char)-504, (short)-505, (long)-506, (long)-507);
		// ft_printf("send : |%zd| |%Ld| |%jd| |%hhd| |%hd| |%d| |%ld| !", -1250125, -1250225, -1250325, -1250425, -1250525, -1250625, -1250725);
		// printf("\nprintf: \"send : |%zd| |%Ld| |%jd| |%hhd| |%hd| |%d| |%ld| !\"\n", -1250125, -1250225, -1250325, -1250425, -1250525, -1250625, -1250725);
		// ft_printf("send : |%zi| |%Li| |%ji| |%hhi| |%hi| |%i| |%li| !", -1250125, -1250225, -1250325, -1250425, -1250525, -1250625, -1250725);
		// printf("\nprintf: \"send : |%zi| |%Li| |%ji| |%hhi| |%hi| |%i| |%li| !\"\n", -1250125, -1250225, -1250325, -1250425, -1250525, -1250625, -1250725);
	//-----nbr positif :
		// ft_printf("send : |%D| |%LD| |%jD| |%hhD| |%hD| |%zD| |%lD| !", 501, 502, 503, 504, 505, 506, 507);
		// printf("\nprintf: \"send : |%D| |%LD| |%jD| |%hhD| |%hD| |%zD| |%lD| !\"\n", 501, 502, 503, 504, 505, 506, 507);
		// ft_printf("send : |%d| |%Ld| |%jd| |%hhd| |%hd| |%zd| |%ld| !", 501, 502, 503, 504, 505, 506, 507);
		// printf("\nprintf: \"send : |%d| |%Ld| |%jd| |%hhd| |%hd| |%zd| |%ld| !\"\n", 501, 502, 503, 504, 505, 506, 507);
		// ft_printf("send : |%i| |%Li| |%ji| |%hhi| |%hi| |%zi| |%li| !", 501, 502, 503, 504, 505, 506, 507);
		// printf("\nprintf: \"send : |%i| |%Li| |%ji| |%hhi| |%hi| |%zi| |%li| !\"\n", 501, 502, 503, 504, 505, 506, 507);
	//-----nbr max et min :
		// ft_printf("send : |%LD| |%zD| |%jD| |%hhD| |%hD| |%D| |%lD| !", LONG_MAX, INT_MAX , -851621 , SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// printf("\nprintf: \"send : |%LD| |%zD| |%jD| |%hhD| |%hD| |%D| |%lD| !\"\n", LONG_MAX, INT_MAX, -851621, SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// ft_printf("send : |%Ld| |%zd| |%jd| |%hhd| |%hd| |%d| |%ld| !", LONG_MAX, INT_MAX , -851621 , SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// printf("\nprintf: \"send : |%Ld| |%zd| |%jd| |%hhd| |%hd| |%d| |%ld| !\"\n", LONG_MAX, INT_MAX, -851621, SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// ft_printf("send : |%Li| |%zi| |%ji| |%hhi| |%hi| |%i| |%li| !", LONG_MAX, INT_MAX , -851621 , SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// printf("\nprintf: \"send : |%Li| |%zi| |%ji| |%hhi| |%hi| |%i| |%li| !\"\n", LONG_MAX, INT_MAX, -851621, SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);

	//TEST MODIFIERS sur u/U
	//-----nbr positif :
		// ft_printf("send : |%u| |%lu| |%ju| |%hhu| |%hu| |%zu| |%Lu| !", 50125, 50225, 50325, 50425, 50525, 50625, 50725);
		// printf("\nprintf: \"send : |%u| |%lu| |%ju| |%hhu| |%hu| |%zu| |%Lu| !\"\n", 50125, 50225, 50325, 50425, 50525, 50625, 50725);
		// ft_printf("send : |%U| |%lU| |%jU| |%hhU| |%hU| |%zU| |%LU| !", 50125, 50225, 50325, 50425, 50525, 50625, 50725);
		// printf("\nprintf: \"send : |%U| |%lU| |%jU| |%hhU| |%hU| |%zU| |%LU| !\"\n", 50125, 50225, 50325, 50425, 50525, 50625, 50725);
	//-----nbr negatif :
		// ft_printf("send : |%u| |%lu| |%ju| |%hhu| |%hu| |%zu| |%Lu| !", -501, -502, -503, -504, -505, -506, -507);
		// printf("\nprintf: \"send : |%u| |%lu| |%ju| |%hhu| |%hu| |%zu| |%Lu| !\"\n", -501, -502, -503, -504, -505, -506, -507);
		// ft_printf("send : |%U| |%lU| |%jU| |%hhU| |%hU| |%zU| |%LU| !", -501, -502, -503, -504, -505, -506, -507);
		// printf("\nprintf: \"send : |%U| |%lU| |%jU| |%hhU| |%hU| |%zU| |%LU| !\"\n", -501, -502, -503, -504, -505, -506, -507);
	//-----nbr max et min :
		// ft_printf("send : |%Lu| |%zu| |%ju| |%hhu| |%hu| |%u| |%lu| !", ULONG_MAX, UINT_MAX , -851621 , CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// printf("\nprintf: \"send : |%Lu| |%zu| |%ju| |%hhu| |%hu| |%u| |%lu| !\"\n", ULONG_MAX, UINT_MAX, -851621, CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// ft_printf("send : |%LU| |%zU| |%jU| |%hhU| |%hU| |%U| |%lU| !", ULONG_MAX, UINT_MAX , -851621 , CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// printf("\nprintf: \"send : |%LU| |%zU| |%jU| |%hhU| |%hU| |%U| |%lU| !\"\n", ULONG_MAX, UINT_MAX, -851621, CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);

	//TEST MODIFIERS sur c
	//-----nbr positif :
		// ft_printf("send : |%c| |%lc| |%jc| |%hhc| |%hc| |%zc| |%Lc| !", 'a', 'b', 'c', 'd', 'e', 'f', 'g');
		// printf("\nprintf: \"send : |%c| |%lc| |%jc| |%hhc| |%hc| |%zc| |%Lc| !\"\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g');
	// -----nbr negatif :
		// ft_printf("send : |%c| |%jc| |%hhc| |%hc| |%zc| |%Lc| !", -52, -53, -54, -55, -56, -57);//lc unicode
		// printf("\nprintf: \"send : |%c| |%jc| |%hhc| |%hc| |%zc| |%Lc| !\"\n", -52, -53, -54, -55, -56, -57);
	//-----nbr max et min :
		// ft_printf("send : |%Lc| |%zc| |%jc| |%hhc| |%hc| |%c| |%lc| !", ULONG_MAX, UINT_MAX , -851621 , CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// printf("\nprintf: \"send : |%Lc| |%zc| |%jc| |%hhc| |%hc| |%c| |%lc| !\"\n", ULONG_MAX, UINT_MAX, -851621, CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);

	//TEST MODIFIERS sur s
	//-----nbr positif :
		// ft_printf("send : |%s| |%js| |%hhs| |%hs| |%zs| |%Ls| !", "abcdef", "abcdef", "abcdef", "abcdef", "abcdef", "abcdef");
		// printf("\nprintf: \"send : |%s| |%js| |%hhs| |%hs| |%zs| |%Ls| !\"\n", "abcdef", "abcdef", "abcdef", "abcdef", "abcdef", "abcdef");
	//-----nbr negatif :
		// ft_printf("send : |%s| |%js| |%hhs| |%hs| |%zs| |%Ls| !", -511, -512, -513, -515, -516, -517);
		// printf("\nprintf: \"send : |%s| |%js| |%hhs| |%hs| |%zs| |%Ls| !\"\n", -512, -513, -514, -515, -516, -517);
	// -----nbr max et min :
		// ft_printf("send : |%Ls| |%zs| |%js| |%hhs| |%hs| |%s| |%ls| !", ULONG_MAX, UINT_MAX , -851621 , CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// printf("\nprintf: \"send : |%Ls| |%zs| |%js| |%hhs| |%hs| |%s| |%ls| !\"\n", ULONG_MAX, UINT_MAX, -851621, CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);

	//TEST MODIFIERS sur x
	//-----nbr positif :
		// ft_printf("send : |%x| |%jx| |%hhx| |%hx| |%zx| |%Lx| !", 5111, 5112, 5113, 5114, 5115, 5116);
		// printf("\nprintf: \"send : |%x| |%jx| |%hhx| |%hx| |%zx| |%Lx| !\"\n", 5111, 5112, 5113, 5114, 5115, 5116);
		// ft_printf("send : |%X| |%jX| |%hhX| |%hX| |%zX| |%LX| !", 5111, 5112, 5113, 5114, 5115, 5116);
		// printf("\nprintf: \"send : |%X| |%jX| |%hhX| |%hX| |%zX| |%LX| !\"\n", 5111, 5112, 5113, 5114, 5115, 5116);
	//-----nbr negatif :
		// ft_printf("send : |%x| |%lx| |%jx| |%hhx| |%hx| |%zx| |%Lx| !", -511, -512, -513, -514, -515, -516, -517);
		// printf("\nprintf: \"send : |%x| |%lx| |%jx| |%hhx| |%hx| |%zx| |%Lx| !\"\n", -511, -512, -513, -514, -515, -516, -517);
		// ft_printf("send : |%X| |%lX| |%jX| |%hhX| |%hX| |%zX| |%LX| !", -511, -512, -513, -514, -515, -516, -517);
		// printf("\nprintf: \"send : |%X| |%lX| |%jX| |%hhX| |%hX| |%zX| |%LX| !\"\n", -511, -512, -513, -514, -515, -516, -517);
	//-----nbr max et min :
		// ft_printf("send : |%Lx| |%zx| |%jx| |%hhx| |%hx| |%x| |%lx| !", ULONG_MAX, UINT_MAX , -851621 , CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// printf("\nprintf: \"send : |%Lx| |%zx| |%jx| |%hhx| |%hx| |%x| |%lx| !\"\n", ULONG_MAX, UINT_MAX, -851621, CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// ft_printf("send : |%LX| |%zX| |%jX| |%hhX| |%hX| |%X| |%lX| !", ULONG_MAX, UINT_MAX , -851621 , CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// printf("\nprintf: \"send : |%LX| |%zX| |%jX| |%hhX| |%hX| |%X| |%lX| !\"\n", ULONG_MAX, UINT_MAX, -851621, CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);

	//TEST MODIFIERS sur o
	//-----nbr positif :
		// ft_printf("send : |%o| |%jo| |%hho| |%ho| |%zo| |%Lo| !", 5111, 5112, 5113, 5114, 5115, 5116);
		// printf("\nprintf: \"send : |%o| |%jo| |%hho| |%ho| |%zo| |%Lo| !\"\n", 5111, 5112, 5113, 5114, 5115, 5116);
		// ft_printf("send : |%O| |%jO| |%hhO| |%hO| |%zO| |%LO| !", 5111, 5112, 5113, 5114, 5115, 5116);
		// printf("\nprintf: \"send : |%O| |%jO| |%hhO| |%hO| |%zO| |%LO| !\"\n", 5111, 5112, 5113, 5114, 5115, 5116);
	//-----nbr negatif :
		// ft_printf("send : |%o| |%lo| |%jo| |%hho| |%ho| |%zo| |%Lo| !", -511, -512, -513, -514, -515, -516, -517);
		// printf("\nprintf: \"send : |%o| |%lo| |%jo| |%hho| |%ho| |%zo| |%Lo| !\"\n", -511, -512, -513, -514, -515, -516, -517);
		// ft_printf("send : |%O| |%lO| |%jO| |%hhO| |%hO| |%zO| |%LO| !", -511, -512, -513, -514, -515, -516, -517);
		// printf("\nprintf: \"send : |%O| |%lO| |%jO| |%hhO| |%hO| |%zO| |%LO| !\"\n", -511, -512, -513, -514, -515, -516, -517);
	//-----nbr max et min :
		// ft_printf("send : |%Lo| |%zo| |%jo| |%hho| |%ho| |%o| |%lo| !", ULONG_MAX, UINT_MAX , -851621 , CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// printf("\nprintf: \"send : |%Lo| |%zo| |%jo| |%hho| |%ho| |%o| |%lo| !\"\n", ULONG_MAX, UINT_MAX, -851621, CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// ft_printf("send : |%LO| |%zO| |%jO| |%hhO| |%hO| |%O| |%lO| !", ULONG_MAX, UINT_MAX , -851621 , CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// printf("\nprintf: \"send : |%LO| |%zO| |%jO| |%hhO| |%hO| |%O| |%lO| !\"\n", ULONG_MAX, UINT_MAX, -851621, CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);

	//----------------AUTRE TEST DIVERS POUR COMPRENDRE-------------------------
	// int p;
	// ft_printf("send : |%p| !", &p);
	// printf("\nprintf: \"send : |%p| !\"\n", &p);
	// ft_printf("send : |%+p| !", &p);
	// printf("\nprintf: \"send : |%+p| !\"\n", &p);
	// ft_printf("send : |%25p| !", &p);
	// printf("\nprintf: \"send : |%25p| !\"\n", &p);
	// ft_printf("send : |%-25p| !", &p);
	// printf("\nprintf: \"send : |%-25p| !\"\n", &p);
	// ft_printf("send : |%025p| !", &p);
	// printf("\nprintf: \"send : |%025p| !\"\n", &p);
	// ft_printf("send : |%.25p| !", &p);
	// printf("\nprintf: \"send : |%.25p| !\"\n", &p);
	// ft_printf("send : |%.p| !", &p);
	// printf("\nprintf: \"send : |%.p| !\"\n", &p);
	// ft_printf("send : |% p| !", &p);
	// printf("\nprintf: \"send : |% p| !\"\n", &p);
	// ft_printf("send : |%#p| !", &p);
	// printf("\nprintf: \"send : |%#p| !\"\n", &p);


	//TESTS chiffres
	ft_printf("|%+#010.5d|\n", 123);
	printf("|%+#010.5d|\n", 123);
	ft_printf("|%+#010d|\n", 123);
	printf("|%+#010d|\n", 123);
	ft_printf("|%+#10.15d|\n", 123);
	printf("|%+#10.15d|\n", 123);
	ft_printf("|%+#10.d|\n", 123);
	printf("|%+#10.d|\n", 123);
	ft_printf("|%0+#10.5d|\n", 123);
	printf("|%0+#10.5d|\n", 123);
	ft_printf("|%0#10.5d|\n", 123);
	printf("|%0#10.5d|\n", 123);
	ft_printf("|%0+#10.5d|\n", -123);
	printf("|%0+#10.5d|\n", -123);

	ft_printf("|%0+# 10.5x|\n", 123);
	printf("|%0+# 10.5x|\n", 123);

	ft_printf("|%0+# 10.5o|\n", 123);
	printf("|%0+# 10.5o|\n", 123);
	ft_printf("|%0+#10.5o|\n", 123);
	printf("|%0+#10.5o|\n", 123);
	ft_printf("|%+# 10.2o|\n", 123);
	printf("|%+# 10.2o|\n", 123);

	ft_printf("|%0+# 10.o|\n", 123);
	printf("|%0+# 10.o|\n", 123);
	ft_printf("|%+# 10.2o|\n", 123);
	printf("|%+# 10.2o|\n", 123);
	ft_printf("|%0+# 10.2o|\n", 0);
	printf("|%0+# 10.2o|\n", 0);
	ft_printf("|%0+# 10.o|\n", 0);
	printf("|%0+# 10.o|\n", 0);

	ft_printf("|%0#10.5u|\n", 123);
	printf("|%0#10.5u|\n", 123);
	ft_printf("|%0+#10.5u|\n", -123);
	printf("|%0+#10.5u|\n", -123);

	// TEST sur les types text (global)
	ft_printf("|%0 +#10.2s|\n", "123");
	printf("|%0 +#10.2s|\n", "123");
	ft_printf("|%0 +#10.5c|\n", 'a');
	printf("|%0 +#10.5c|\n", 'a');

	//valeur null ou pre 0
	//pour char
	ft_printf("|%010.5c|\n", 'a');
	printf("|%010.5c|\n", 'a');
	ft_printf("|%010.1c|\n", 'a');
	printf("|%010.1c|\n", 'a');
	ft_printf("|%010.c|\n", 'a');
	printf("|%010.c|\n", 'a');
	ft_printf("|%.0c|\n", 'a');
	printf("|%.0c|\n", 'a');
	ft_printf("|%010.5c|\n", 0);
	printf("|%010.5c|\n", 0);
	ft_printf("|%10.c|\n", 0);
	printf("|%10.c|\n", 0);
	ft_printf("|%010.c|\n", 0);
	printf("|%010.c|\n", 0);
	ft_printf("|%.c|\n", 0);
	printf("\n|%.c|\n", 0);
	ft_printf("|%-010.c|\n", 0);
	printf("\n|%0-10.c|\n", 0);
	ft_printf("|%11c|\n", 0);
	printf("|%11c|\n", 0);

	//pour str
	ft_printf("|%010.5s|\n", "abc");
	printf("|%010.5s|\n", "abc");
	ft_printf("|%10.5s|\n", "abc");
	printf("|%10.5s|\n", "abc");
	ft_printf("|%010.1s|\n", "abc");
	printf("|%010.1s|\n", "abc");
	ft_printf("|%010.s|\n", "abc");
	printf("|%010.s|\n", "abc");
	ft_printf("|%010.5s|\n", 0);
	printf("|%010.5s|\n", 0);
	ft_printf("|%10.s|\n", 0);
	printf("|%10.s|\n", 0);
	ft_printf("|%010.s|\n", 0);
	printf("|%010.s|\n", 0);
	ft_printf("|%0+#10.5s|\n", 0);
	printf("|%0+#10.5s|\n", 0);
	ft_printf("|%+#.s|\n", 0);
	printf("|%+#.s|\n", 0);
	ft_printf("|%-010s|\n", "abc");
	printf("|%-010s|\n", "abc");

	//---------------------------------OCTAL------------------------------------
	/*
	Avec un nombre:
		- si precision <= au nb:
			- affiche le nombre
			- avec le #: affiche un zero avant
		- si > au nb:
			- ajoute des 0 avant le nombre
			- avec le #: inactif car deja des 0

	Si nombre = 0:
		- precision 0 et nb 0, affiche rien
		- precision 0 et nb 0 avec #, ajoute le 0
		-
	*/
	// printf("\n==> octal pre 0 avec nb : |%. 0o|", 54321);
	// printf("\n==> octal pre 0 avec nb et # : |% .0#o|\n", 54321);
    //
	// printf("\n==> octal pre 0 nb 0 : %.0o", 0);
	// printf("\n==> octal pre 0 nb 0 et # : %.0#o\n", 0);
    //
	// printf("\n==> octal pre 4 avec nb  : %.4o", 54321);
	// printf("\n==> octal pre 4 avec nb et # : %.4#o\n", 54321);
    //
	// printf("\n==> octal pre 4 nb 0 : %.4o", 0);
	// printf("\n==> octal pre 4 nb 0 et # : %.4#o\n", 0);
    //
	// printf("\n==> octal pre 4 avec nb : %.4o", 1000);
	// printf("\n==> octal pre 4 avec nb et # : %.4#o\n", 1000);
    //
	// printf("\n==> octal pre 8 avec nb : %.8o", 1000);
	// printf("\n==> octal pre 8 avec nb et # : %.8#o\n", 1000);
    //
	// printf("\n==> octal pre 8  nb 0 : %.8o", 0);
	// printf("\n==> octal pre 8 nb 0 et # : %.8#o\n", 0);
    //
	// printf("\n==> octal nb 0 sans pre : %o", 0);
	// printf("\n==> octal nb 0 sans pre et # : %#o\n", 0);
    //
	// printf("\n==> octal avec nb sans pre : %o", 123);
	// printf("\n==> octal avec nb sans pre et # : %#o\n", 123);
    //
	// printf("\n==> octal avec nb sans pre et +: %+o", 123);
	// printf("\n==> octal avec nb sans pre et # + : %+#o\n", 123);
	//-------------------------------------------------------------------------

	//-------------------------test field width avec d------------------------------------------
	// printf("\nprintf d: |%0+9.4d|\n", 123); //fw = ' ' avant le +, puis pre puis pre (ok)
	// printf("\nprintf d: |%09.4d|\n", 123); //fw = ' ' et pre apres (ok) | pas de flag_0 avec flag_pre
	// printf("\nprintf d: |%0+9d|\n", 123); //fw = 0 apres le + (ok)
	// printf("\nprintf d: |%+9d|\n", 123); //fw = ' ' avant le + (ok)
	// printf("\nprintf d: |%09d|\n", 123); //fw = 0 (ok)
	// printf("\nprintf d: |%9d|\n", 123);//fw = ' ' (ok)
	//-------------------------------------------------------------------------

	//-------------------------test field width avec x------------------------------------------
	// printf("\nprintf x: |%0+9.4x|\n", 123); //fw = ' ' avant le +, puis pre puis pre (ok)
	// printf("\nprintf x: |%09.4x|\n", 123); //fw = ' ' et pre apres (ok) | pas de flag_0 avec flag_pre
	// printf("\nprintf x: |%0+9x|\n", 123); //pas de + (ok)
	// printf("\nprintf x: |%+9x|\n", 123); //pas de + avec x (ok)
	// printf("\nprintf x: |%09x|\n", 123); //fw = 0 (ok)
	// printf("\nprintf x: |%9x|\n", 123);//fw = ' ' (ok)

	// printf("\nprintf x: |%0#9.4x|\n", 123); //fw = ' ' , puis # puis pre (ok)
	// printf("\nprintf x: |%09.4x|\n", 123); //fw = ' ' et pre apres (ok) | pas de flag_0 avec flag_pre
	// printf("\nprintf x: |%0#9x|\n", 123); //fw = '0' apres le 0x (ok)
	// printf("\nprintf x: |%#9x|\n", 123); //fw = ' ' puis affiche le 0x (ok)
	// printf("\nprintf x: |%09x|\n", 123); //fw = 0 (ok)
	// printf("\nprintf x: |%9x|\n", 123);//fw = ' ' (ok)

	ft_printf("|%#x|\n", 0); //fw = ' ' puis affiche le 0x (ok)
	printf("|%#x|\n", 0); //fw = ' ' puis affiche le 0x (ok)
	//-------------------------------------------------------------------------

	//-------------------------test field width avec o------------------------------------------
	// printf("\nprintf o: |%0+9.4o|\n", 123); //fw = ' ' avant le +, puis preix puis pre (ok)
	// printf("\nprintf o: |%09.4o|\n", 123); //fw = ' ' et pre apres (ok) | pas de flag_0 avec flag_pre
	// printf("\nprintf o: |%0+9o|\n", 123); //pas de o (ok)
	// printf("\nprintf o: |%+9o|\n", 123); //pas de + avec o (ok)
	// printf("\nprintf o: |%09o|\n", 123); //fw = 0 (ok)
	// printf("\nprintf o: |%9o|\n", 123);//fw = ' ' (ok)

	// printf("\nprintf o: |%0#9.4o|\n", 123); //fw = ' ' avant le +, puis preix puis pre (ok)
	// printf("\nprintf o: |%09.4o|\n", 123); //fw = ' ' et pre apres (ok) | pas de flag_0 avec flag_pre
	// printf("\nprintf o: |%0#9o|\n", 123); //pas de o (ok)
	// printf("\nprintf o: |%#9o|\n", 123); //pas de + avec o (ok)
	// printf("\nprintf o: |%09o|\n", 123); //fw = 0 (ok)
	// printf("\nprintf o: |%9o|\n", 123);//fw = ' ' (ok)
	//-------------------------------------------------------------------------

	//-------------------------test x------------------------------------------
	// printf("\n==> x et +: %+x", 1723);
	// printf("\n==> x et #: %+#x\n", 1723);
	// printf("\n==> x et #: |% x|\n", 1723);
	// printf("\n==> x et #: %0 x\n", 1723);
	//-------------------------------------------------------------------------

	//-------------------------test s------------------------------------------
	// printf("\n==> s et +: %+s", "abcd");
	// printf("\n==> s et #: %+#s\n", "abcd");
	// printf("\n==> s et ' ': |% s|\n", "abcd");
	// printf("\n==> s et 0: %0 s\n", "abcd");
	//-------------------------------------------------------------------------

	return EXIT_SUCCESS;
}
