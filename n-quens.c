#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define v 4
int x[5];


bool place(int k, int i)
{
    for(int j=1; j<=k-1; j++)
    {
        if(x[j]==i || fabs(x[j]-i) == fabs(j-k))
        {
            return false;
        }
    }
    return true;
}

void nQueen(int k)
{
    for(int i=1; i<=v; i++)
    {
        if(place(k, i))
        {
            x[k] = i;
            if(k==v)
            {
                for(int i=1; i<=v; i++)
                {
                    printf("%d ", x[i]);
                }
                printf("\n");
            }
            else{
                nQueen(k+1);
            }
        }
    }
}

int main()
{
    nQueen(1);
    return 0;

}
