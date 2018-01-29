#include "ft_printf.h"

void 	print_flag(t_printf *data)
{
	int i;

	i = -1;
	printf("\n'0' '-' '+' ' ' '#' 'w' '.'\n");
	while (++i < 7)
		printf("[%d] ", (data->flag[0] & (1 << e_flag_zero + i)) / (1 << i));
	printf("\n\n");
	printf("field with = %d\n", data->flag[1]);
	printf("precision = %d\n\n", data->flag[2]);
}

void 	print_lst(t_printf *data)
{
	t_result *curr = data->res_begin;

	printf("\nresult: \"");
	while (curr) {
		printf("%s", curr->buf);
		curr = curr->next;
	}
	printf("\"\n");
}

void 	print_format(t_printf *data)
{
	printf("format: \"%s\"\n", data->format);
}
