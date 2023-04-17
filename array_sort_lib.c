#include <stdio.h>
#include <stdlib.h>

void insertsort(int a[], int);
void selectsort(int a[], int);
void bubblesort(int a[], int);
void mergesort(int a[], int, int);
void fondi(int a[], int, int, int);
void copia(int a[], int sx1, int dx1, int b[], int sx2, int dx2);
void quicksort(int a[], int, int);
void heapsort(int a[], int);
void setaccia_heap(int a[], int, int);

void insertsort(int a[], int n)
{
    int i, j, tmp;
    
    /*Sequenza di destinazione a[0]-a[0], destinazione = a[1]-a[n-1]*/
    for(i=1; i < n; i++)
    {   
        /*Valore da inserire: a[i] = a[1]*/
        for(tmp = a[i], j=i-1; 
            j >= 0 && a[j] > tmp; /*Scambiare il valore con quelli che lo precedono, finchè maggiori*/ 
            j--)
        {   
            a[j+1] = a[j];
            a[j] = tmp;
        }
    }
}

void selectsort(int a[], int n)
{
    int i, j, min, tmp;
    
    for(i=0; i < n; i++)
    {   
        min = i;

        for(j=i+1; j < n; j++)
        {
            if(a[j] < a[min])
              min = j;
        }
        
        tmp = a[min];
        a[min] = a[i];
        a[i] = tmp;
    }
}

void bubblesort(int a[], int n)
{
    int i, j, tmp;

    for (i=1; i < n; i++)
    {
        for(j=n-1; j >= i; j--)
        {
            if(a[j] < a[j-1])
            {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
}

void mergesort(int a[], int sx, int dx)
{
    int mx;

    if (sx < dx)
    {
        mx = (sx + dx) / 2;
        mergesort(a, sx, mx);
        mergesort(a, mx+1, dx);

        fondi(a, sx, mx, dx);
    }
}

void fondi(int a[], int sx, int mx, int dx)
{
    int *b, i, j, k;

    b = (int *)calloc(dx+1, sizeof(int));

    for(i = sx, j = mx+1, k = sx; ((i <= mx) && (j <= dx)); k++)
    if (a[i] <= a[j])
    {
        b[k] = a[i];
        i++;
    }
    else
    {
        b[k] = a[j];
        j++;
    }

    if (i <= mx)
       copia(a, i, mx, a, k, dx);
    
    copia(b, sx, k-1, a, sx, k-1);
    free(b);
}

void copia(int a[], int sx1, int dx1, int b[], int sx2, int dx2)
{
    int i1, i2;

    for (i1 = sx1, i2 = sx2; (i1 <= dx1); i1++, i2++)
    b[i2] = a[i1];
}

void quicksort(int a[], int sx, int dx)
{
    int pivot, tmp, i, j;

    /*Creare partizione*/
    for (pivot = a[(sx + dx) / 2], i = sx, j = dx; i <= j;)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--; 
        
        if (i <= j)
        {
            if (i < j)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }

            i++;
            j--;
        }
    }

    /* Ordina le due parti */
    if (sx < j)
       quicksort(a, sx, j);
    
    if (i < dx)
       quicksort(a, i, dx);
}

void heapsort(int a[], int n)
{   
    int tmp, sx, dx;

    /*Trasformare l'array in un heap*/
    for (sx = n/2; sx >= 1; sx--)
        setaccia_heap(a, sx, n-1);

    /*Ordinare l'array*/
    for (dx = n-1; dx > 1; dx--)
    {
        tmp = a[1];
        a[1] = a[dx];
        a[dx] = tmp;
        
        /*Fare in modo che il nuovo ordine sia ancora un heap*/
        setaccia_heap(a, 1, dx-1);
    }
}

void setaccia_heap(int a[], int sx, int dx)
{
    int testa, i, j;
    
    for (testa = a[sx], i = sx, j = 2 * i; /*Nodo padre = primo elemento dell'array*/
         j <= dx;)  /*Termina il loop alla fine dell'array*/
    {   
        /*Verificare quale dei due nodi figli è il maggiore (e se ce ne sono due o uno solo)*/
        if (j < dx && a[j+1] > a[j])
           j++;
        
        /*Verificare se il nodo figlio maggiore è più grande del nodo padre*/
        if (testa < a[j])
        {   
            /*Se si, il nodo figlio maggiore diventa il nodo padre*/
            a[i] = a[j];
            i = j;
            j = 2 * i;
        }
        else
            j = dx + 1; /*Se no, l'array è già un heap, si pone j=condizione di terminazione*/
    }
    
    /*Porre l'ex nodo padre come nodo figlio*/
    if (i != sx)
        a[i] = testa;
}
