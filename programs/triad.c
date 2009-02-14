#include "../src/core/core.h"
#include <stdio.h>


int
main(int argc, char **argv)
{
	chord i;
	note c[3];
	char result[30];


	if (argc != 4)
	{
		return 1;
	}


	if (is_valid_note_str(argv[1]) &&
		is_valid_note_str(argv[2]) &&
		is_valid_note_str(argv[3]))
	{
		c[0] = NOTE(argv[1]);
		c[1] = NOTE(argv[2]);
		c[2] = NOTE(argv[3]);
		i = determine_triad(c);
		chord_to_string(i, result, 0);
		printf("%s\n", result);
		return 0;
	}

	return 1;
}
