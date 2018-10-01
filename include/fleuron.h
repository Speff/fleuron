#ifdef __cplusplus
extern "C"{
#endif 

#ifndef FLEURON
#define FLEURON

typedef struct{
    clock_t time;
} f_time_record;

typedef struct{
    size_t num_elements;
    long clock_rate;
    clock_t* time;
    char** time_desc;
} f_timer;

typedef f_timer* Fleuron;

Fleuron fleuron_init();
int fleuron_add(Fleuron in, const char* str_in);
int fleuron_delete(Fleuron in);
void fleuron_print(Fleuron in);
#endif

#ifdef __cplusplus
}
#endif
