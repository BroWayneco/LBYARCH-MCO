#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

// For asm
extern float dot_product_asm(float* A, float* B, int n);
clock_t start, end;

void randomizer(int n, float A[], float B[], float max_value) {
    for (int i = 0; i < n; i++) {
        A[i] = ((float)rand() / RAND_MAX) / max_value;
        B[i] = ((float)rand() / RAND_MAX) / max_value;
    }
}

void dot_product_c(float A[], float B[], int n, float* sdot_c, double* time_c) {

    start = clock();
    // Adding the numbers in A[] and B[] and putting the data to sdot_c
    for (int i = 0; i < n; i++) {
        *sdot_c += A[i] * B[i];
    }
    end = clock();

    *time_c = ((double)end - start) / CLOCKS_PER_SEC;
}

void dot_product_assembly(float A[], float B[], int n, float* sdot_asm, double* time_asm) {

    start = clock();
    *sdot_asm = dot_product_asm(A, B, n);
    end = clock();
    *time_asm = ((double)end - start) / CLOCKS_PER_SEC;
}

void display_asm(int n) {
    printf("\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    printf("-_-_-_-_-_-_-_Dot Product Using Assembly Kernel # %d_-_-_-_-_-_-_-\n", n);
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
}

void display_c(int n) {
    printf("\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    printf("-_-_-_-_-_-_-_-_-_Dot Product Using C Kernel # %d_-_-_-_-_-_-_-_-_-\n", n);
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
}

int main() {
    // Initialize the time
    double time_asm = 0.0;
    double time_c = 0.0;
    double ave_asm = 0.0;
    double ave_c = 0.0;

    // Initialize Sanity Check
    float sanity_check = 0.0;

    // SDot in Assembly and C
    float sdot_asm = 0.0;
    float sdot_c = 0.0;

    // Number of Values in the array
    int n = 0;
    float max_value = 10.0;

    // Initialize the number of elements in the array
    printf("Type in the power that you want to test: ");
    int result = scanf("%d", &n);
    if (result != 1) {
        printf("Failed to read input.\n");
        return 1; // Or handle the error in another appropriate way
    }
    n = (int)pow(2, n);

    // Initializing array
    float* A = (float*)malloc(n * sizeof(float));
    float* B = (float*)malloc(n * sizeof(float));

    if (A == NULL || B == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < 30; i++) {
        sdot_asm = 0.0;
        sdot_c = 0.0;
        randomizer(n, A, B, max_value);
        display_asm(i + 1);
        dot_product_assembly(A, B, n, &sdot_asm, &time_asm);
        ave_asm += time_asm;
        printf("Time Used by Assembly: %f\n", time_asm);
        printf("Answer for ASM: %f\n", sdot_asm);
        display_c(i + 1);
        dot_product_c(A, B, n, &sdot_c, &time_c);
        ave_c += time_c;
        printf("Time Used by C: %f\n", time_c);
        printf("Answer for C: %f\n", sdot_asm);
        printf("\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
        sanity_check = (sdot_asm / sdot_c) * 100;
        printf("Percent of Correctness From C and Assembly: %2f%%\n", sanity_check);
    }
    printf("\n\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    printf("Average Time in Assembly: %f\n", (ave_asm / 30.0));
    printf("Average Time in C: %f\n", (ave_c / 30.0));

    free(A);
    free(B);

    return 0;
}
