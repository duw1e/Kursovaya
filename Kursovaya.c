#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX 100

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, i, j, k, m;
    double matrix[MAX][MAX];
    double array[MAX * (MAX - 1) / 2];

    srand(time(NULL));

    printf("Введите размерность матрицы: ");
    scanf_s("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Ошибка! Размерность должна быть от 1 до 100.\n");
        return 1;
    }

    m = n * (n - 1) / 2;

    printf("\nИсходная матрица:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrix[i][j] = (double)rand() / RAND_MAX * 20 - 10;
            printf("%8.2f", matrix[i][j]);
        }
        printf("\n");
    }

    k = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i + j < n - 1)
            {
                array[k] = matrix[i][j];
                k++;
            }
        }
    }

    printf("\nОдномерный массив:\n");

    for (i = 0; i < m; i++)
    {
        printf("%.2f ", array[i]);
    }

    printf("\n");

    return 0;
}