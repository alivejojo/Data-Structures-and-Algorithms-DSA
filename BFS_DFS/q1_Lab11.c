#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #include<math.h>

// typedef struct node
// {   int val;
//     int clr;
//     struct node* pred;
//     struct node* next;
//     int dist;
// }NODE;
int max_depth_dist = 0;
int max_depth_x = -1;
int max_depth_y = -1;

int sqrt(int x)
{
    int i =0;
    double root = 1;
    int ans;
    while(1)
    {
        i++;
        root = (x/root + root)/2;
        if (i==x+1) {break;}

    }
    ans = root;
    return ans;
}
void DFS(int** arr, int x, int y, int N, int M)
{
    if(x<0 || y<0 || x>N || y>M || arr[x][y]==1)
    {
        return;
    }
    if(arr[x][y]==0)
    {
    arr[x][y] = 2;
    DFS(arr, x-1,y,N,M);
    DFS(arr, x-1,y+1,N,M);
    DFS(arr, x,y+1,N,M);
    DFS(arr, x+1,y+1,N,M);
    DFS(arr, x+1,y,N,M);
    DFS(arr, x+1,y-1,N,M);
    DFS(arr, x,y-1,N,M);
    DFS(arr, x-1,y-1,N,M);
    }

}
int distance (int x1,int y1,int x2,int y2 )
{
return sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
}

void max_depth(int** arr, int x, int y, int N, int M)
{
            // printf("hey5");
            // printf("x = %d, y = %d\n" , x,y);

    for(int i =0;i<N;i++)
    {
        // prinf("yo1");
        for(int j = 0;j<M;j++)
        {
            // printf("yo2");
            if(arr[i][j]==2)
            {
                // printf("yo3");
                    // printf("i = %d, j = %d, distance = %d\n", i,j,distance(x,y,i,j));

                if(max_depth_dist < distance(x,y,i,j))
                {
                    // printf("yo4");
                    // printf("i = %d, j = %d, distance = %d\n", i,j,distance(x,y,i,j));
                    max_depth_dist = distance(x,y,i,j);
                    max_depth_x = i;
                    max_depth_y = j;
                }
            }
        }
    }

    // printf("%d %d\n", max_depth_x, max_depth_y);
}


int main()
{
    int N,M;
    scanf("%d",&N);
    scanf("%d",&M);

    // dynamically create an array of pointers of size N
    int **arr = (int**)malloc(N*sizeof(int*));

    // dynamically allocate memory of size M for each row
    for (int i=0;i<M;i++) 
    {
        arr[i] = (int *)malloc(M * sizeof(int));
    }

    for (int i =0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int c;
            scanf("%d",&c);
            arr[i][j] = c;
        }
    }
    for (int i =0; i<N;i++)
    {
        if(arr[i][0]==0)
                DFS(arr,i,0,N,M);
        if(arr[i][M-1]==0)
                DFS(arr,i,M-1,N,M);
    }
    for (int j=0; j<M;j++)
    {
        if(arr[0][j]==0)
                DFS(arr,0,j,N,M);
        if(arr[N-1][j]==0)
                DFS(arr,N-1,j,N,M);
    }
    
    // printf("-----\n");
    // now we need to print the replaced and non replaced elements in sorted fashion
    int c1 =0;
    printf("Replaced\n");
    for(int i =0;i<N;i++)
    {
        for (int j =0;j<M;j++)
        {
            if(arr[i][j]==0)
            {
                
                c1++;
                printf("%d %d\n",i,j);
            }
        }
    }
    if(c1==0)
        printf("NULL\n");
    int c2 =0 ;
    printf("Not Replaced\n");
    for(int i=0;i<N;i++)
    {
        for (int j =0;j<M;j++)
        {
            if(arr[i][j]==2)
            {
                c2++;
                printf("%d %d\n",i,j);
            }
        }
    }
    if(c2==0)
        printf("NULL\n");
    //printing 
    // for (int i =0;i<N;i++)
    // {
    //     for(int j=0;j<M;j++)        
    //         printf("%d ",arr[i][j]);
    //     printf("%c",'\n');
    // }

    // now for maximum depth
    int flag =0;
    int x_=0;
    int y_=0;

    
    printf("Maximum Depth\n");
    for (int j=0;j<M;j++)
    {
        //checking first horizontal boundary
        if(arr[0][j]==2)
        {
            //max_depth()
            // printf("hey1");
            x_=0;
            y_=j;
            flag++;
            max_depth(arr, 0,j,N,M);
        }

        //checking last horizontal boundary
        else if(arr[N-1][j]==2)
        {
            // printf("hey2");
            flag++;
            x_=N-1;
            y_=j;

            //mex_depth()
            max_depth(arr, N-1,j, N,M);

        }
    }
    if (flag==0)
    {
    for(int i=0;i<N;i++)
    {
        //checking first vertical boundary
        if(arr[i][0]==2)
        {
            x_=i;
            y_=0;            
            // printf("hey3");
            max_depth(arr, i,0, N,M);


        }
        else if(arr[i][M-1]==2)
        {
            // printf("hey4");
            x_=i;
            y_=M-1;
            max_depth(arr, i,M-1, N,M);
        }
    }
    }
    if(max_depth_x==-1)
        printf("%d %d\n", x_, y_);

    else
        printf("%d %d\n", max_depth_x, max_depth_y);

    // for (int i =0;i<N;i++)
    // {
    //     for(int j=0;j<M;j++)        
    //         printf("%d ",arr[i][j]);
    //     printf("%c",'\n');
    // }






    return 0;
}
