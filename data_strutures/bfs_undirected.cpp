#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>

using namespace std;

vector<int> visited;
vector<int> level;
vector<vector<int>> G;
struct Queue *front = NULL;
struct Queue *rear = NULL;
int count = 1;
int curr_level = 0;

struct Queue{
    int data;
    struct Queue *link;
};

void enqueue(int x)
{
    struct Queue *temp;
    temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->data = x;
    temp->link = NULL;
    if(front==NULL&&rear==NULL)
    {
        rear = temp;
        front = temp;
        return;
    }
    rear->link = temp;
    rear = temp;
}

int dequeue()
{
    int x;
    struct Queue *temp = front;
    if(front==NULL&&rear==NULL)
        return -1;
    if(front==rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
        front = front->link;
    x = temp->data;
    free(temp);
    return x;
}


void bfs(int n)
{
    int s = 1,x,bipartite=1;
    visited[s-1] = 1;
    level[s-1] = 0;
    enqueue(s);
    while(1)
    {
        x = dequeue();
        if(x==-1)
            break;
        cout<< x <<" ";
        for(int i=0; i<G[x-1].size(); i++)
        {
            if(visited[G[x-1][i]-1]==0)
            {
                visited[G[x-1][i]-1] = 1;
                level[G[x-1][i]-1] = level[x-1]+1;
                enqueue(G[x-1][i]);
            }
            else if(level[G[x-1][i]-1]-level[x-1] ==0)
            {
                bipartite = 0;
            }
        }
    }
    cout<<"\n"<<endl;
    if(bipartite == 0)
        cout<< "Given graph is not bipartite. ";
    else
        cout<< "Given graph is bipartite. ";
}


void initialization()
{
    for(int i=0;i<visited.size();i++)
    {
        visited[i] = 0;
        level[i] = 64000;
    }
}


int main(void)
{
    int x, y, n, m;
    cout <<"Enter number of veryices and edges: ";
    cin >> n >> m;

    G.resize(n);
    visited.resize(n);
    level.resize(n);

    cout <<"Enter edges: "<< endl;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        G[x-1].push_back(y);
        G[y-1].push_back(x);
    }

    initialization();

    cout<<endl;
    cout<<"BFS traversal is given by: "<<endl;
    bfs(n);


    
    return 0;
}