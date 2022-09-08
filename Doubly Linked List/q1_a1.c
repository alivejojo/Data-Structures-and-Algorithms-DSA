#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct node{
    char url[100]; //character array
    struct node *previous;
    struct node *next;
}NODE;

NODE* head = NULL;


void V(char* URL)
{
    char temp_url[100];
    int i = 0;
    NODE* newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->next = NULL;
    newnode->previous = NULL;
  
    while(*(URL+i)!='\0')
    {
        temp_url[i] = *(URL+i);
        i++;
    }
    temp_url[i] = '\0';

    strcpy(newnode->url, temp_url);

    if(head==NULL)
    {
        head = newnode;       
    }
    else
    {
        newnode->previous = head;
        head->next = newnode;
        head = newnode;       
    }

    //print statements
    if(head->previous == NULL)
        printf("none ");
    //the first print
    else
    {   char temp_str[100];
        strcpy(temp_str, (head->previous)->url);
        printf("%s ", temp_str);
    }

    printf("%s", head->url); 
   
    if(head->next == NULL)
    {   
        printf(" none\n");}
    else
    {char temp_str[100];
        strcpy(temp_str, (head->next)->url);
        printf(" %s\n", temp_str);    
    }
}

void B(int N)
{   

    NODE* temp = head;
    int i = 0;
    if(head==NULL)
    {
        printf("%d back not possible\n", N);
        return;
    }
    
    while(temp->previous!=NULL)
    {
        temp = temp->previous;
        i++;
    }
    
    if(N<=i)
    {
        
        for(int j = 0;j<N;j++)
        {   
            head = head->previous;
           
        }
    }
    else
    {   printf("%d back not possible\n", N-i);
        for(int j =0;j<i;j++)
            head = head->previous;
            
    }
    
    if(head->previous == NULL)
        printf("none ");
    else
    {   char temp_str[50];
        strcpy(temp_str, (head->previous)->url);
        printf("%s ", temp_str);
    }

    printf("%s", head->url); 
   
    if(head->next == NULL)
    {   
        printf(" none\n");}
    else
    {
        char temp_str[50];
        strcpy(temp_str, (head->next)->url);
        printf(" %s\n", temp_str);    
    }
    
}

void F(int N)
{
    if(head==NULL)
    {
        printf("%d forward not possible\n", N);
        return;
    }
    NODE* temp = head;
    int i =0;
    while(temp->next!=NULL)
    {
        temp = temp->next;
        i++;
    }
    
    if(N<=i)
    {
        
        for(int j = 0;j<N;j++)
        {   
            head = head->next;
           
        }
    }
    else
    {   printf("%d forward not possible\n", N-i);
        for(int j =0;j<i;j++)
            head = head->next;
            
    }
    
    //print statements;
    if(head->previous == NULL)
        printf("none ");
    else
    {   char temp_str[100];
        strcpy(temp_str, (head->previous)->url);
        printf("%s ", temp_str);
    }

    printf("%s", head->url); 
   
    if(head->next == NULL)
    {   
        printf(" none\n");}
    else
    {
        char temp_str[100];
        strcpy(temp_str, (head->next)->url);
        printf(" %s\n", temp_str);    
    }
}

void Q(int N)
{
    if(head==NULL)
    {
        printf("none\n");
        return;
    }
    NODE* temp = head;
    if(N<0)
    {   
        int i =0;
        while(temp->previous!=NULL)
        {
            temp = temp->previous;
            i++;
        }
        //i stores how many steps you can actually go backward
        NODE* temp2 = head;
        if(((-1)*N)<=i)
        {   int j =0;
            // printf("HELLO/ AT 183");
            while(N++)
            {
                // printf("HELLO AT 186");
                temp2 = temp2->previous;
            }
            printf("%s\n",temp2->url);
        }
        else
            printf("none\n");
        
    } 
    else
    {   
        int i =0;
        while(temp->next!=NULL)
        {
            temp = temp->next;
            i++;
        }
        NODE* temp2 = head;
        //i stores how many steps you can actually go forward
        if(N<=i)
        {
          while(N--)
            { 
                // printf("HELLO AT 210");
                temp2 = temp2->next;
            }
            printf("%s\n",temp2->url);
            
        }
        else
            printf("none\n");
    }
    
}

void D(int N)
{
    if(head==NULL)
    {
        printf("none\n");
        return;
    }
    NODE* temp = head;
    if(N<0)
    {   
        int i =0;
        while(temp->previous!=NULL)
        {
            temp = temp->previous;
            i++;
        }
        //i stores how many steps you can actually go backward
        NODE* temp2 = head;
        if(((-1)*N)<=i)
        {   int j =0;
            while(N++)
            {
                temp2 = temp2->previous;
            }
            if(temp2->previous==NULL)
                (temp2->next)->previous = NULL;
            else
            {
                (temp2->next)->previous = temp2->previous;
                (temp2->previous)->next = temp2->next;
            }
        }
        else
            printf("none\n");
        
    } 
    else
    {   
        int i =0;
        while(temp->next!=NULL)
        {
            temp = temp->next;
            i++;
        }
        NODE* temp2 = head;
        if(N<=i)
        {
          while(N--)
            { 
                temp2 = temp2->next;
            }
            if(temp2->next==NULL)
                (temp2->previous)->next = NULL;
            else
            {
                (temp2->previous)->next = temp2->next;
                (temp2->next)->previous = temp2->previous;
            }
            
        }
        else
            printf("none\n");
    }
   
}

int main()
{
    char input[25] = "0000000000000000000000";
    while(input[0]!='E')
    {
        gets(input);
        if(input[0]=='V')
        {
            char URL[20];
            int i = 2;
            while(input[i]!='\0')
            {
                URL[i-2] = input[i];
                i++;
            }
            URL[i-2] = '\0';
            // printf("URL: %s", URL);
            V(URL);
            // printf("%c",'\n');
            continue;

        }
        else if (input[0]=='B')
        {
            char URL[20];
            int i = 2;
            while(input[i]!='\0')
            {
                URL[i-2] = input[i];
                i++;
            }
            URL[i-2] = '\0';
            int N = atoi(URL);
            B(N);
            // printf("%c",'\n');
            continue;

        }
        else if(input[0]=='F')
        {
            char URL[20];
            int i = 2;
            while(input[i]!='\0')
            {
                URL[i-2] = input[i];
                i++;
            }
            URL[i-2] = '\0';
            int N = atoi(URL);
            F(N);
            // printf("%c",'\n');
            continue;
        }
        else if(input[0]=='D')
        {
            char URL[20];
            int i = 2;
            while(input[i]!='\0')
            {
                URL[i-2] = input[i];
                i++;
            }
            URL[i-2] = '\0';
            int N = atoi(URL);
            D(N);
            // printf("%c",'\n');
            continue;
        }
        else if(input[0]=='Q')
        {
            char URL[20];
            int i = 2;
            while(input[i]!='\0')
            {
                URL[i-2] = input[i];
                i++;
            }
            URL[i-2] = '\0';
            int N = atoi(URL);
            Q(N);
            // printf("%c",'\n');
            continue;
        }
    }
    return 0;
}
