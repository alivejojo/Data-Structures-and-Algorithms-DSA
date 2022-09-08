#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n; //number of edges and nodes
#define INFINITY 9999
int count_R;
int count_S;
int find_closest_node(int S[], int distance[])
{
    int min_distance = 2000000;
    int closest_node = -1;

    for(int i=0;i<n;i++)
    {
        //loop over all nodes
        //whichever is not present in S and whose distance from src <=2000000
        //is the closest node.. 
        if(S[i]==0 && distance[i]<=min_distance)
        {
            min_distance = distance[i];
            closest_node = i;
        }
        return closest_node;
    }
}

void print_path(int path[], int j)
{
    if(path[j]==-1)
    {
        // printf("%d ", j);
        return;
    }
    print_path(path, path[j]);
    printf("%d ",j);
}


void dijkstra(int adj[n][n], int target)
{
    int cost[n][n], distance[n], pred[n];
    int visited[n], count, mindistance, nextnode, i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(adj[i][j]==0)
                cost[i][j]= INFINITY;
            else
                cost[i][j] = adj[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        distance[i] = cost[0][i];
        pred[i] = 0;
        visited[i]=0;
    }
    distance[0] = 0;
    visited[0]=1;
    count=1;
    while(count<n-1)
    {
        mindistance = INFINITY;
        for(i=0;i<n;i++)
        {
            if(distance[i]<mindistance &&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
            
        }
        visited[nextnode]=1;
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(mindistance+cost[nextnode][i]<distance[i])
                {
                    distance[i] = mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
            }
        }
        count++;
    }
    int final_output_path[n];
    int in=1;
    final_output_path[0]=target;
    if(target!=0)
    {
        printf("%d ", distance[target]);
        // printf("\nPath = %d",target);
        j=target;
        do
            {
                j=pred[j];
                // printf("<-%d",j);
                final_output_path[in] = j;
                in++;
            } while (j!=0);

    }
    for(i=in-1;i>0;i--)
    {
        // printf("%d", final_output_path[i]);
    
        // printf("count_r = %d !", count_R);
        if(final_output_path[i]==0)
        {
            printf("RC ");
        }
        else
        {
            if(final_output_path[i]>0 && final_output_path[i]<count_R)
                printf("R%d ",final_output_path[i]);

            else
                printf("S%d\n", n-final_output_path[i]);

        }

    }
    printf("S%d\n",n-target);
    
}
int main()
{
    scanf("%d",&n);
    count_R =0;
    count_S=0;
    int adj[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            adj[i][j] = 0;
    }

    int dist[n]; //distance of every node from RC
    int visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;//only bool =1 when new Router is added
    }
     
    char input[200];
    fgets(input,200,stdin);
    

    while(input[0]!='T')
    {
        
        if(input[0]=='R')
        {
            
            int c=0;
            int i1=0,i2=0;
            char* token = strtok(input, " ");
        while(token!=NULL)
        {   
            c++; //counts the tokens
            if(c!=3)
            {
                if(token[0]=='R')
                {
                    // count_R++;
                    if(token[1]=='C')
                    {    
                        visited[0]=1;
                        if(c==1)
                            i1=0;
                        if(c==2)
                            i2=0;
                    }
                    
                    else
                    {
                        char temp[100];
                        int i=1;
                        while(token[i]!='\0')
                        {
                            temp[i-1] = token[i];
                            i++;
                        }
                        temp[i-1]='\0';
                        visited[atoi(temp)]=1;
                        if(c==1)
                            i1 = atoi(temp);
                        if(c==2)
                            i2 = atoi(temp);
                    }
                }

                if(token[0]=='S')
                {
                    
                    char temp[100];
                        int i=1;
                        while(token[i]!='\0')
                        {
                            temp[i-1] = token[i];
                            i++;
                        }
                        temp[i-1]='\0';
                    if(c==1)
                        i1 = n-atoi(temp);
                    if(c==2)
                        i2 = n-atoi(temp);

                }
            }
    //         for(int i=0;i<n;i++)
    // {
    //     count_R = count_R + visited[i];
    //     // printf("%d ", visited[i]);
    // }
    // count_S = n-count_R;
            else
            {
                //till now i1,i2 have been alloted
                int x = atoi(token);
                adj[i1][i2] = x;
                adj[i2][i1] = x;
            }
            token = strtok(NULL, " ");
        }
        }
        
        if(input[0]=='S')
        {
            // printf("R =%d,S = %d\n", count_R, count_S);
        
        for(int i=0;i<n;i++)
        {
            count_R = count_R + visited[i];
            // printf("%d \n", visited[i]);
        }
        count_S = n-count_R;
        // printf("R =%d,S = %d\n", count_R, count_S);
            char temp[100];
            int i=1;
            while(input[i]!='\0')
            {
                temp[i-1] = input[i];
                i++;
            }
            int target = n-atoi(temp);
            dijkstra(adj, target);
        }

        fgets(input,200,stdin);
        continue;
    }
    
  
    return 0;
}
