#include "philo.h"

/* number; */
/* time_die; */
/* time_eat; */
/* time_sleep; */
/* must_eat; */

/* number > 0 */

bool input_check(int argc ,char **argv)
{
	const char *str;

	if(argc < 5 || argc > 6 || *argv[1] == '0') 		
	{
				ft_put_error(ARGS_ERROR);
				return(false);
	}
	while(*++argv)
	{
			str = *argv;
			while(*str)
			{
					if(!ft_isdigit(*str))
					{
						ft_put_error(ARGS_ERROR);
						return(false);
					}
					str++;
			}
	}
	return(true);
}
