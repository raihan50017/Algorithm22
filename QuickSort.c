#include<stdio.h>

void swap(int *a, int *b);

int partition(int low, int high, int arr[])
{

    int i = (low -1);
    int pivot = arr[high];
    for(int j=low; j<high; j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[high], &arr[i+1]);


    return i+1;

}

void quickSort(int low, int high, int arr[])
{

    if(low<high)
    {
        int pi = partition(low, high, arr);
        quickSort(low, pi-1, arr);
        quickSort(pi+1, high, arr);
    }

    return;
}

int main()
{
    int arr[] = { 90, 40, 52, 60, 39};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array: ");
    for(int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    quickSort(0, size-1, arr);
    printf("Array after sorting: ");
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
