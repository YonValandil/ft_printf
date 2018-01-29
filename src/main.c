#include "ft_printf.h"

//fonction a ajouter dans la libft (=lst_add_end a remplacer)
//faire aussi une fnct newnode si possible
// void 	ft_enqueue(void **begin_queue, void **end_queue, void *new)//**?
// {
// 	char *tmp_begin;
// 	char *tmp_end;
// 	char *tmp_new;
//
// 	if (begin_queue && end_queue && new) //*end_queue(?) etc..
// 	{
// 		tmp_begin = *(char **)begin_queue;
// 		tmp_end = *(char **)end_queue;
// 		tmp_new = (char *)new;
// 		if (!tmp_end)
// 			tmp_queue = tmp_new;
// 		else
// 			tmp_end->next = tmp_new;
// 		tmp_end = tmp_new;
// 		tmp_new->next = NULL;
// 	}
// }

//en faire une fonction generique, avec **?
void 	del_list(t_result *lst)
{
	t_result *tmp;

	tmp = lst;
	while (tmp)
	{
		ft_memdel((void **)&lst); //cast?
		tmp = tmp->next;
		lst = tmp;
	}
	ft_memdel((void **)&tmp);
}

int		main(void)
{
	int ret;
	// ft_printf("send : |%-020.3s| panda sauvage\0", "panda sauvage");
	// ft_printf("send : |%-020.3#15s| panda sauvage\0", "panda sauvage");
	// ft_printf("send : |%-020.3#15.77+s| panda sauvage\0", "panda sauvage");
	// ft_printf("send : |%-20.3#15..77+s| panda sauvage\0", "panda sauvage");
	// ft_printf("send : |%%020..3#15.s| panda sauvage", "panda sauvage");
	ret = ft_printf("send : |%%%020..7 -3#15+.s| pandas sauvages!", "yoyo"); //tester san spec
	// ft_printf("send : |%3s| panda sauvage\0", "panda sauvage");
	// ft_printf("send : |%s| panda sauvage", "panda sauvage");
	// ft_printf("send : || panda sauvage", "panda sauvage");

	// ft_printf("panda sauvage");
	// ft_printf("yoyo12test34ninja56");
	return EXIT_SUCCESS;
}
