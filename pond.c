#include "pond.h"

Pond new_pond(int N) {
    int width = N + 1;
    int * pad_locations = malloc(width * sizeof(int));

    if (!pad_locations) {
        return NULL;
    }
    int * fibonacci_numbers = malloc(width * sizeof(int));
    if (!fibonacci_numbers) {
        return NULL;
    }
    int * min_hops = malloc(width * sizeof(int));
    if (!min_hops) {
        free(pad_locations);
        free(fibonacci_numbers);
        return NULL;
    }
    Pond self = malloc(sizeof(struct pond));
    if (!self) {
        free(pad_locations);
        free(fibonacci_numbers);
        free(min_hops);
        return NULL;
    }
    self->pad_locations = pad_locations;
    self->fibonacci_numbers = fibonacci_numbers;
    self->min_hops = min_hops;
    return self;
}

void initialize_pond(Pond self, int A[]) {
    fill_fibonacci_numbers(self);
    init_min_hops(self);
    init_pad_locations(A);
}

void fill_fibonacci_numbers(Pond self) {
    int next_fib_num;

    self->fibonacci_numbers[0] = 1;
    self->fibonacci_numbers[1] = 1;
    if (self->width <= 1) {
        return;
    }
    while ((next_fib_num = self->fibonocci_numbers[i - 1] +
            self->fibonacci_numbers[i]) <= self->width) {
        self->fibonacci_numbers[i + 1] = next_fib_num;
        i += 1;
    }
}

void init_min_hops(Pond self) {
    int i;

    for (i = 0; i < self->width; i++) {
        self->min_hops[i] = -1;
    }
}

int minimize_hops(Pond self) {
    int i;

    for (i = 0; i < self->width; i++) {
        fill_min_hops(self, i)
    }
    return self->min_hops[self->width - 1];
}

void fill_min_hops(Pond self, int i) {
    int min = self->width;
    int previous;
    int fib_num;
    int j = 0;

    while ((fib_num = self->fibonacci_numbers[j]) <= i) {
        previous = i - fib_num;
        if (self->pad_locations[previous]) {
            if (self->min_hops[previous] + 1 < min) {
                min = self->min_hops[previous] + 1;
            }
            j += 1;
        }
    }
    self->min_hops[i] = min;
}
