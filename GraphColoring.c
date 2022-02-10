#include<stdio.h>
#include<conio.h>

int m, n; // m is the number of color & n is the number of vertices
int count=0; // Total number of solution counter
int g[50][50]; // Adjacency matrix array of a graph
int x[50]; // Vertices array whose index represents individual vertex & whose value represents assigned legal color for individual vertex
void nextValue(int k);
void GraphColoring(int k);

int main()
{
    int i, j;
    int temp;
    printf("Enter the number of nodes: " );
    scanf("%d", &n);
    printf("\nEnter the number of colors: " );
    scanf("%d", &m);
    printf("\nEnter Adjacency Matrix:\n");
    for(i=1; i<=n; i++) //Adjacency matrix of a graph
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }

    printf("\nPossible Solutions are:\n");
    GraphColoring(1);
    printf("\nTotal number of solution: %d\n",count);
    getch();

}

void GraphColoring(int k)
{
    int i;
    while(1)
    {
        nextValue(k); //Assign to x[k] a legal color
        if(x[k]==0)  // No new color possible
        {
            return;
        }
        if(k==n) // At most m color have been used to color the n vertices
        {
            for(i=1; i<=n; i++) //Write a legal solution  solution
            {
                printf("%d ", x[i]);
            }
            count++;
            printf("\n");
        }
        else
        {
            GraphColoring(k+1);
        }
    }

}

void nextValue(int k)
{
    int j;
    while(1)
    {
        x[k]=(x[k]+1)%(m+1); // Next highest color
        if(x[k]==0)  // All color have been used
        {
            return;
        }
        for(j=1; j<=n; j++)  // Check if this color distinct from adjacent collor
        {
            if(g[k][j]==1&&x[k]==x[j])
                break;
        }
        if(j==(n+1)) // New color found
        {
            return;
        }
    }
}
