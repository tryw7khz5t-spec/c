#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;

    printf("Введите размер массива: ");
    scanf("%d", &n);

    float array[n];   
    float sum = 0;
    float product = 1;
    int maxindex = 0;
    int minindex = 0;

    for (int i = 0; i < n; i++)
    {
        printf("array[%d] = ", i);
        scanf("%f", &array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (array[i] > 0)
        {
            sum += array[i];
        }

        if (fabs(array[i]) > fabs(array[maxindex]))
        {
            maxindex = i;
        }

        if (fabs(array[i]) < fabs(array[minindex]))
        {
            minindex = i;
        }
    }

    int first = minindex;
    int last = maxindex;

    if (maxindex < minindex)
    {
        first = maxindex;
        last = minindex;
    }

    for (int i = first + 1; i < last; i++)
    {
        product *= array[i];
    }

    printf("\nСумма положительных элементов = %.2f\n", sum);
    printf("Произведение элементов = %.2f\n", product);


    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] < array[j])
            {
                float temporary = array[i];
                array[i] = array[j];
                array[j] = temporary;
            }
        }
    }

    printf("\nМассив по убыванию:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", array[i]);
    }

    printf("\n");

    return 0;
}