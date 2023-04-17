#include <stdio.h>
#include <stdlib.h>
#include "array_sort_lib.h"

void stampa_array(int a[], int);

int main(void)
{
    int *array;
    int op;
    int n, i;
    
    printf("Inserisci il numero di elementi dell'array:\n");    
    scanf("%d", &n);

    array = (int *)calloc(n, sizeof(int));
    
    i= 0;
    while (i < n)
    {
        printf("Inserisci il %d elemento:\n", i);
        scanf("%d", &array[i]);
        i++;
    }


    printf("Scegli che algoritmo provare:\n");
    printf("1-Insertsort\n2-Selectsort\n3-Bubblesort\n4-Mergesort\n5-Quicksort\n6-Heapsort\n");
    
    scanf("%d", &op);

    stampa_array(array, n);
    putchar('\n');
    switch(op)
    {
        case 1:
            insertsort(array, n);
            break;
        case 2:
            selectsort(array, n);
            break;
        case 3:
            bubblesort(array, n);
            break;
        case 4:
            mergesort(array, 0, n);
            break;
        case 5:
            quicksort(array, 0, n-1);
            break;
        case 6:
            int b[n+1];
            b[0] = 0;
            i = 1;
            while (i < n+1)
            {
                b[i] = array[i-1];
                i++;
            }
            heapsort(b, n+1);
            i = 0;
            while (i < n)
            {
                array[i] = b[i+1];
                i++;
            }
            break;
    }

    stampa_array(array, n);
    putchar('\n');

    return(0);
}

void stampa_array(int a[], int n)
{
    int i;

    for(i=0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
