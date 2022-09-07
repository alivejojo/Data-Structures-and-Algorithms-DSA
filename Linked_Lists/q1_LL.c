#include<stdio.h>
#include<stdlib.h>

int power(int a,int b){
    // returns a^b
    int prod=1;
    for (int i=0;i<b;i++){
        prod = prod*a;
    }
    return prod;
}

typedef struct node{
    int coeff;
    int pw;
    struct node *next;
}NODE;

NODE* makePolynomial(int* p, int max_pow){
    
    NODE* head = NULL;
    int m = max_pow;
    for (int i=0;i<max_pow+1;++i){

        if (head==NULL)
        {
            NODE* newnode;
            newnode = (NODE*)malloc(sizeof(NODE));
            newnode->coeff = *(p+i);
            newnode-> pw = m;
            newnode->next = NULL;
            head = newnode;

        }
        else{
            NODE* temp = head;
            while((temp->next)!=NULL)
            {
                temp=temp->next;
            }
            NODE* newnode;
            newnode = (NODE*)malloc(sizeof(NODE));
            newnode->coeff = *(p+i);
            newnode-> pw =--m;
            newnode->next = NULL;
            temp->next= newnode;

        }
    }

    return head;
}
void display(NODE *ptr){
	NODE *temp = ptr;
	
	while(temp!=NULL)
	{	
    if(temp==ptr && temp->pw == 0)
            printf("%d", temp->coeff);

		if(temp==ptr && temp->coeff!=0 && temp->next!=NULL)
			printf("%dx^%d ", temp->coeff,temp->pw);
			
		
		else if(temp==ptr && temp->coeff==0 && temp->next==NULL)
			printf("0");
			
	
		else if(temp->coeff>0 && temp->pw>0) 
			printf("+ %dx^%d ", temp->coeff,temp->pw); 	
				
	
		else if(temp->coeff<0 && temp->pw>0) 
			printf("- %dx^%d ", -1*temp->coeff,temp->pw); 
			
		else if(temp->coeff>0 && temp->pw==0 && temp!=ptr)
			printf("+ %d", temp->coeff);	
			
		else if(temp->coeff<0 && temp->pw==0 && temp!=ptr)
			printf("- %d", -1*temp->coeff);
	
		temp = temp->next; 
	}
} 


NODE* evaluate(int max_pow1, int max_pow, NODE* head_p1, NODE* head_p2){

    NODE* head_p3=NULL;
    int m = max_pow; 


for (int i=0;i<max_pow+1;i++){

  
    if (head_p3==NULL)

    {   
        NODE* newnode;
        newnode = (NODE*)malloc(sizeof(NODE));
        newnode->coeff = head_p1->coeff; 
        head_p1 = head_p1->next;
        newnode-> pw = m-i;
        newnode->next = NULL;
        head_p3 = newnode;
    }

    else 

    {   
        NODE* temp = head_p3; 
        while((temp->next)!=NULL)
        {
            temp=temp->next;
        }

        if(i<max_pow1+1){
            //printf("here 85\n");
            NODE* newnode;
            newnode = (NODE*)malloc(sizeof(NODE));
            newnode->coeff = head_p1->coeff;
            head_p1 = head_p1->next;
            newnode-> pw = m-i;
            newnode->next = NULL;
            temp->next = newnode;

        }
     
        else{
            NODE* newnode;
            newnode = (NODE*)malloc(sizeof(NODE));
            newnode->coeff = head_p2->coeff;
            head_p2 = head_p2->next;
            newnode-> pw =m-i;
            newnode->next = NULL;
            temp->next= newnode;

        }
    }}
    
    return head_p3;
}

int calculate(NODE* ptr, int n){
    NODE* temp = ptr;
    int sum=0;
    while(temp!=NULL){
        // printf("%d\n", temp->coeff, "^");
        // printf("%d\n",  temp->pw);
        sum = sum + temp->coeff * power(n,temp->pw);
        temp =temp->next;

    }
    return sum;
}



int main(){
    int* p1;
    int* p2;
    int max_pow1, max_pow2;

    scanf("%d",  &max_pow1);
    p1 = (int*)malloc((max_pow1+1)* sizeof(int));
    for (int i = 0; i <max_pow1+1; ++i) {
        int c;
        scanf("%d",&c);
        p1[i]=c;
    }
    scanf("%d",  &max_pow2);
    p2 = (int*)malloc((max_pow2+1)* sizeof(int));
    for (int i = 0; i <max_pow2+1; ++i) {
        int c;
        scanf("%d",&c);
        p2[i]=c;
    }

    NODE* head_p1;
    NODE* head_p2;

    head_p1 = makePolynomial(&p1[0], max_pow1);
    head_p2 = makePolynomial(&p2[0], max_pow2);
    NODE* head_p3;
    NODE* head_p1_copy = head_p1;
    NODE* head_p2_copy = head_p2;

    head_p3 = evaluate(max_pow1,max_pow1+max_pow2+1, head_p1_copy, head_p2_copy);
    int n;
    scanf("%d",&n);
    printf("P1(x) = ");
    display(head_p1);
    printf("\n");
    
    printf("P2(x) = ");
    display(head_p2);
    printf("\n");

    
    

    printf("P3(x) = ");
    display(head_p3);
    printf("\n");

 
    


    printf("P1(%d) = ",n );
    printf("%d", calculate(head_p1, n));
    printf("\n");
    

    printf("P2(%d) = ",n );
    printf("%d", calculate(head_p2, n));
    printf("\n");
  

    printf("P3(%d) = ",n );
    printf("%d", calculate(head_p3, n));
    printf("\n");
    return 0;
}
