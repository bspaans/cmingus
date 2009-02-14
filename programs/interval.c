#include "../src/core/core.h"
#include <stdio.h>


int
main(int argc, char **argv)
{
	interval i;
	char result[30];

	if (argc != 3)
	{
		return 1;
	}


	if (is_valid_note_str(argv[1]) &&
			is_valid_note_str(argv[2]))
	{
		i = determine_interval(NOTE(argv[1]), NOTE(argv[2]));
		interval_to_string(i, result);
		printf("%s\n", result);
		return 0;
	}

	return 1;
}
