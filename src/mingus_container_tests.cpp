/*

================================================================================
    
    cmingus, a reimplementation of mingus in C.
    Copyright (C) 2008-2009, Bart Spaans <bartspaans@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

================================================================================

*/

#include <iostream>
#include <assert.h>
#include "containers/Note.cpp"

void start_test(const char *);
void end_test(void);

/*	containers/Note.cpp	*/
void test_Note_to_int(void);

int testnr = 0;

int 
main() {
	printf("==========================================================\n");
	printf("                         CMINGUS                          \n");
	printf("==========================================================\n");
	printf("cmingus_containers 0.1 - Unit Tests\n");
	printf("Copyright(C) 2009, Bart Spaans <bartspaans@gmail.com>\n");
	printf("This program is free software and licensed under the GPLv3\n");
	printf("Compiled on %s, %s\n", __TIME__, __DATE__);
	printf("==========================================================\n");
	printf("                          NOTE                            \n");
	printf("==========================================================\n");
	test_Note_to_int();
	return 0;
}

void 
start_test(const char* testname)
{
	cout << testnr << ". Testing " << testname << "...";
	testnr++;
}

void 
end_test()
{
	cout << "OK\n";
}

void test_Note_to_int() 
{
	Note n;

	start_test("Note::to_int");
	assert(n.to_int() == 48);
	end_test();
}
