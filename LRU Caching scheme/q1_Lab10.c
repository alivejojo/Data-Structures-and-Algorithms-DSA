#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int bookId;
    struct node* prev;
    struct node* next;
}NODE;

int N;
int m;
int L;
int capacity;
int* bookId_arr;
int* unique_bookIds;
int c;
// struct node* hash_array;

void print_q(NODE* head, NODE* tail)
{
    //print from tail to head
    NODE* current = tail->prev;
    while(current->prev!=NULL)
    {
        printf("%d ", current->bookId);
        current = current->prev;
    }
    printf("%c",'\n');
}

NODE* enqueue(NODE* head, NODE* tail, int current)
{
    if(head->next==tail)
    {
        // printf("\n 28 enquing for the first time");
        NODE* newnode;
        newnode = (NODE*)malloc(sizeof(NODE));
        newnode->bookId = current;
        newnode->prev = head;
        newnode->next = tail;
        head->next = newnode;
        tail->prev = newnode;
        // printf("%d\n", newnode->bookId);
    return newnode;


    }
    else
    {
        // printf("\n 39 enquing %d", current);

        NODE* newnode;
        newnode = (NODE*)malloc(sizeof(NODE));
        newnode->bookId = current;
        NODE* t = head->next;
        newnode->prev = head;
        t->prev = newnode;
        newnode->next = t;
        head->next = newnode;
        // printf("%d\n", newnode->bookId);
    return newnode;


    }
    // return newnode;
}

NODE* get(NODE* head, NODE* tail, NODE* to_be_accessed)
{
    // printf("\ns");
    NODE* newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->bookId = to_be_accessed->bookId;
    // printf("book id in to_be_accessed  = %d", to_be_accessed->bookId);
    // printf("\nss");

    
    if (to_be_accessed->next == tail)
    {
        // printf("\nyo");
        to_be_accessed->prev->next = tail;
        tail ->prev = to_be_accessed->prev;
        free(to_be_accessed);
    }
    
    else
    {
        // printf("\nyo2");

        to_be_accessed->prev->next = to_be_accessed->next;
        to_be_accessed->next->prev = to_be_accessed->prev;
        free(to_be_accessed);
    }
    NODE* t = head->next;
        newnode->prev = head;
        t->prev = newnode;
        newnode->next = t;
        head->next = newnode;

    return newnode;
}

NODE* dequeue(NODE* head, NODE* tail, int current)
{
    //returns the LRU
    c=0;
    NODE* LRU;
    LRU = (NODE*)malloc(sizeof(NODE));
    LRU = tail->prev;

    LRU->prev->next = tail;
    tail->prev = LRU->prev;
    // int c;
    c = LRU->bookId;
    free(LRU);

    NODE* newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->bookId = current;
    NODE* t = head->next;
        newnode->prev = head;
        t->prev = newnode;
        newnode->next = t;
        head->next = newnode;
    unique_bookIds[c] = 0;

    // return c;
    return newnode;

}

int main()
{
    
    //initialise head and tail
    NODE* head;
    head = (NODE*)malloc(sizeof(NODE));
    NODE* tail;
    tail = (NODE*)malloc(sizeof(NODE));
    head->next = tail;
    head->prev = NULL;
    tail->next = NULL;
    tail->prev = head;
    head->bookId = -1;
    tail->bookId = -1;

    //Input
    // int N;
    // int m;
    // int L;
    // int capacity;
    scanf("%d",&N);
    scanf("%d",&m);
    scanf("%d",&L);
    // printf("%d %d %d", N,m,L);

    capacity = m;

    // int* bookId_arr;
    bookId_arr = (int*)malloc(L*sizeof(int));

    // int* unique_bookIds;
    unique_bookIds = (int*)malloc((N+1)*sizeof(int));

    for(int i=0; i<N+1;i++)
    {
        unique_bookIds[i] = 0;
    }

    struct node* hash_array[N+1];
    // hash_array = (struct node*)malloc(L*sizeof(struct node));



    for(int i=0; i<N+1;i++)
    {
        hash_array[i]=NULL;
    }

    for(int i =0; i<L;i++)
    {
        int c;
        scanf("%d",&c);
        bookId_arr[i] = c; //gives the index = key
    }

    //main thing
    for (int i=0; i<L;i++)
    {
        //each element is one in bookId_arr
        int current = bookId_arr[i];
        // printf("current = %d\n", current);
        // printf("capacity = %d\n", capacity);


        if(i==0)
        {   //first enqueue
            // printf("\nstep1\n");
            NODE* to_be_inserted = enqueue(head,tail,current);
            capacity--;
            hash_array[current] = to_be_inserted;
            unique_bookIds[current]++;
        }

        else
        {
            if(capacity>0)
            {
                //still space left
                // printf("step2\n");


                if(hash_array[current]==NULL)
                {
                    // printf("step3\n");

                    //element being inserted for the first time and there is space in the q
                    NODE* to_be_inserted = enqueue(head,tail,current);
                    capacity--;
                    hash_array[current] = to_be_inserted;
                    // printf("171... bookId of node just stored = %d", to_be_inserted->bookId );
                    unique_bookIds[current]++;

                }
                else
                {
                    //element already present in q is being accessed and there is space in the q

                    //get()
                    // printf("step4\n");
                    
                    struct node* to_be_accessed = hash_array[current]; //isko apni position se nikal ke starting mein rakhna hain
                    NODE* t = get(head, tail, to_be_accessed);
                    hash_array[current] = t;
                    //ntg needs to be updated

                }
            }
            
            else
            {
                //no more space left in q
                // we have created space for every possible element [1,N]
                // hence it can't be that a new element shows up, it will be just accessing
                if(hash_array[current]== NULL)
                {
                    //new element
                    // printf("\ncap1\n");
                    //need to dequeue last wala and enqueue new

                    NODE* t = dequeue(head, tail ,current); //newly entered node, but old node needs to be removed from hash_array
                    // printf("c = %d",c);
                    
                    hash_array[c]=NULL;
                    // hash_array[current] = t;

                    hash_array[current] = t;
                    // unique_bookIds[c] = 0;
                    unique_bookIds[current]++;                   


                }
                // printf("step5\n");
                else
                {
                    // printf("step5\n");

                struct node* to_be_accessed = hash_array[current];  //isko apni position se nikal ke starting mein rakhna hain
                // printf("ttt%d\n",to_be_accessed->bookId);
                // printf("step6\n");
               
                NODE* t = get(head, tail, to_be_accessed);
                hash_array[current] = t;
                }
            }
        }
        print_q(head, tail);
    }
    return 0;

}
