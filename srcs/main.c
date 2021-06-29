
#include "../includes/so_long.h"

int main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 2)
	{
		sl_data_init(&data);
		sl_parse(argv[1], &data);
		if (sl_check_points(data.sl) != 0)
			ft_error_handling("Error\n");
		so_long(&data);
	}
	return (0);
}
