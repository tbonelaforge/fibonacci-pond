#include <stdio.h>

#include "pond.h"


int solution(int A[], int N) {
    Pond pond = new_pond(N);
    int min_hops;

    initialize_pond(pond, A);
    printf("After initializing the pond, it looks like:\n");
    print_pond(pond);
    min_hops = minimize_hops(pond);
    printf("After minimizing_hops, the pond looks like:\n");
    print_pond(pond);
    return min_hops;
}

int main() {

    int N;

    printf("About to test a pond with width 7:\n");

    int A[] = {
        1, 0, 1, 1, 0, 1
    };
    int minimum;
    Pond test_pond;
    
    N = 6;
    printf("About to construct a new pond...\n");
    test_pond = new_pond(N);
    printf("About to initialize_pond\n");
    initialize_pond(test_pond, A);
    printf("After initialization, the pond looks like:\n");
    print_pond(test_pond);
    printf("About to minimize hops...\n");
    minimum = minimize_hops(test_pond);
    printf("The minimum hops are: %d\n", minimum);

    printf("About to test a pond with width 8:\n");

    int B[] = {
        1, 0, 1, 1, 0, 1, 0
    };
    N = 7;
    printf("About to construct a new pond...\n");
    test_pond = new_pond(N);
    printf("About to initialize_pond\n");
    initialize_pond(test_pond, B);
    printf("After initialization, the pond looks like:\n");
    print_pond(test_pond);
    printf("About to minimize hops...\n");
    minimum = minimize_hops(test_pond);
    printf("The minimum hops are: %d\n", minimum);

    int C[] = {
        
    };
    N = 0;
    printf("ABout to try and use an empty array...\n");
    int c_solution = solution(C, N);
    printf("The solution is: %d\n", c_solution);

    int D[] = {
        1
    };
    N = 1;
    printf("About to try and use an array consisting of only 1's\n");
    int d_solution = solution(D, N);
    printf("the solution is: %d\n", d_solution);

    int E[] = {
        1,
        1
    };
    N = 2;
    printf("About to try and use an array consisting of two 1's\n");
    int e_solution = solution(E, N);
    printf("the solution is: %d\n", e_solution);

    int F[] = {
        1,
        1,
        1
    };
    N = 3;
    printf("About to try and use an array consisting of three 1's\n");
    int f_solution = solution(F, N);
    printf("the solution is: %d\n", f_solution);

    int AA[] = {
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
    N = 11;
    int s = solution(AA, N);

    printf("The solution is: %d\n", s);


}
