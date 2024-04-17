#include "philo.h"

int main(int argc, char **argv)
{
			t_info *input;

			if (!input_check(argc, argv))
				return (ERROR);
			input = init_info(argc, argv);
			if (!input)
				return (ERROR);

			return (SUCCESS);
}