#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}TREE;
int max_nodes;
int lst[100000];


int height(TREE* node){
    if(node==NULL)
    {
        return 0;
    }
    else
    {
        int hl = height(node->left);
        int hr = height(node->right);
        
        if(hr>hl)
            return hr+1;
        else
            return hl+1;
    }
}

int pIndex = 3; //this is the index going piche se for postorder; because global, it gets changes later. 

TREE* grow_tree(int inorder[], int postorder[], int inorder_start, int inorder_end)
{   
    if(pIndex==-1)
        return NULL;
    if(inorder_start>inorder_end){
        return NULL; //only happens at the end
    }

    TREE* newnode;
    newnode = (TREE*)malloc(sizeof(TREE*));
    newnode->data = postorder[pIndex];
    newnode->left=  newnode->right = NULL;
    pIndex--;

    if(inorder_start==inorder_end){
        // printf("I am being returned at line 26%d", newnode->data);
        return newnode;
    }

    int i, index_in_inorder;
    for(i=inorder_start;i<=inorder_end;i++)
    {
        if(inorder[i]==newnode->data)
            break;
    }

    index_in_inorder = i;
    newnode->right = grow_tree(inorder, postorder, index_in_inorder+1, inorder_end );
    newnode->left =  grow_tree(inorder, postorder, inorder_start, index_in_inorder-1);
    return newnode;

}
typedef struct stack{
    TREE* node;
    struct stack *next;
}STACK;

STACK* top = NULL;

void push(TREE* temp)
{
    if(top==NULL)
    {
        STACK* newnode;
        newnode = (STACK*)malloc(sizeof(STACK*));
        newnode->node = temp;
        newnode->next = NULL;
        top = newnode;
    }
    else
    {
        STACK* newnode;
        newnode = (STACK*)malloc(sizeof(STACK*));
        newnode->node = temp;
        newnode->next = top;
        top = newnode;
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("underflow\n");
    }
    else
    {
        top = top->next;
        
    }
}

TREE* topp()
{
    return top->node;
}

int isstackempty(){
    if(top==NULL)
        return 1;
    else
        return 0;
}
int inorderindex=0;
void preOrder(TREE* root)
{
    
    if(root==NULL)
        return;
    else
    {
        push(root);
        TREE* current = NULL;
        while(isstackempty()!=1)
        {
            current = topp();
            lst[inorderindex] = current->data;
            inorderindex++;
            pop();
            if(current->right != NULL)
                push(current->right);
            if(current->left!=NULL)
                push(current->left);
        }
        
    }
           
}
// void preOrder(TREE* node)
// {
// 	if (node == NULL)
// 		return;
// 	printf("%d ", node->data);
// 	preOrder(node->left);
// 	preOrder(node->right);
// }


void inOrder(TREE* node)
{   
	if (node == NULL)
		return;
	
	lst[inorderindex] = node->data;
	
	inorderindex++;
	inOrder(node->left);
	inOrder(node->right);
}

int count_leaves = 0;

int leaves(TREE* node)
{  
    if(node==NULL)
        return 0;
    if (node->right == NULL && node->left == NULL)
        return 1;
    else
        return leaves(node->left)+leaves(node->right);
}

int getnodes_at_level( TREE* node, int now, int target)
{
    if(node==NULL)
        return 0;
    if (now==target)
        return 1;
    else
        return getnodes_at_level(node->left, now+1, target) + getnodes_at_level(node->right, now+1, target);
}

TREE* findrightmost(TREE* temp)
{
    while(temp->right!=NULL)
        temp=temp->right;
    return temp;
    
}
TREE* delete(TREE* root, int data){
    
    if(root==NULL)
        return root;
    else if(data < root->data)
        root->left = delete(root->left,data);
    else if(data > root->data)
        root->right = delete(root->right, data);
    else 
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if(root->left == NULL)
        {
            TREE* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            TREE* temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            TREE* node = findrightmost(root->left); //have to make this function which returns the node. 
            root->data = node->data;
            root->left = delete(root->left, node->data);
        }
    }
    return root;
}

int main(){
   
    int menu;
    int max_nodes2;

    int* inorder;
    int* postorder;

    TREE* root;
    int count_no_of_deletions = 0;

    while(1)
    {  
        
        scanf("%d", &menu);
        if (menu==1)
        {
            scanf("%d", &max_nodes);
            // count_no_of_deletions-=max_nodes;
            for (int i =0;i<max_nodes;i++)
                lst[i]=0;
                
            inorder = (int*)malloc((max_nodes)*sizeof(int));
            postorder = (int*)malloc((max_nodes)*sizeof(int));
    
            for (int i = 0; i <max_nodes; ++i)
            {
                int c;
                scanf("%d",&c);
                if(c<1)
                    {
                        break;
                    }
                inorder[i]=c;
            }
    
            scanf("%d", &max_nodes2);
            for (int i = 0; i <max_nodes2; ++i)
            {
                int c;
                scanf("%d",&c);
                if(c<1)
                    {
                        break;
                    }
                postorder[i]=c;
            }        
        
            pIndex = max_nodes2-2;
         
            root = (TREE*)malloc(sizeof(TREE*));
            root->data = postorder[max_nodes2-1];
         
            int i;
            for (i=0;i<max_nodes2;i++)
            {
                if(inorder[i]==root->data)
                    break;
            }
            
            int iIndex = i;
            root->right = grow_tree(inorder, postorder, iIndex+1, max_nodes2-1);
            root->left = grow_tree(inorder, postorder,0, iIndex-1);

            if(root==NULL)
            {
                printf("empty\n");
                continue;
            }
            printf("%d\n",leaves(root));
            printf("%d\n",height(root));
            
            for(int i =0;i<height(root);i++)
            {
                int count_nodes_at_level = getnodes_at_level(root,0,i);
                printf("%d %d\n",i,count_nodes_at_level);
            }
            continue;
        }
        if(menu==2)
        {   
            
            if(root==NULL)
            {
                printf("empty\n");
                continue;
            }
            int key;
            scanf("%d",&key);
    
            
            inorderindex =0;
            
            preOrder(root);
            int flag =0;
            for(int i=0; i<max_nodes2-count_no_of_deletions; i++)
            {
                if(lst[i]==key)
                {   flag = 1;
                    break;
                }
            }
            if(flag==0)
            {    printf("error\n");
                 continue;
            }
            
            root = delete(root, key);
            count_no_of_deletions++;
            inorderindex =0;
            preOrder(root);
            if(root==NULL)
                printf("empty\n");
            
            
            // printf("%d", lst[j+1]);
            
            for(int i =0;i<max_nodes2-count_no_of_deletions;i++)
            {
                if(i!=max_nodes2-count_no_of_deletions-1)
                    printf("%d " , lst[i]);
                else
                    printf("%d\n", lst[i]);
            }
            continue;
            
        }
        else
          break;
          
    }
    return 0;
}
