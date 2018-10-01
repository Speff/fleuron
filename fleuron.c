#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <fleuron.h>

Fleuron fleuron_init(){
    Fleuron ret = (Fleuron)malloc(sizeof(f_timer));
    ret->time = (clock_t*)malloc(sizeof(clock_t));
    ret->time_desc = (char**)malloc(sizeof(char*));
    if((ret == NULL) || (ret->time == NULL) || (ret->time_desc == NULL))
        return NULL;

    ret->num_elements = 1;
    ret->time[0] = clock();
    ret->clock_rate = CLOCKS_PER_SEC;

    char* time_desc_init = "Init";
    ret->time_desc[0] = (char*)malloc(sizeof(char)*(strlen(time_desc_init)+1));
    if(ret->time_desc[0] == NULL) return NULL;
    strcpy(ret->time_desc[0], time_desc_init);

    return ret;
}

int fleuron_add(Fleuron in, const char* str_in){
    if(in == NULL) return -1;
    if(str_in == NULL) return -1;

    clock_t* temp_time = (clock_t*)malloc(sizeof(clock_t) * in->num_elements);
    char** temp_time_desc = (char**)malloc(sizeof(char*) * in->num_elements);
    if(temp_time == NULL) return 0;
    if(temp_time_desc == NULL) return 0;

    memcpy(temp_time, in->time, sizeof(clock_t*) * in->num_elements);
    memcpy(temp_time_desc, in->time_desc, sizeof(char**) * in->num_elements);

    in->num_elements += 1;

    in->time = (clock_t*)realloc(in->time, sizeof(clock_t) * in->num_elements);
    in->time_desc = (char**)realloc(in->time_desc, sizeof(char**) * in->num_elements);
    if(in->time == NULL) return 0;
    if(in->time_desc == NULL) return 0;

    memcpy(in->time, temp_time, sizeof(clock_t*) * in->num_elements);
    memcpy(in->time_desc, temp_time_desc, sizeof(char**) * in->num_elements);

    in->time[in->num_elements - 1] = clock();
    in->time_desc[in->num_elements - 1] = (char*)malloc(sizeof(char)*(strlen(str_in)+1));
    strcpy(in->time_desc[in->num_elements - 1], str_in);

    return 1;
}

int fleuron_delete(Fleuron in){
    if(in == NULL) return 0;

    for(size_t i = 0; i < in->num_elements; i++){
        free(in->time_desc[i]);
    }

    free(in->time);
    free(in->time_desc);
    free(in);
    return 1;
}

void fleuron_print(Fleuron in){
    if(in == NULL) return;

    for(size_t i = 0; i < in->num_elements; i++){
        printf("%ld\t%s\n", in->time[i], in->time_desc[i]);
    }
}

//int main(int argc, char** argv){
//    long long i;
//    i = 10000000;
//    while(i--);
//
//    Fleuron time_r = initTimer();
//    i = 10000000;
//    while(i--);
//    fleuron_add(time_r, "TEST_TIME");
//    fleuron_print(time_r);
//
//    fleuron_delete(time_r);
//    return 0;
//}
