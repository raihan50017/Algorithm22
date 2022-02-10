#include<stdio.h>
int w[] = {5,7,10,12,15,18,20};
int m=35;
int x[7];

void SumOfSubset(int s, int k, int r)
{
    x[k] = 1;
    if(s+w[k] == m)
    {
        for(int i=0; i<=k; i++)
        {
            if(x[i]==1)
            {
                printf("%d ", w[i]);
            }
        }
        printf("\n");
    }
    else if(s+w[k]+w[k+1] <= m)
    {
        SumOfSubset(s+w[k], k+1, r-w[k]);
    }
    if(s+r-w[k]>=m && s+w[k+1]<=m)
    {
        x[k] = 0;
        SumOfSubset(s, k+1, r-w[k]);
    }
}

int main()
{
    SumOfSubset(0, 0, 87);
    return 0;
}

