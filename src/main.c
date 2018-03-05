#include "ft_printf.h"

int		main(void)
{
	int ret;

	// ret = ft_printf("send : |%0-#15hz.7zc| |%.9#019ls| |%.9-0hhd| |%0lu| pandas sauvages!",
		// 'j', "tsubotsubo", 512, 73422);
	// ret = printf("\nprintf : |%0-#15hz.7zc| |%.9#019ls| |%.9-0hhd| |%0lu| pandas sauvages!",
		// 'j', "tsubotsubo", 512, 73422);

	//TEST MODIFIERS sur d
	//-----nbr negatif :
		// ft_printf("send : |%d| |%Ld| |%jd| |%hhd| |%hd| |%zd| |%ld| !", -501, (long)-502, (long)-503, (char)-504, (short)-505, (long)-506, (long)-507);
		// printf("\nprintf: \"send : |%d| |%Ld| |%jd| |%hhd| |%hd| |%zd| |%ld| !\"\n", -501, (long)-502, (long)-503, (char)-504, (short)-505, (long)-506, (long)-507);
		// ft_printf("send : |%zd| |%Ld| |%jd| |%hhd| |%hd| |%d| |%ld| !", -1250125, -1250225, -1250325, -1250425, -1250525, -1250625, -1250725);
		// printf("\nprintf: \"send : |%zd| |%Ld| |%jd| |%hhd| |%hd| |%d| |%ld| !\"\n", -1250125, -1250225, -1250325, -1250425, -1250525, -1250625, -1250725);
	//-----nbr positif :
		// ft_printf("send : |%d| |%Ld| |%jd| |%hhd| |%hd| |%zd| |%ld| !", 501, 502, 503, 504, 505, 506, 507);
		// printf("\nprintf: \"send : |%d| |%Ld| |%jd| |%hhd| |%hd| |%zd| |%ld| !\"\n", 501, 502, 503, 504, 505, 506, 507);
	//-----nbr max et min :
		ft_printf("send : |%Ld| |%zd| |%jd| |%hhd| |%hd| |%d| |%ld| !", ULONG_MAX, UINT_MAX , -851621 , SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		printf("\nprintf: \"send : |%Ld| |%zd| |%jd| |%hhd| |%hd| |%d| |%ld| !\"\n", ULONG_MAX, UINT_MAX, -851621, SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN);
		// long	i;
		// i = LONG_MIN;
		// printf("%s\n", ft_lltoa_base(-9223372036854, 10));
		// while (i)
		// {
			// printf("%s\n", ft_lltoa_base(i, 10));
			// i /= 10;
		// }
		// printf("%s\n", ft_lltoa_base(-92233720368547, 10));
		// printf("send : |%%%| |%.2-w| |%0.d| |%0207 -3 #15.7+s| pandas sauvages!");

	//TEST MODIFIERS sur u
	//-----nbr positif :
		// ft_printf("send : |%u| |%lu| |%ju| |%hhu| |%hu| |%zu| |%Lu| !", 50125, 50225, 50325, 50425, 50525, 50625, 50725);
		// printf("\nprintf: \"send : |%u| |%lu| |%ju| |%hhu| |%hu| |%zu| |%Lu| !\"\n", 50125, 50225, 50325, 50425, 50525, 50625, 50725);
	//-----nbr negatif :
		// ft_printf("send : |%u| |%lu| |%ju| |%hhu| |%hu| |%zu| |%Lu| !", -501, -502, -503, -504, -505, -506, -507);
		// printf("\nprintf: \"send : |%u| |%lu| |%ju| |%hhu| |%hu| |%zu| |%Lu| !\"\n", -501, -502, -503, -504, -505, -506, -507);

	// printf("\n==========> ulltoa = %s\n", ft_ulltoa_base(9669875, 16));
	return EXIT_SUCCESS;
}
