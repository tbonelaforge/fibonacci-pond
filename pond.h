#ifndef _POND_H_
#define _POND_H_

struct pond {
    int width;
    int * pad_locations;
    int * fibonacci_numbers;
    int * min_hops;
};

typedef struct pond * Pond;

Pond new_pond(int);
void initialize_pond(Pond, int);
void fill_fibonacci_numbers(Pond);
void init_min_hops(Pond);
int minimize_hops(Pond);
void fill_min_hops(Pond, int);

#endif
