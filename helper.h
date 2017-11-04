#ifndef HELPER_H
#define HELPER_H

int get_array_length(const char* path);

void map_input_to_array(const char* path, int* array);

bool is_number_range_correct(int* array, int length);

bool is_duplicate_int(int* array, int range);

bool is_appeared_before(int* array, int num, int length);

#endif
