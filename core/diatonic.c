#include "notes.h"
#include "diatonic.h"

void
get_notes(note key, note* result)
{
	int i, fi = fifths_index(key.basename);
	char nametmp[2];
	note tmp;

	if (fi != 0)
	{
		for (i = 0; i < 7; i++) 
		{
			nametmp[0] = fifths[i];
			nametmp[1] = '\0';
			tmp = NOTE(nametmp);
			tmp.accidentals = key.accidentals;
			if (i < fi - 1) 
				tmp.accidentals += 1;
			result[i] = tmp;
		}
	}
	else 
	{
		result[6] = NOTE("Bb");
		for (i = 0; i < 6; i++) 
		{
			nametmp[0] = fifths[i];
			nametmp[1] = '\0';
			tmp = NOTE(nametmp);
			tmp.accidentals = key.accidentals;
			result[i] = tmp;
		}
	}

	sort_notes(result, 7);
	partition_on_tonic(result, 7, key);
}

void
get_notes_from_str(char *key, note *result) 
{
	return get_notes(NOTE(key), result);
}

void 
partition_on_tonic(note *notes, int size, note n)
{
	int i, r = -1, a= 0;
	note tmp[7];

	for (i = 0; i < size; i++) 
	{
		if (equals(notes[i], n))
		{
			r = i;
			break;
		}
	}
	if (r == -1) 
		return;

	for(i = r; i < size; i++)
		tmp[a++] = notes[i];
	for(i = 0; i < r; i++)
		tmp[a++] = notes[i];
	
	for (i = 0; i < size; i++) 
		notes[i] = tmp[i];

}
