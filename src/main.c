#include "ft_printf.h"

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
		ft_printf("send : |%D| |%LD| |%jD| |%hhD| |%hD| |%zD| |%lD| !", -501, (long long)-502, (long)-503, (char)-504, (short)-505, (long)-506, (long)-507);
		printf("\nprintf: \"send : |%D| |%LD| |%jD| |%hhD| |%hD| |%zD| |%lD| !\"\n", -501, (long long)-502, (long)-503, (char)-504, (short)-505, (long)-506, (long)-507);
		// ft_printf("send : |%zd| |%Ld| |%jd| |%hhd| |%hd| |%d| |%ld| !", -1250125, -1250225, -1250325, -1250425, -1250525, -1250625, -1250725);
		// printf("\nprintf: \"send : |%zd| |%Ld| |%jd| |%hhd| |%hd| |%d| |%ld| !\"\n", -1250125, -1250225, -1250325, -1250425, -1250525, -1250625, -1250725);
		// ft_printf("send : |%zi| |%Li| |%ji| |%hhi| |%hi| |%i| |%li| !", -1250125, -1250225, -1250325, -1250425, -1250525, -1250625, -1250725);
		// printf("\nprintf: \"send : |%zi| |%Li| |%ji| |%hhi| |%hi| |%i| |%li| !\"\n", -1250125, -1250225, -1250325, -1250425, -1250525, -1250625, -1250725);
	//-----nbr positif :
		// ft_printf("send : |%D| |%LD| |%jD| |%hhD| |%hD| |%zD| |%lD| !", 501, 502, 503, 504, 505, 506, 507);
		// printf("\nprintf: \"send : |%D| |%LD| |%jD| |%hhD| |%hD| |%zD| |%lD| !\"\n", 501, 502, 503, 504, 505, 506, 507);
		// ft_printf("send : |%d| |%Ld| |%jd| |%hhd| |%hd| |%zd| |%ld| !", 501, 502, 503, 504, 505, 506, 507);
		// printf("\nprintf: \"send : |%d| |%Ld| |%jd| |%hhd| |%hd| |%zd| |%ld| !\"\n", 501, 502, 503, 504, 505, 506, 507);
		// // ft_printf("send : |%i| |%Li| |%ji| |%hhi| |%hi| |%zi| |%li| !", 501, 502, 503, 504, 505, 506, 507);
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
		// // ft_printf("send : |%X| |%jX| |%hhX| |%hX| |%zX| |%LX| !", 5111, 5112, 5113, 5114, 5115, 5116);
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

	//AUTREE TEST DIVERS POUR COMPRENDRE
	// int p;
	// ft_printf("send : |%p| !", &p);
	// printf("\nprintf: \"send : |%p| !\"\n", &p);
	// printf("send : |%%%| |%.2-w| |%0.d| |%0207 -3 #15.7+s| pandas sauvages!");

	// ft_printf("coucou");
	// printf("Je te l'avais dit:\n");
	// printf("%10d\n", 43210);
	// printf("%.10d\n", 43210);
	// printf("%3d\n", 43210);
	// printf("%.3d\n", 43210);
    //
	// printf("%10s\n", "test w");
	// printf("%.10s\n", "test pre");
	// printf("%3s\n", "test w");
	// printf("%.3s\n", "test pre");
    //
	// printf("%#25.10d\n", 43210);
	// printf("%25.10d\n", 43210);

	// printf("\n%10.3d\n", 43210);
	// ft_printf("yoyo %.3d", 43210);
	// ft_printf("a%10.4lhhd", 43210); //boucle infini avec field width
	// ft_printf("%10.4lhhd", 43210); //boucle infini avec field width

	return EXIT_SUCCESS;
}
