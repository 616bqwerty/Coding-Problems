#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

vector<vector<pair<int,int>>> G;
vector<int> set;
vector<int> flag;
vector<int> dist;
vector<pair<int,int>> heap;

struct Queue{
    int vertex;
    Queue *next;
};

Queue *front = NULL;
Queue *rear = NULL;


void initialization()
{

    for(int i=0; i < set.size(); i++)
    {
        dist[i] = 61678;
        set[i] = 0;
    }

}

void makeheap(int S)
{
    heap[0].first = S;
    heap[0].second = 0;
    for(int i=1; i<heap.size(); i++)
    {
        heap[i].first = i+1;
        heap[i].second = dist[i];
    }
}

int extract_min()
{
    int x, l, i, small;
    pair<int,int> temp;
    l = heap.size();

    if(l==0)
        return -1;

    x = heap[0].first;
    heap[0] = heap[l-1];
    heap.pop_back();

    // cout << "Extract " << heap.size()<< endl;
    // for(i=0; i<heap.size(); i++)
    //      cout<< heap[i].first << " " << heap[i].second << endl;

    i = 0;

    while(2*i < heap.size() && (2*i - 1) < heap.size())
    {
        if(heap[2*i -1].second <= heap[2*i].second)
            small = 2*i - 1;
        else
            small = 2*i;
        
        if(heap[small].second >= heap[i].second)
            break;
        
        temp = heap[small];
        heap[small] = heap[i];
        heap[i] = temp;

        i = small;

    }

    return x;

}

void decrease_key(int v, int w)
{

    int i, small, mark;
    pair<int,int> temp;

    for(i=0; i < heap.size() ; i++)
        if(heap[i].first == v)
        {
            mark = i;
            heap[i].second = w;
            break;
        }    
    
    i = mark;
    while( i>=1 && heap[(i+1)/2 -1].second > heap[i].second)
    {
        temp = heap[i];
        heap[i] = heap[(i+1)/2 -1];
        heap[(i+1)/2 -1] = temp;
    }

    // cout << "Decrease " << heap.size()<< endl;
    // for(i=0; i<heap.size(); i++)
    //      cout<< heap[i].first << " " << heap[i].second << endl;


}

void dijkshtras(int S)
{
    int x;
    dist[S-1] = 0;

    makeheap(S);

    

    while(heap.size()>0)
    {
        x = extract_min();
        set[x-1] = 1;
        //cout << heap.size() << " "<< x <<endl;
        for(int i=0; i < G[x-1].size() ; i++)
        {
            if(set[G[x-1][i].first -1] == 1)
                continue;
            if(dist[G[x-1][i].first -1] > dist[x-1] + G[x-1][i].second)
            {
                dist[G[x-1][i].first -1] = dist[x-1] + G[x-1][i].second;
                decrease_key(G[x-1][i].first, dist[x-1] + G[x-1][i].second);
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
    dist.resize(n);
    set.resize(n);
    heap.resize(n);

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

    dijkshtras(source);

    return 0;
}