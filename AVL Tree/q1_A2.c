#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include <string.h>
#include <stdbool.h>

// Create Node
typedef struct Node {
  char model_name[200];
  int price;
  char company[200];
//   float cam;
char cam[200];
  char color[50];
  int RAM;
  int battery;
  bool rem_battery;
  //this tree is searched using lexicographic order of model_name
//   int key;
  int ID;
  struct Node *left;
  struct Node *right;
  int height;
}TREE;

typedef struct Node2 {
  char model_name[200];
  int price;
  char company[200];
//   float cam;
char cam[200];

  char color[50];
  int RAM;
  int battery;
  bool rem_battery;
  int ID;
  struct Node2 *left;
  struct Node2 *right;
  int height;
}TREE2;


TREE* print_all_details(TREE* node)
{
    printf("ID: %d, ", node->ID);
    printf("%s, ", node->model_name);
    printf("%d,",node->price);
    printf("%s, ", node->company);
    printf("%s,",node->cam);
    
    printf("%s, ", node->color);
    printf("%d, ",node->RAM);
    printf("%d, ",node->battery);
    printf("%d\n", node->rem_battery);
}

TREE2* print_all_details2(TREE2* node)
{
    
    printf("ID: %d, ", node->ID);
    printf("%s, ", node->model_name);
    printf("%d,",node->price);
    printf("%s, ", node->company);
    // printf("%d,",(int)node->cam);
        printf("%s,",node->cam);

    printf("%s, ", node->color);
    printf("%d, ",node->RAM);
    printf("%d, ",node->battery);
    printf("%d\n", node->rem_battery);
}
// Calculate height
int height(TREE *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int height2(TREE2 *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
    if(a>b)
        return a;
    else
        return b;
//   return (a > b) ? a : b;
}

// Create a node

TREE *newNode( char* model_name, int price, char* company, char* cam, char* color, int RAM, int backup, bool batt, int ID) {
    //will pass all elements
    TREE *node = (TREE*)malloc(sizeof(TREE));
    char temp[200];
    int i = 0;
    while(*(model_name+i)!='\0')
    {
        temp[i] = *(model_name+i);
        i++;
    }
    temp[i]='\0';

                // printf("newNode%s\n", temp);

// printf("\n in newnode ##%s##",temp);

    strcpy(node->model_name, temp);
    // printf("I was stored in node %s\n", node->model_name);


    node->price = price;
    char temp2[200];
    i = 0;
    while(*(company+i)!='\0')
    {
        temp2[i] = *(company+i);
        i++;
    }
    temp2[i]='\0';

    strcpy(node->company, temp2);
char temp55[200];
    i = 0;
    while(*(cam+i)!='\0')
    {
        temp55[i] = *(cam+i);
        i++;
    }
    temp55[i]='\0';
strcpy(node->cam, temp55);
    char temp3[50];
    i = 0;
    while(*(color+i)!='\0')
    {
        temp3[i] = *(color+i);
        i++;
    }
    temp3[i]='\0';

    strcpy(node->color, temp3);
    node->RAM = RAM;
    node->battery = backup;
    node->rem_battery = batt;
    
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->ID = ID;
    return (node);
}

TREE2 *newNode2(char* model_name, int price, char* company, char* cam, char* color, int RAM, int backup, bool batt, int ID) 
{
    TREE2 *node = (TREE2*)malloc(sizeof(TREE2));
    char temp[200];
    int i = 0;
    while(*(model_name+i)!='\0')
    {
        temp[i] = *(model_name+i);
        i++;
    }
    temp[i]='\0';

// printf("\n##%s##",temp);
                // printf("newNode2%s\n", temp);


    strcpy(node->model_name, temp);
    // printf("I was stored in node %s\n", node->model_name);

    node->price = price;
    // printf("price while making node 113 \n%d ", node->price);
    char temp2[200];
    i = 0;
    while(*(company+i)!='\0')
    {
        temp2[i] = *(company+i);
        i++;
    }
    temp2[i]='\0';

    strcpy(node->company, temp2);
    char temp55[200];
    i = 0;
    while(*(cam+i)!='\0')
    {
        temp55[i] = *(cam+i);
        i++;
    }
    temp55[i]='\0';
strcpy(node->cam, temp55);
    char temp3[50];
    i = 0;
    while(*(color+i)!='\0')
    {
        temp3[i] = *(color+i);
        i++;
    }
    temp3[i]='\0';

    strcpy(node->color, temp3);
    node->RAM = RAM;
    node->battery = backup;
    node->rem_battery = batt;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
    node->ID = ID;

  return (node);
}

// Right rotate
TREE *rightRotate(TREE *y) {
  TREE *x = y->left;
  TREE *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

TREE2 *rightRotate2(TREE2 *y) {
  TREE2 *x = y->left;
  TREE2 *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height2(y->left), height2(y->right)) + 1;
  x->height = max(height2(x->left), height2(x->right)) + 1;

  return x;
}

// Left rotate
TREE *leftRotate(TREE *x) {
  TREE *y = x->right;
  TREE *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

TREE2 *leftRotate2(TREE2 *x) {
  TREE2 *y = x->right;
  TREE2 *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height2(x->left), height2(x->right)) + 1;
  y->height = max(height2(y->left), height2(y->right)) + 1;

  return y;
}

// Get the balance factor
int getBalance(TREE *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

int getBalance2(TREE2 *N) {
  if (N == NULL)
    return 0;
  return height2(N->left) - height2(N->right);
}

// Insert node
TREE *insertNode(TREE *node, char* model_name, int price, char* company, char* cam, char* color, int RAM, int backup, bool batt, int ID) {

    char temp[200];
    int i = 0;
    while(*(model_name+i)!='\0')
    {
        temp[i] = *(model_name+i);
        i++;
    }
    temp[i]='\0';
  if (node == NULL)
    return (newNode(temp, price, company, cam, color, RAM, backup, batt, ID));
  if(strcmp(temp,node->model_name)<0)
    node->left = insertNode(node->left, temp, price, company, cam, color, RAM, backup, batt, ID);
  else if (strcmp(temp,node->model_name)>0)
    node->right = insertNode(node->right, temp, price, company, cam, color, RAM, backup, batt, ID);
  else
    return node;
  node->height = 1 + max(height(node->left),
               height(node->right));

  int balance = getBalance(node);

  if(balance > 1 && strcmp(temp, node->left->model_name)<0)
    return rightRotate(node);


  if(balance < -1 && strcmp(temp, node->right->model_name)>0)
    return leftRotate(node);


   if (balance > 1 && strcmp(temp, node->left->model_name)>0)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

    if(balance<-1 && strcmp(temp, node->right->model_name)<0)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
//
  return node;
}



TREE2 *insertNode2(TREE2 *node,  char* model_name, int price, char* company, char* cam, char* color, int RAM, int backup, bool batt, int ID) {
char temp[200];
    int i = 0;
    while(*(model_name+i)!='\0')
    {
        temp[i] = *(model_name+i);
        i++;
    }
    temp[i]='\0';
// printf("##%s##",temp);
                // printf("insertNode2%s\n", temp);
 
  if (node == NULL)
    return (newNode2(temp, price, company, cam, color, RAM, backup, batt, ID));

  if (price < node->price)
    node->left = insertNode2(node->left,model_name, price, company, cam, color, RAM, backup, batt, ID);
  else if (price > node->price)
    node->right = insertNode2(node->right, model_name, price, company, cam, color, RAM, backup, batt, ID);
  else
    return node;

  node->height = 1 + max(height2(node->left),
               height2(node->right));

  int balance = getBalance2(node);
  if (balance > 1 && price < node->left->price)
    return rightRotate2(node);

  if (balance < -1 && price > node->right->price)
    return leftRotate2(node);

  if (balance > 1 && price > node->left->price) {
    node->left = leftRotate2(node->left);
    return rightRotate2(node);
  }

  if (balance < -1 && price < node->right->price) {
    node->right = rightRotate2(node->right);
    return leftRotate2(node);
  }

  return node;
}

TREE* query_by_model_name(TREE* root, char* model_name)
{
    char temp[100];
    int i = 0;
    while(*(model_name+i)!='\0')
    {
        temp[i] = *(model_name+i);
        i++;
    }
    if(root==NULL)
    {
        printf("Not Found\n");
        return NULL;
    }
    if(strcmp(root->model_name, temp)==0)
    {
        // return root;
        print_all_details(root);
    }
    if(strcmp(root->model_name, temp)<0)
        return query_by_model_name(root->right, model_name);
    return query_by_model_name(root->left, model_name);
}

TREE2* query_by_price(TREE2* root2, int price)
{
    // print_all_details2(root2);
    // printf("yo %d\n", root2->price);
    // printf("yoo %d\n", price);

    // printf("hello");
    if(root2==NULL)
    {
        printf("Not Found\n");
        return root2;
    }
    if(root2->price==price)
      return print_all_details2(root2);
    if(price<root2->price)
      return query_by_price(root2->left, price);
    else
      return query_by_price(root2->right, price);

}

//function to query database using price, then delete that node.. uske pehle make sure delete works.

TREE* leftMostNode(TREE* node) {
  TREE* current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}
TREE2* leftMostNode2(TREE2* node) {
  TREE2 *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

// Delete a nodes

TREE *deleteNode(struct Node *root, char* model_name) {
    // Find the node and delete it

    if (root == NULL)
    {
        // printf("Not Found");
        return root;
    }
    char temp[100];
        int i = 0;
        while(*(model_name+i)!='\0')
        {
            temp[i] = *(model_name+i);
            i++;
        }

    //   if (key < root->key)
    if(strcmp(model_name, root->model_name)<0)
        root->left = deleteNode(root->left, model_name);

    else if(strcmp(model_name, root->model_name)>0)
        root->right = deleteNode(root->right, model_name);

    else {
        if ((root->left == NULL) || (root->right == NULL)) {
        TREE *t = root->left ? root->left : root->right;

        if (t == NULL) {
            t = root;
            root = NULL;
        } else
            *root = *t;
        free(t);
        } else {
        TREE *t = leftMostNode(root->right);

        //   root->key = temp->key;
        strcpy(root->model_name, t->model_name);
        root->price = t->price;
        strcpy(root->company, t->company);
        strcpy(root->cam,t->cam);
        strcpy(root->color, t->color);
        root->RAM = t->RAM;
        root->battery = t->battery;
        root->rem_battery = t->rem_battery;
        root->right = deleteNode(root->right, t->model_name);
        }
    }

    if (root == NULL)
        return root;

    // Update the balance factor of each node and
    // balance the tree
    root->height = 1 + max(height(root->left),
                height(root->right));

    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

TREE2 *deleteNode2(TREE2 *root, int price) {
    // Find the node and delete it

    if (root == NULL)
    {
        printf("Not Found");
        return root;
    }
   
    //   if (key < root->key)
    if(price < root->price)
        root->left = deleteNode2(root->left, price);

    else if(price>root->price)
        root->right = deleteNode2(root->right, price);

    else {
        if ((root->left == NULL) || (root->right == NULL)) {
        TREE2 *t = root->left ? root->left : root->right;

        if (t == NULL) {
            t = root;
            root = NULL;
        } else
            *root = *t;
        free(t);
        } else {
        TREE2 *t = leftMostNode2(root->right);

        strcpy(root->model_name, t->model_name);
        root->price = t->price;
        strcpy(root->company, t->company);
                strcpy(root->cam,t->cam);

        strcpy(root->color, t->color);
        root->RAM = t->RAM;
        root->battery = t->battery;
        root->rem_battery = t->rem_battery;
        
        // strcpy(root->model_name, t->model_name);
        root->right = deleteNode2(root->right, t->price);
        }
    }

    if (root == NULL)
        return root;

    // Update the balance factor of each node and
    // balance the tree
    root->height = 1 + max(height2(root->left),
                height2(root->right));

    int balance = getBalance2(root);
    if (balance > 1 && getBalance2(root->left) >= 0)
        return rightRotate2(root);

    if (balance > 1 && getBalance2(root->left) < 0) {
        root->left = leftRotate2(root->left);
        return rightRotate2(root);
    }

    if (balance < -1 && getBalance2(root->right) <= 0)
        return leftRotate2(root);

    if (balance < -1 && getBalance2(root->right) > 0) {
        root->right = rightRotate2(root->right);
        return leftRotate2(root);
    }

    return root;
}


void R_menu(TREE2* root2, int p1, int p2)
{

  // printf("%d",p1);
  // printf("%d",p2);

    if(root2==NULL)
    {
      return;
    }
    if(p1 < root2->price)
    {
      R_menu(root2->left, p1,p2);
    }
    if(p1<=root2->price && p2>=root2->price)
    {
      print_all_details2(root2);
    }
    if(p2>root2->price)
      R_menu(root2->right, p1,p2);       
}
// Print the tree
int ID = 0;


int main() 
{

  TREE *root = NULL;
  TREE2 *root2 = NULL;

  // int ID=0;
  char input_str[300];
  fgets(input_str,300, stdin);

  while(input_str[0]!='T')
  {
  if(input_str[1]==' ')
  {
    if (input_str[0] == 'A')
    {   
        ID++;
        //insertion
        char model_name[200];
        int price;
        char company[200];
        char cam[200];
        char color[50];
        int RAM;
        int battery;
        int rem_battery;
        int i = 0;
        
        char input_str2[200];
        int j = 2;
        while(input_str[j]!='\0')
        {
            input_str2[j-2] = input_str[j];
            j++;
        }
        char *token = strtok(input_str2, ",");
        while(token!= NULL)
        {
            if(i==0)
            {  
              strcpy(model_name, token);
              // printf("token%s\n", model_name);
            }
            if(i==1)
                price = atoi(token);
            if(i==2)
                strcpy(company, token);
            if(i==3)
                strcpy(cam, token);
                // cam = atof(token);
            if(i==4)
                strcpy(color, token);
            if(i==5)
                RAM = atoi(token);
            if(i==6)
                battery = atoi(token);
            if(i==7)
                rem_battery = atoi(token);
            i++;
            token = strtok(NULL, ",");
        }
        printf("ID: %d\n", ID);
        root = insertNode(root, model_name, price, company, cam, color, RAM, battery, rem_battery, ID);
        root2 = insertNode2(root2, model_name, price, company, cam, color, RAM, battery, rem_battery, ID);
        // print_all_details(root);
        // printf("%c",'\n');
        // print_all_details2(root2);
        fgets(input_str,300, stdin);
        continue;
    }
    else
    {
      
      int p1 = 0;
      int p2 = 0;
      int i = 2;
      char p1_p2[100];
      while(input_str[i]!='\0')
      {
        p1_p2[i-2] = input_str[i];
        i++;
      }
      int j=0;
      char *token = strtok(p1_p2, " ");
      while(token!= NULL)
      {
        if(j==0)
          p1 = atoi(token);
        if(j==1)
          p2 = atoi(token);
        token = strtok(NULL, " ");        
        j++;
      }
      //  printf("%d",p1);
  // printf("hi   %d",p2);
      R_menu(root2, p1,p2);
      fgets(input_str,300, stdin);
      continue;
    }
  }
  if(input_str[2]==' ')
  {
    if(input_str[0]=='Q' && input_str[1]=='P')
    {
        // printf("meh wrong");
        //Query database using price (print “Not Found” in case of any issues)
        //QP 12000
        char price_str[100];
        int i = 3;
        while(input_str[i]!='\0')
        {
          price_str[i-3] = input_str[i];
          i++;
        }
        int price = atoi(price_str);
        // printf("%d",price);
        query_by_price(root2, price);
        fgets(input_str,300, stdin);
        continue;

    }
    if(input_str[0]=='Q' && input_str[1]=='N')
    {
        // printf("meh wrong");
        //Query database using name (print “Not Found” in case of any issues)
        //QP nokia
        char name[200];
        int i = 3;
        while(input_str[i]!='\0')
        {
          name[i-3] = input_str[i];
          i++;
        }
        query_by_model_name(root, name);
        fgets(input_str,300, stdin);
        continue;

    }
    if(input_str[0]=='D' && input_str[1]=='P')
    {
        // printf("meh wrong");
        // Query database using price and delete model for the database (print “Not Found” in case of any issues)
        char price_str[100];
        int i = 3;
        while(input_str[i]!='\0')
        {
          price_str[i-3] = input_str[i];
          i++;
        }
        int price = atoi(price_str);
        root2 = deleteNode2(root2,price);
        printf("Deleted ID: %d\n", root2->ID);
        fgets(input_str,300, stdin);
        continue;
     
    }
    if(input_str[0]=='D' && input_str[1]=='N')
    {
        // printf("meh wrong");
        // Query the database using the Name and delete model for the database (print “Not Found” in case of any issues)
        char name[100];
        int i = 3;
        while(input_str[i]!='\0')
        {
          name[i-3] = input_str[i];
          i++;
        }
        // query_by_model_name_delete(root, name);
        root = deleteNode(root,name);
        printf("Deleted ID: %d\n", root->ID);
        fgets(input_str,300, stdin);
        continue;
    }
  }
  }

  return 0;
}
