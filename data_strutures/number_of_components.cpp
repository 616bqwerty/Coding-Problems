#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

vector<int> visited;
vector<int> finishr;
vector<vector<int>> G;
vector<vector<int>> Gr;
int component = 0;
int count = 1;
struct Node* top=NULL;

struct Node{
    int data;
    struct Node* link;
};

void push(int x)
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}

void pop()
{
    struct Node* temp;
    if(top == NULL)
        return;
    temp = top;
    top = top->link;
    free(temp);
}

void explore(int u)
{
    visited[u-1] = 1;
    count++;
    cout<< u <<" ";
    for(int i=0;i<G[u-1].size();i++)
    {
        if(visited[G[u-1][i]-1] == 0)
            explore(G[u-1][i]);
    }
    finishr[u-1] = count;
    pop();
    count++;
}

void dfs(int n)
{
    struct Node* temp;
    temp = top;
    while(temp!=NULL)
    {
        if(visited[temp->data-1] == 0)
        {
            component++;
            cout<< "Component "<<component<< " elements are: "<<endl;
            explore(temp->data);
            cout<<endl;
        }
        temp = temp->link;
    }
}


void exploreGr(int u)
{
    visited[u-1] = 1;
    count++;
    for(int i=0;i<Gr[u-1].size();i++)
    {
        if(visited[Gr[u-1][i]-1] == 0)
            exploreGr(Gr[u-1][i]);
    }
    finishr[u-1] = count;
    push(u);
    count++;
}

void dfsGr(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(visited[i-1] == 0)
            exploreGr(i);
    }
}

void display()
{
    cout<<"Finished time: "<<endl;
    for(int i=0;i<finishr.size();i++)
        cout<< i+1 << ": " <<finishr[i] <<endl;
}

void initialization()
{
    for(int i=0;i<visited.size();i++)
        visited[i] = 0;
}


int main(void)
{
    int x, y, n, m;
    cout <<"Enter number of vertices and edges: ";
    cin >> n >> m;

    G.resize(n);
    Gr.resize(n);
    visited.resize(n);
    finishr.resize(n);

    cout <<"Enter edges: "<< endl;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        G[x-1].push_back(y);
        Gr[y-1].push_back(x);
    }

    initialization();

    cout<<endl;
    dfsGr(n);

    cout<<endl;
    display();

    initialization();

    cout<<"Following are the strongly connected components of G:\n"<<endl;

    cout<<endl;
    dfs(n);

    return 0;
}