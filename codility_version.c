#include <stdlib.h>
#include <stdio.h>

struct pond {
    int width;
    int * pad_locations;
    int * fibonacci_numbers;
    int * min_hops;
};

typedef struct pond * Pond;

Pond new_pond(int);
void initialize_pond(Pond, int *);
void fill_fibonacci_numbers(Pond);
void init_min_hops(Pond);
void init_pad_locations(Pond, int *);
int minimize_hops(Pond);
void fill_min_hops(Pond, int);
void print_pond(Pond);
void print_pad_locations(Pond);
void print_fibonacci_numbers(Pond);
void print_min_hops(Pond);


Pond new_pond(int N) {
    int width = N + 1;
    int * pad_locations;
    int * fibonacci_numbers;
    int * min_hops;
    Pond self;

    pad_locations = malloc(width * sizeof(int));
    if (!pad_locations) {
        return NULL;
    }
    fibonacci_numbers = malloc(width * sizeof(int));
    if (!fibonacci_numbers) {
        free(pad_locations);
        return NULL;
    }
    min_hops = malloc(width * sizeof(int));
    if (!min_hops) {
        free(pad_locations);
        free(fibonacci_numbers);
        return NULL;
    }
    self = malloc(sizeof(struct pond));
    if (!self) {
        free(pad_locations);
        free(fibonacci_numbers);
        free(min_hops);
        return NULL;
    }
    self->pad_locations = pad_locations;
    self->fibonacci_numbers = fibonacci_numbers;
    self->min_hops = min_hops;
    self->width = width;
    return self;
}

void initialize_pond(Pond self, int A[]) {
    fill_fibonacci_numbers(self);
    init_min_hops(self);
    init_pad_locations(self, A);
}

void fill_fibonacci_numbers(Pond self) {
    int next_fib_num;
    int i;

    self->fibonacci_numbers[0] = 1;
    self->fibonacci_numbers[1] = 2;
    if (self->width <= 1) {
        return;
    }
    for (i = 1; i + 1 < self->width; i++) {
        next_fib_num = self->fibonacci_numbers[i - 1] + self->fibonacci_numbers[i];
        self->fibonacci_numbers[i + 1] = next_fib_num;
    }
}

void init_min_hops(Pond self) {
    int i;

    for (i = 0; i < self->width; i++) {
        self->min_hops[i] = -1;
    }
}

void init_pad_locations(Pond self, int A[]) {
    int i;

    for (i = 0; i < self->width - 1; i++) {
        self->pad_locations[i] = A[i];
    }
    self->pad_locations[self->width - 1] = 1; // Crossed the pond.
}

int minimize_hops(Pond self) {
    int i;

    for (i = 0; i < self->width; i++) {
        fill_min_hops(self, i);
    }
    return self->min_hops[self->width - 1];
}

void fill_min_hops(Pond self, int i) {
    int min = self->width + 10;
    int previous;
    int fib_num;
    int j = 0;

    if (!self->pad_locations[i]) {
        return;
    }

    while (j < self->width && (fib_num = self->fibonacci_numbers[j]) <= i + 1) {
        previous = i - fib_num;
        if (previous == -1) {
            self->min_hops[i] = 1;
            return;
        }
        if (self->pad_locations[previous] && 
            self->min_hops[previous] > -1) {
            if (self->min_hops[previous] + 1 < min) {
                min = self->min_hops[previous] + 1;
            }
        }
        j += 1;
    }
    self->min_hops[i] = ( min == self->width + 10 ) ? -1 : min;
}

void print_pond(Pond self) {
    printf("The pond has width: %d\n", self->width);
    printf("The pad locations are:\n");
    print_pad_locations(self);
    printf("\nThe fibonacci numbers are:\n");
    print_fibonacci_numbers(self);
    printf("\nThe min_hops array is:\n");
    print_min_hops(self);
}

void print_pad_locations(Pond self) {
    int i;

    for (i = 0; i < self->width; i++) {
        printf("%d", self->pad_locations[i]);
        if (i < self->width - 1) {
            printf(", ");
        }
    }
}

void print_fibonacci_numbers(Pond self) {
    int i;

    for (i = 0; i < self->width; i++) {
        printf("%d", self->fibonacci_numbers[i]);
        if (i < self->width - 1) {
            printf(", ");
        }
    }
}

void print_min_hops(Pond self) {
    int i;

    for (i = 0; i < self->width; i++) {
        printf("%d", self->min_hops[i]);
        if (i < self->width - 1) {
            printf(", ");
        }
    }
}


int solution(int A[], int N) {
    Pond pond = new_pond(N);
    int min_hops;

    initialize_pond(pond, A);
    min_hops = minimize_hops(pond);
    return min_hops;
}

int main() {
    int A[] = {
        0,
        0,
        0,
        1,
        1,
        0,
        1,
        0,
        0,
        0,
        0
    };
    int N = 11;
    int s = solution(A, N);

    printf("The solution is: %d\n", s);
}
