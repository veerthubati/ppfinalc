
#include <stdio.h>
#include <stdlib.h>

int partition(int * a, int p, int r)
{
    int lt[r-p], gt[r-p],  i,  j,  key = a[r],  lt_n = 0, gt_n = 0;

    for(i = p; i < r; i++){
        if(a[i] < a[r]){
            lt[lt_n++] = a[i];
        }else{
            gt[gt_n++] = a[i];
        }
    }

    for(i = 0; i < lt_n; i++){
        a[p + i] = lt[i];
    }

    a[p + lt_n] = key;

    for(j = 0; j < gt_n; j++){
        a[p + lt_n + j + 1] = gt[j];
    }

    return p + lt_n;
}

void quicksort(int * a, int p, int r)
{
    int div;

    if(p < r){
        div = partition(a, p, r);
        {
            quicksort(a, p, div - 1);
            quicksort(a, div + 1, r);

        }
    }
}

int main(void)
{
    int a[10] = {6, 11, 17, 9, 8, 5, 4, 54, 23, 0};
    int i;

    quicksort(a, 0, 9);

    for(i = 0;i < 10; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}
