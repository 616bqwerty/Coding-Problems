#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

vector<int> visited;
vector<vector<int>> G;
vector<int> disct;
vector<int> finish;
struct Node* top=NULL;
int count = 1;

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

void initialization()
{
    for(int i=0;i<visited.size();i++)
        visited[i] = 0;
}

void explore(int u)
{
    visited[u-1] = 1;
    cout<< u <<" ";
    disct[u-1] = count;
    count++;
    for(int i=0;i<G[u-1].size();i++)
    {
        if(visited[G[u-1][i]-1] == 0)
            explore(G[u-1][i]);
    }
    finish[u-1] = count;
    push(u);
    count++;
}

void dfs(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(visited[i-1] == 0)
            explore(i);
    }
}

void display()
{
    struct Node* temp;
    temp = top;
    cout<< "Topological order is: "<<endl;
    while(temp !=NULL)
    {
        cout<< temp->data<<" ";
        temp = temp->link;
    }
}

int main(void)
{
    int x, y, n, m;
    cout <<"Enter number of Gices and edges: ";
    cin >> n >> m;

    G.resize(n);
    visited.resize(n);
    disct.resize(n);
    finish.resize(n);

    cout <<"Enter edges: "<< endl;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        G[x-1].push_back(y);
    }

    initialization();

    // cout<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<G[i].size();j++)
    //         cout<< G[i][j] <<" ";
    //     cout<< endl;
    // }

    cout<<endl;

    cout<< "Traversal order is: "<<endl;
    dfs(n);

    cout<<endl;
    display();

    return 0;
}