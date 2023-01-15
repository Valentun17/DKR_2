#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void sort(int *sortable_matrix, int *result_matrix, const int matrix_size);
int once_sort(int *sortable_matrix, const int matrix_size);
void array_fill(int *array, const int array_size);
void array_print(int *array, const int array_size);
int rnd_diapazon(const int left, const int right);
void swap(int *a, int *b);

#define MATRIX_SIZE 5

int main()
{
    srand(time(NULL)); //"rnd" begin for func rand()
    int A[MATRIX_SIZE][MATRIX_SIZE] = {0};
    int B[MATRIX_SIZE][MATRIX_SIZE] = {0};

    array_fill(&A[0][0], MATRIX_SIZE);
    array_print(&A[0][0], MATRIX_SIZE);

    sort(&A[0][0], &B[0][0], MATRIX_SIZE);

    array_print(&B[0][0], MATRIX_SIZE);

    getch();
    return 0;
}

void array_fill(int *array, const int array_size)
{
    int up_border = 0;
    up_border = rnd_diapazon(10, 15);

    for (int i = 0; i < array_size; i++)
        for (int j = 0; j < array_size; j++)
            array[i * array_size + j] = rnd_diapazon(0, up_border); // fill array by "rnd" numbers
}

void array_print(int *array, const int array_size)
{
    printf("%2d  ", 0);
    for (int j = 1; j <= array_size; j++)
        printf(" %5d", j);
    printf("\n");
    for (int i = 0; i < array_size; i++)
    {
        printf("%2d||", i + 1);
        for (int j = 0; j < array_size; j++)
            printf(" %5d", array[i * array_size + j]);
        printf(" ||\n");
    }
    printf("\n");
}

int rnd_diapazon(int left, int right)
{
    return rand() % (right - left + 1) + left;
}

int once_sort(int *sortable_matrix, const int matrix_size)
{
    int * elem1 = &sortable_matrix[0], * elem2 = 0;
    for (int i = 1; i < matrix_size; i++)
    {
        elem2 = &sortable_matrix[i * matrix_size + i];
        if (*elem2 > *elem1)
        {
            swap(elem1, elem2);
            return 1; // if mairix sorted not fully, return "1"
        }
        elem1 = elem2;
        //elem2 = 0;
    }
    return 0; // if sorted all mairix, return "0"
}


void sort(int *sortable_matrix, int *result_matrix, const int matrix_size)
{
    for (int i = 0; i < matrix_size * matrix_size; i++)
        result_matrix[i] = sortable_matrix[i];
    while (once_sort(&result_matrix[0], matrix_size))
        ;
}

void swap(int *a, int *b)
{
    int pp = *b;
    *b = *a;
    *a = pp;
}
