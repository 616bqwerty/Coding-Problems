//Linked list implementation of binary tree

#include<iostream>
#include<stdlib.h>

using namespace std;

//Node to store information about a tree node
struct Node{
    int data;
    struct Node* left;            //left child
    struct Node* right;           //right child
};
Node *root = NULL;               //root node

//Queue to insert element in tree to maintain it as complete tree
struct Queue{
    Node *node;
    Queue *next;
};
Queue *front = NULL;
Queue *rear = NULL;

void enqueue(Node *n)           //function to enqueue a tree node into the queue
{
    Queue *temp;
    temp = (Queue*)malloc(sizeof(Queue));
    temp->node = n;

    if(front == NULL)          //check if queue is empty
    {
        front = temp;
        rear = temp;
        temp->next = NULL;
        return;
    }

    rear->next = temp;
    temp->next = NULL;
    rear = temp;

}
 
void dequeue()              //function to dequeue or remove node which has both children as NOT NULL
{
    if(front == NULL)
        return;
    front = front-> next;
}

void Insert(int data)                  //insert element into binary tree
{
    Node *temp;
    Queue *tempq, *tempq2, *reari;

    temp = (Node*)malloc(sizeof(Node));
    tempq = (Queue*)malloc(sizeof(Queue));

    temp->data = data;
    tempq->node = temp;

    if(root==NULL)                 //tree is empty
    {
        root = temp;
        temp->left = NULL;
        temp->right = NULL;
        
        enqueue(temp);            //enqueue root into the queue

        return ;
    }

    tempq2 = front;

    if(tempq2->node->left == NULL)         //check if front tree node has both children as NuLL in that case store new node as its left child
    {
        tempq2->node->left = temp;
    }
    else                                   //check if front tree node has right child as NuLL in that case store 
    {                                      // new node as its right child and pop front tree node
        tempq2->node->right = temp;        
        dequeue();
    }  

    enqueue(temp);                         //enqueue new node
    temp->left = NULL;                     //set its left and right children to NULL
    temp->right = NULL;

}

int Max(int a, int b)                   //to return max of two numbers
{
    if(a>b)
        return a;
    else
        return b;
}

int Height(Node *Root)                  //calculates height of tree
{
    if(Root == NULL)
        return -1;
    return Max( Height(Root->left) , Height(Root->right) ) + 1;
}

void Postorder(Node *Root)              //postorder traversal of tree
{

    if(Root == NULL)                    
        return;
    Postorder(Root->left);             //left child
    Postorder(Root->right);            //right child
    cout << Root->data <<" ";          //parent or root

}

void Preorder(Node *Root)             //preorder traversal of tree
{

    if(Root==NULL)
        return;
    cout << Root->data << " ";         //parent or root
    Preorder(Root->left);              //left child
    Preorder(Root->right);             //right child

}

void Inorder(Node *Root)             //Inorder traversal of tree
{

    if(Root == NULL)
        return; 
    Inorder(Root->left);                //left child
    cout << Root->data << " ";          //parent or root
    Inorder(Root->right);               //right child

}


int main(void)
{
    int data, x=1, value;
    Node *find;

    cout << "Enter 1: Insert"<<endl;
    cout << "Enter 2: Find height of tree" <<endl;
    cout << "Enter 3: Preorder traversal"<<endl;
    cout << "Enter 4: Postorder traversal"<<endl;
    cout << "Enter 5: Inorder traversal" <<endl;

    while(x)                //menu driver program to perform different opeartions on tree          
    {

        cout << "Enter your choice: ";
        cin >> x;
        switch(x)
        {
            case 1: cout<< "Enter number to be inserted: ";
                    cin >> data;
                    Insert(data);
                    break;

            case 2: cout << "Height of this node is: "<< Height(root) <<endl;
                    break;
            
            case 3: cout << "Preorder traversal of tree is: "<<endl;
                    Preorder(root);
                    cout << endl;
                    break;

            case 4: cout << "Postorder traversal of tree is: "<<endl;
                    Postorder(root);
                    cout << endl;
                    break;
            
            case 5: cout << "Inorder traversal of tree is: "<<endl;
                    Inorder(root);
                    cout << endl;
                    break;

            default : cout <<"Invalid choice"<<endl;
        }

        cout << "Enter 1 to continue else 0: "<<endl;
        cin >> x;

    }

    return 0;
}