extern "C" 
{
	#include "../core/notes.h"
};
#include "Note.h"
#include <iostream>
using namespace std;

Note::Note() {
	octave = 4;
	basename = NOTE((char *)"C");
}

int main() {
	Note n;
	cout << n.octave << '\n';
	return 0;
}
