#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

vector<vector<pair<int,int>>> G;
vector<int> visited;
vector<int> flag;
vector<int> dist;

struct Queue{
    int vertex;
    Queue *next;
};

Queue *front = NULL;
Queue *rear = NULL;

void enqueue(int x)
{
    Queue *temp, temp1;
    temp = (Queue*)malloc(sizeof(Queue));
    temp->vertex = x;

    if(front == NULL && rear == NULL)
    {
        temp->next = NULL;
        front = temp;
        rear = temp;
        return;
    }

    rear->next = temp;
    temp->next = NULL;
    rear = temp;

}

int dequeue()
{
    Queue *temp;
    int x;

    if(front == NULL)
    {
        return -1;
    }

    temp = front;
    x = temp->vertex;

    if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
    }

    free(temp);
    return x;

}

void initialization()
{

    for(int i=0; i < visited.size(); i++)
    {
        dist[i] = 61678;
        flag[i] = 0;
        visited[i] = 0;
    }

}

void shortest_path_bfs(int S)
{
    int x;
    dist[S-1] = 0;
    enqueue(S);
    flag[S-1] = 1;
    while(1)
    {
        x = dequeue();
        if(x == -1)
            break;
        flag[x-1] = 0;
        for(int i=0; i < G[x-1].size(); i++)
        {
            //cout << x << " " << G[x-1][i].first << " " << dist[x-1] + G[x-1][i].second << " " << dist[G[x-1][i].first - 1] <<endl;
            if(dist[x-1] + G[x-1][i].second < dist[G[x-1][i].first - 1])
            {
                dist[G[x-1][i].first - 1] = dist[x-1] + G[x-1][i].second;
                if(flag[G[x-1][i].first - 1] == 0)
                {
                    enqueue(G[x-1][i].first);
                    flag[G[x-1][i].first - 1] = 1;
                }
                
            }
        }
    }

    cout << "Distance of each vertex from source is: " <<endl;

    for(int i=0; i < dist.size() ; i++)
        cout << i + 1 << " " <<  dist[i] <<endl;
}

int main(void)
{
    int n, m, x, y, w, source;

    cout << "Enter number of vertices: "<<endl;
    cin >> n;

    cout << "Enter number of edges: "<<endl;
    cin >> m;

    G.resize(n);
    visited.resize(n);
    flag.resize(n);
    dist.resize(n);

    cout << "Enter the edges and thier weights: "<<endl;

    for(int i=0; i<m;i++)
    {
        cout << "Edge: ";
        cin >> x >> y;
        cout << "Weight: ";
        cin >> w;
        G[x-1].push_back(make_pair(y,w));
        G[y-1].push_back(make_pair(x,w));
    }

    initialization();

    cout << "Enter the vertex number from which to find the shortest paths: ";
    cin >> source;

    // for(int i=0; i<n;i++)
    // {
    //     for(int j=0; j< G[i].size(); j++)
    //     {
    //         cout << i+1 << " " << G[i][j].first << " " << G[i][j].second <<endl;
    //     }
    // }

    shortest_path_bfs(source);

    return 0;
}