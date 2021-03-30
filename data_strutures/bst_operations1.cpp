//Implementation of Binary Search Tree

#include<iostream>
#include<stdlib.h>

using namespace std;

//to store nodes of tree
struct Node
{
    char data;
    Node *left;
    Node *right;
};

//to store elements in stack
struct Stackn
{
    Node *current;
    Stackn *next;
};
Stackn *top = NULL;  //top of stack

//to store return tuple of BSTSearch
struct ReturnS
{
    Node *parent;
    Node *found;
};



Node* BSTInsert(Node *root, char data)            //function to insert element into BST
{
    Node *temp;

    if(root == NULL)                             //tree is empty
    {
        temp = (Node*)malloc(sizeof(Node));
        root = temp;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
    }
    else if(root->data < data)                 //data is more than current root data
    {
        
        temp = BSTInsert(root->right, data);
        root->right = temp;
    }
    else                                       //data is less than current root data
    {
        temp = BSTInsert(root->left, data);
        root->left = temp;
    }

    return root;
}

ReturnS BSTSearch(Node *root, char s_data)          //function to search item
{
    ReturnS temp;             //strores thr current root

    if(root == NULL)                               
    {
        temp.found = root;                        
        return temp;
    }
    if(root->data == s_data)
    {
        temp.found = root;
        root = temp.found;
        return temp;
    }
    if(root->data < s_data)
    {
        temp = BSTSearch(root->right, s_data);
        temp.parent = root;                      //storing parent for the return node
        root = temp.found;
    }
    else
    {
        temp = BSTSearch(root->left, s_data);
        temp.parent = root;                    //storing parent for the return node
        root = temp.found;                       
    }
    return temp;
}


void pushstack(Node *cur)              //function to push element on stack
{
    Stackn *temp;

    temp = (Stackn*)malloc(sizeof(Node));
    temp->current = cur;
    temp->next = top;
    top = temp;

}
 
char popstack()                      //fucntion to pop element from stack
{
    Stackn *temp;
    char x;

    if(top == NULL)                //stack is empty
        return '0';

    temp = top;
    top = top->next;

    x = temp->current->data;

    delete temp;

    return x;
}

void BSTInorderStack(Node *root)             //function to Inorder traversal of the BST
{
    Stackn *temp;
    Node *c_node = root;
    char x;
    
    while(top != NULL || c_node != NULL)         //checks if stack is not empty else the current node is not NULL
    {
        while(c_node != NULL)                    //pushing onto stack the left nodes of left sub tree
        {
            pushstack(c_node);
            c_node = c_node->left;
        }

        c_node = top->current;              

        x = popstack();                           
        cout << x << " ";                         //prints the inorder traversal elements

        c_node = c_node->right;                   //traversing the right subtree
    }

}

int main(void)
{
    Node *root = NULL, *search;
    ReturnS temp;
    int n, x=1;
    char c;

    cout << "Enter" <<endl;
    cout << "1 : Insert item" <<endl;
    cout << "2 : Search item" <<endl;
    cout << "3 : Print Inorder Traversal" <<endl;

    while(x)                                   //menu driven program to perfrom operations on BST
    {
        cout <<"Enter choice: ";
        cin >>x;
        switch(x)
        {
            case 1: cout <<"Enter element to insert: ";
                    fflush(stdin);
                    cin >> c;
                    temp = BSTSearch(root, c);            //check if item already exixts in BST
                    if(temp.found == NULL)                //inserts only if item is not present in BST
                        root = BSTInsert(root, c);
                    else
                        cout << "Item already exists"<< endl;
                    break;
            
            case 2: cout << "Enter element to search: ";
                    fflush(stdin);
                    cin >> c;
                    temp = BSTSearch(root, c);
                    if(temp.found != NULL)
                        cout << "Element found at location " << temp.found <<endl;
                    else
                        cout << "Element not found" <<endl;
                    break;
            
            case 3: cout << "Elements in Binary Search tree are: "<<endl;
                    BSTInorderStack(root);
                    cout << endl;
                    break;

            default : cout << "Invalid choice" <<endl;

        }
        cout << "Enter 1 to continue else 0 : " ;
        cin >> x;
    }

    return 0;
}