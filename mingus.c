#include <stdio.h>
#include <assert.h>

int main() {
	assert(note_to_int("C##") == 3);
	printf("Test? %d\n", note_to_int("C##"));
}
