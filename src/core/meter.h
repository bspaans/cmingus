
typedef int meter[2];

extern meter common_time;
extern meter cut_time;

int valid_beat_duration(int);
int is_valid_meter(meter);
int is_compound_meter(meter);
int is_simple_meter(meter);
int is_asymmetrical_meter(meter);
