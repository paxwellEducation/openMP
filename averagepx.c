#include <stdio.h>
#include <omp.h>
#include <stdlib.h>


int main() {
    int N, i;
    unsigned int sum = 0;

    int num_threads = omp_get_max_threads();
    omp_set_num_threads(num_threads);
    // printf("Number of threads: %d\n", num_threads);
    scanf("%d", &N);


    unsigned *numbers;
    numbers = (unsigned *) malloc(N * sizeof(unsigned));
    unsigned int *local_sums;
    local_sums = (unsigned int *) malloc(num_threads * sizeof(unsigned int));

    for (i = 0; i < N; i++) {
        scanf("%u", &numbers[i]);
    }

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int chunk_size = N / num_threads;
        int start = tid * chunk_size;
        int end = (tid == num_threads - 1) ? N : start + chunk_size;  // handle the case when N is not divisible by num_threads

        unsigned int local_sum = 0;
        for (int local_i = start; local_i < end; local_i++) { // Notice the use of local_i instead of i
        local_sum += numbers[local_i];
        }
        local_sums[tid] = local_sum;

    }
    for (i = 0; i < num_threads; i++) {
        sum += local_sums[i];
    }
    // #pragma omp parallel for reduction(+:sum) 
    // for (i = 0; i < N; i++) {
    //     sum += numbers[i];
    // }
    
    printf("%u", sum/N); 
    free(numbers);
    free(local_sums);
    return 0;
}

//gcc -fopenmp averagepx.c -o averagepx