//Directed Graph using Adjancency Matrix
#include<iostream>
#include<stdlib.h>

using namespace std;

//queue node
struct Node{
    int data;
    Node *link;
};

Node *front = NULL;
Node *rear = NULL;


void Insert(int n1,int n2, int **matrix)    //fucntion to insert
{
    if(matrix[n1-1][n2-1] == 1)
        cout << "Edge already exists"<<endl;
    else
        matrix[n1-1][n2-1] = 1;
}

void enqueue(int x)        //function to enqueue
{
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    
    if(front == NULL)   //empty queue
    {
        temp->link = NULL;
        front = rear = temp;
    }

    rear->link = temp;
    rear = temp;
    temp->link = NULL;
    return;

}

int dequeue()     //function to dequeue
{
    Node *temp;
    int x;

    if(front==NULL && rear==NULL)  //empty queue
        return 0;

    temp = front;
    x = temp->data;
    if(front == rear)
    {
        front = rear = NULL;
        free(temp);
    }
    else
    {
        front = front->link;
        free(temp);
    }

    return x;
}

void initialize(int *visited, int n)   //initialize visited array
{
    for(int i=0; i<n ;i++)
    {
        visited[i] = 0;
    }
}

void BFS_Display(int **matrix, int vertex, int n, char *c)    //display reachable nodes from a vertex
{
    int *visited, x;
    visited = (int*)malloc(n*sizeof(int));
    initialize(visited,n);

    enqueue(vertex);

    cout << "Reachable nodes from " << vertex <<" : "<< endl;

    while(1)
    {
        x = dequeue();
        if(x==0)           //queue is empty
            break;
        cout << c[x-1] << " ";
        for(int i=0;i<n;i++)
        {
            if(matrix[x-1][i] == 1 && visited[i] == 0)    //out neighbours of x
            {
                visited[i] = 1;
                enqueue(i+1);
            }
        }
    }

    cout << endl;
    return;
}


void BFS_Search(int **matrix, char item, int n, char *c)    //search for an element
{
    int *visited, x, found, k;
    char *array;
    array = (char*)malloc(n*sizeof(char));

    visited = (int*)malloc(n*sizeof(int));
    initialize(visited,n);

    found = 0;
    for(int i=0;i<n;i++)     //perform BFS with each node as root
    {
        enqueue(i+1);
        initialize(visited,n);

        while(1)           //BFS
        {
            x = dequeue();
            if(x==0)        //empty queue
                break;
            if(c[x-1]==item)    
            {
                found = 1;
                break;
            }
            for(int i=0;i<n;i++)
            {
                if(matrix[x-1][i] == 1 && visited[i] == 0)
                {
                    visited[i] = 1;
                    enqueue(i+1);
                }
            }
        }

        if(found == 1)
        {
            cout << "Search Success" << endl;
            int j = x-1;
            k = 0;
            while(j!=i)    //backtrack
            {
                for(int l = 0; l<n;l++)
                {
                    if(matrix[l][j] == 1)
                    {
                        j = l;
                        array[k] = c[j];
                        k++;
                        break;
                    }
                }
            }
            cout << "Path : "<<endl;
            for(int j = k-1;j>=0;j--)   //printing the path
            {
                cout << array[j] << " ";
            }
            cout << endl;
            break;
        }
    }

    if(found == 0)
        cout << "Search Failure" <<endl;

}

void BFS_Connect(int **matrix, int n)    //to check if graph is strongly connected or not
{
    int *visited, x, count, wk;

    visited = (int*)malloc(n*sizeof(int));
    initialize(visited,n);

    wk = 0;

    for(int i=0;i<n;i++)      //perform BFS with each node as root
    {
        enqueue(i+1);
        initialize(visited,n);

        count = 0;     //to count the number of vertices reachable from current vertex

        while(1)
        {
            x = dequeue();
            count++;
            if(x==0)
                break;
            for(int i=0;i<n;i++)
            {
                if(matrix[x-1][i] == 1 && visited[i] == 0)
                {
                    visited[i] = 1;
                    enqueue(i+1);
                }
            }
        }

        if(count < n)   
        {
            wk = 1;
            break;
        }
    }
    if(wk == 1)
        cout << "Weekly connected graph" << endl;
    else
        cout << "Strongly connected graph" << endl;

}


int main(void)
{
    int n, x, n1, n2, vertex;
    int **matrix, *visited;
    char *c, item;

    cout << "Enter number of nodes : ";
    cin >> n;

    matrix = (int**)malloc(n*sizeof(char*));
    c = (char*)malloc(n*sizeof(char));
    visited = (int*)malloc(n*sizeof(int));

    initialize(visited,n);

    cout << "Enter character data: " <<endl;

    for(int i=0; i<n ; i++)
    {
        fflush(stdin);
        cout << "Node " << i+1 << " : ";
        cin >> c[i];
    }

    for(int i=0; i<n ; i++)
    {
        matrix[i] = (int*)malloc(n*sizeof(int));
        for(int j=0; j<n ;j++)
            matrix[i][j] = 0;
    }

    cout << "Enter : " << endl;

    cout << "1 : Insert" << endl;
    cout << "2 : Display BFS" << endl;
    cout << "3 : Search in BFS" << endl;
    cout << "4 : Connectivity Check" << endl;

    x = 1;
    while(x)            //menu driven program to perform various operations on graph
    {
        cout << "Enter your choice: ";
        cin >> x;
        switch(x)
        {
            case 1 : cout << "Enter the nodes between which edge to be created: ";
                     cin >> n1 >> n2;
                     Insert(n1,n2,matrix);
                     break;

            case 2 : cout << "Enter node number from which to find all reachable nodes: ";
                     cin >> vertex;
                     BFS_Display(matrix,vertex,n,c);
                     break;

            case 3 : cout << "Enter item to be searched : ";
                     cin >> item;
                     BFS_Search(matrix,item,n,c);
                     break;

            case 4 : BFS_Connect(matrix,n);
                     break;

            default : cout << "Invalid entry "<< endl;

        }

        cout << "Enter 1 to continue else 0 : ";
        cin >> x;

    }


    return 0;
}