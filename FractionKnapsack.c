#include<stdio.h>

int main()
{
    float profit[20], weight[20], ratio[20], x[20], temp, tp=0;
    int n,capacity,k,l;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter profits data set: ");
    for(int i=0; i<n; i++)
    {
        scanf("%f", &profit[i]);
    }
    printf("Enter weight data set: ");
    for(int i=0; i<n; i++)
    {
        scanf("%f", &weight[i]);
    }

    printf("Enter the capacity: ");
    scanf("%d", &capacity);

    for(int i=0; i<n; i++)
    {
        ratio[i] = 0.0;
        ratio[i] = profit[i]/weight[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }

    for(k=0; k<n; k++)
    {
        if(capacity < weight[k])
        {
            break;
        }
        else
        {
            x[k] = 1.0;
            tp = tp + profit[k];
            capacity = capacity - weight[k];
        }
    }

    tp = tp + (profit[k]/weight[k])*capacity;

    printf("Maximum profit: %f", tp);


    return 0;
}
