
typedef int meter[2];

extern meter common_time;
extern meter cut_time;

int valid_beat_duration(int);

#define is_valid_meter(meter) (meter[0] >= 0 && valid_beat_duration(meter[1]))
#define is_compound_meter(meter) (is_valid_meter(meter) && meter[0] % 3 == 0)
#define is_simple_meter(meter) (is_valid_meter(meter))
#define is_asymmetrical_meter(meter) (is_valid_meter(meter) && meter[0] % 2 == 1)
