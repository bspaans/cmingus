#include "../src/core/core.h"
#include <stdio.h>


int
main(int argc, char **argv)
{


	if (argc != 2)
		return 1;

	return is_valid_note_str(argv[1]);
}
