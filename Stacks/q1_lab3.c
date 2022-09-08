#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct node{
    float data;
    struct node *next;
}NODE;

typedef struct node2{
    char term[200]; //character array 
    struct node2 *next;
}NODE2;


NODE* top_eval=NULL;
NODE2* top_print=NULL;



void push(float num){
    // printf("hello@14      push %d\n",num);
    if (top_eval==NULL)
    
    { 
        // printf("here@15\n");
        NODE* newnode;
        newnode = (NODE*)malloc(sizeof(NODE));
        newnode->data = num;
        newnode->next = NULL;
        top_eval = newnode; 

    }
    else
    {
        NODE* newnode;
        newnode = (NODE*)malloc(sizeof(NODE));
        newnode->data = num;
        newnode->next = top_eval;
        top_eval = newnode;
    }
}


float pop()
{  
    float n;
    if (top_eval==NULL)
        printf("error");

    else
    {   n = top_eval->data;
        top_eval = top_eval->next;
    }
    return n;
}

int isEMPTY(NODE* top){
    int n=0;
    if(top==NULL){
        n=1;   
    }
    return n;
}
float points_to_top(NODE* top_eval){
    return top_eval->data;
}



int main()
{  
    int j=0, x=0, k=0; //j loops over array, x loops over temp
    char str[200];
    // NODE* top_eval=NULL;
    // NODE* top_print=NULL;
    scanf("%s",&str);
    int m=0;
    while(str[m]!='\0'){
        m++;

    }str[m]=',';
    char arr[200][200], temp[200];

    for (int i=0;i<strlen(str);i++){

        if(str[i]==','){
            while(x--)
                {  
                    arr[j][k] = temp[k];
                    k++;
                }
            j++;
            k=0;
            x=0;
            continue;
        }
        else{
            temp[x] = str[i];
            x++;
            continue;
        }
    }
 //checking if the given postfix is allowed or not.
    if(strcmp(arr[0],"+\0")==0 || strcmp(arr[0],"-\0")==0 || strcmp(arr[0],"*\0")==0 || strcmp(arr[0],"/\0")==0 || strcmp(arr[0],"^\0")==0)
        printf("error");
    
    int count_operand=0, count_operator = 0, count_unary=0;

    for (int i =0;i<j;i++)
    {   
        if (strcmp(arr[i],"+\0")!=0 && strcmp(arr[i],"-\0")!=0 && strcmp(arr[i],"*\0")!=0 && strcmp(arr[i],"/\0")!=0 && strcmp(arr[i],"^\0")!=0)
        {
            count_operand++;
        }
        else if(strcmp(arr[i],"^\0")==0)
            count_unary++;
        else
            count_operator++;
    }
    if(count_operator>count_operand){
        printf("error");
    }

    // if( strcmp(arr[j],"+\0")!=0 && strcmp(arr[j],"-\0")!=0 && strcmp(arr[j],"*\0")!=0 && strcmp(arr[j],"/\0")!=0 && strcmp(arr[j],"^\0")!=0)
    //   printf("error");


 
    float left_operand, right_operand;
    float eval;
    //doing everything in main itself
    for (int i=0;i<j;i++){
        // printf("here@96\n");
        if (strcmp(arr[i],"+\0")!=0 && strcmp(arr[i],"-\0")!=0 && strcmp(arr[i],"*\0")!=0 && strcmp(arr[i],"/\0")!=0 && strcmp(arr[i],"^\0")!=0)
            //implies its an operand, so push it
            {

            push(atof(arr[i]));}
            else
            {  
                //unary operator 
                if(strcmp(arr[i],"^")==0)
                {
                    int n = pop(top_eval);
                    push(n*n);
                    // printf("%f I was pushed\n", n*n);
                }
                else
                {
                    right_operand = pop();
                    left_operand = pop();
                    if (strcmp(arr[i],"+")==0){
                        push(right_operand+left_operand);}
                        // printf("%f I was pushed after operation \n",right_operand+left_operand );}
                    else if (strcmp(arr[i],"-")==0)
                        {
                        push(left_operand-right_operand);}
                        // printf("%f I was pushed after operation\n",left_operand-right_operand);}
                    else if (strcmp(arr[i],"*")==0){
                        push(right_operand*left_operand);}
                        // printf("%f I was pushed after operation\n",right_operand*left_operand );}
                    else if (strcmp(arr[i],"/")==0)   {
                        push(left_operand/right_operand);}
                        // printf("%f I was pushed after operation\n",left_operand/right_operand);}
                       
                    else 
                        continue;
                }
            }
        }
    
    eval = points_to_top(top_eval);


    char left_operand_string[200], right_operand_string[200];
    char final_expression[400];

    for(int i =0;i<j;i++)
    {
        if ((strcmp(arr[i],"+\0")!=0 && strcmp(arr[i],"-\0")!=0 && strcmp(arr[i],"*\0")!=0 && strcmp(arr[i],"/\0")!=0 && strcmp(arr[i],"^\0")!=0))
        {
            NODE2* newnode;
            newnode = (NODE2*)malloc(sizeof(NODE2));
            if (top_print==NULL)
            {
                strcpy(newnode->term, arr[i]);
                newnode->next = NULL;
                top_print = newnode;
            }
            else
            {
                strcpy(newnode->term,arr[i]);
                newnode->next = top_print;
                top_print = newnode;
            }

        }
        else
        {
            //now it is an operator
            if (strcmp(arr[i],"^\0")==0)
            {
                if (top_print==NULL)
                    printf("error");
                else
                {
                    char n[100] = "(\0";
                    strcat(n,top_print->term);
                    strcat(n,"^)\0");
                    top_print = top_print->next;//popping
                    NODE2* newnode;

                    newnode = (NODE2*)malloc(sizeof(NODE2));
                    if (top_print==NULL)
                    {
                        strcpy(newnode->term, n);
                        newnode->next = NULL;
                        top_print = newnode;
                    }
                    else
                    {
                        strcpy(newnode->term,n);
                        newnode->next = top_print;
                        top_print = newnode;
                    }
                }
            }
            else
            {
                //now the operator is not ^
                if(strcmp(arr[i], "+\0")==0)
                {
                    //pop twice and push (a+b)
                    if (top_print==NULL)
                    printf("error");
                    else{
                            char n_right[100] = "+\0";
                            strcat(n_right,top_print->term);
                            strcat(n_right,")\0");
                            top_print = top_print->next;//popping

                            char n_left[100] = "(\0";
                            strcat(n_left,top_print->term);
                            // strcat(n_left,")\0");
                            top_print = top_print->next;//popping

                            strcat(n_left,n_right);

                            NODE2* newnode;

                            newnode = (NODE2*)malloc(sizeof(NODE2));
                            if (top_print==NULL)
                            {
                                strcpy(newnode->term, n_left);
                                newnode->next = NULL;
                                top_print = newnode;
                            }
                            else
                            {
                                strcpy(newnode->term,n_left);
                                newnode->next = top_print;
                                top_print = newnode;
                            }



                    }

                }
                else if (strcmp(arr[i], "-\0")==0)
                {
                    //pop twice and push (a+b)
                    if (top_print==NULL)
                    printf("error");
                    else{
                            char n_right[100] = "-\0";
                            strcat(n_right,top_print->term);
                            strcat(n_right,")\0");
                            top_print = top_print->next;//popping

                            char n_left[100] = "(\0";
                            strcat(n_left,top_print->term);
                            // strcat(n_left,")\0");
                            top_print = top_print->next;//popping

                            strcat(n_left,n_right);

                            NODE2* newnode;

                            newnode = (NODE2*)malloc(sizeof(NODE2));
                            if (top_print==NULL)
                            {
                                strcpy(newnode->term, n_left);
                                newnode->next = NULL;
                                top_print = newnode;
                            }
                            else
                            {
                                strcpy(newnode->term,n_left);
                                newnode->next = top_print;
                                top_print = newnode;
                            }



                    }
                }
                else if (strcmp(arr[i], "*\0")==0)
                {
                    //pop twice and push (a+b)
                    if (top_print==NULL)
                    printf("error");
                    else{
                            char n_right[100] = "*\0";
                            strcat(n_right,top_print->term);
                            strcat(n_right,")\0");
                            top_print = top_print->next;//popping

                            char n_left[100] = "(\0";
                            strcat(n_left,top_print->term);
                            // strcat(n_left,")\0");
                            top_print = top_print->next;//popping

                            strcat(n_left,n_right);

                            NODE2* newnode;

                            newnode = (NODE2*)malloc(sizeof(NODE2));
                            if (top_print==NULL)
                            {
                                strcpy(newnode->term, n_left);
                                newnode->next = NULL;
                                top_print = newnode;
                            }
                            else
                            {
                                strcpy(newnode->term,n_left);
                                newnode->next = top_print;
                                top_print = newnode;
                            }



                    }
                }
                else if (strcmp(arr[i], "/\0")==0)
                {
                    //pop twice and push (a+b)
                    if (top_print==NULL)
                    printf("error");
                    else{
                            char n_right[100] = "/\0";
                            strcat(n_right,top_print->term);
                            strcat(n_right,")\0");
                            top_print = top_print->next;//popping

                            char n_left[100] = "(\0";
                            strcat(n_left,top_print->term);
                            // strcat(n_left,")\0");
                            top_print = top_print->next;//popping

                            strcat(n_left,n_right);

                            NODE2* newnode;

                            newnode = (NODE2*)malloc(sizeof(NODE2));
                            if (top_print==NULL)
                            {
                                strcpy(newnode->term, n_left);
                                newnode->next = NULL;
                                top_print = newnode;
                            }
                            else
                            {
                                strcpy(newnode->term,n_left);
                                newnode->next = top_print;
                                top_print = newnode;
                            }



                    }
                }
                else
                printf("error");
            }

        }
    }
    printf("%s", top_print->term);
    // int n;
    // n = (10*eval)/10;
    // if(n==(int)eval)
    //     {printf("%f\n",n);}

    // else
    if (eval==(int)eval){
        printf("\n%d", (int)eval);
    }
    else
    printf("\n%.2f", eval);

    //now for printing the infix expression


return 0;
}
