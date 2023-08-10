#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i;
    unsigned int sum = 0;

    scanf("%d", &N);

    unsigned *numbers= (unsigned *)malloc(N * sizeof(unsigned));
    for (i = 0; i < N; i++) {
        scanf("%u", &numbers[i]);
    }
    for (i = 0; i < N; i++) {
        sum += numbers[i];
    }

    printf("%u", sum/N); 
    free(numbers);
    return 0;
}
