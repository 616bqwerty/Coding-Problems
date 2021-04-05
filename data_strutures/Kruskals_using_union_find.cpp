/*
Implementation of Kruskal's Minimum Spanning Tree Algorithm using union find Data Structure
*/

#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

vector<pair<pair<int,int>,int>> G;          //Given weighted undirected grapg G with n vertices, m edges
vector<pair<pair<int,int>,int>> MST;        //Required Minimum Spanning Tree with n vertices, n-1 edges
vector<int> V;                              //Vertex vector to store parent of each vertex in set
//root condition : V[i] = i --> i is the root of the component to which it belongs
vector<int> size_c;                           //Vector to denote the size_c of component set to which the fiven vertex belongs
int components;                             //number of components

//function to merge the sorted edges 
void merge(vector<pair<pair<int,int>,int>> &G, vector<pair<pair<int,int>,int>> &l, vector<pair<pair<int,int>,int>> &r, int lc, int rc)
{
    int i, j, k;
    i = j = k = 0;

    while(j < lc && k < rc)      //merging to sorted vectors of edges
    {
        if(l[j].second < r[k].second)
            G[i++] = l[j++];
        else
            G[i++] = r[k++];
    }

    while(j < lc)
        G[i++] = l[j++];
    
    while(k < rc)
        G[i++] = r[k++];

    return;
}

//function to sort the edges in increasing order according to thier weights
void mergesort(int m, vector<pair<pair<int,int>,int>> &G)
{
    vector<pair<pair<int,int>,int>> l, r;
    int mid, i, j;
    if(m < 2)
        return;
    
    mid = m/2;            //middle index 
    l.resize(mid);        //left sub vector
    r.resize(m-mid);      //right sub vector

    i = j = 0;
    while(i < mid)
        l[j++] = G[i++];
    
    j = 0;
    while(i < m)
    {
        r[j++] = G[i++];
    }
    
    mergesort(mid, l);
    mergesort(m-mid, r);
    merge(G, l, r, mid, m-mid);

    return;
}

//function to find the set to which the given vertex belongs
int find(int u)
{
    int root = u, parent;
    
    while(root != V[root-1])     //finding the root of the component to which vertex u belongs, until the root condition is satisfied
        root = V[root-1];

    while(u != root)             //path compression : setting the root as the parent of u
    {
        parent = V[u-1];
        V[u-1] = root;
        u = parent;
    }

    return root;
}

//function to perform union of two sets or two component trees
void make_union(int u, int v)
{
    int root1, root2, count1, count2;

    root1 = u;
    root2 = v;

    count1 = size_c[root1-1];       //no of elements in set 1
    count2 = size_c[root2-1];       //no of elements in set 2

    //merging two sets such that the smaller set is merged into the larger set
    if(count1 > count2)
    {
        V[root2-1] = root1;
        size_c[root1-1] += count2;
    }
    else
    {
        V[root1-1] = root2;
        size_c[root2-1] += count1;
    }

    components--;        //decreasing the  number of components

    return;
}

//Kruskals Algorithm function to find MST
void Kruskals_Algorithm(int n, int m)
{
    int i, j, root1, root2;

    mergesort(m, G);          //sorting all the edges in increasing order of their weights

    // debug
    // for(int i=0;i<m;i++)
    //     cout << G[i].first.first << " " << G[i].first.second << " " << G[i].second << endl;

    MST.resize(n-1);

    // i : G, j : MST
    for(i=0, j=0; i<m && j<n-1 ; i++)
    {
        //finding roots of both the endpoints of current edge
        root1 = find(G[i].first.first);    
        root2 = find(G[i].first.second);

        // debug
        // cout << root1 << " " << root2 << endl;
        
        if(root1 == root2)    //Both the vertices belong to same set hence will form a cycle thus edge must not be included in MST
            continue;

        make_union(root1,root2);   //both vertices belong to different components hence perform the union of both the components
        
        //adding the edge to the MST
        MST[j].first.first = G[i].first.first;
        MST[j].first.second = G[i].first.second;
        MST[j].second = G[i].second;

        j++;  

    }

    cout << endl;

    cout << "Required MST is : " << endl;

    //printing all the edges of MST
    for(i=0; i< n-1 ;i++)
    {
        cout << "Edge " << i+1 << " :" << endl;
        cout << MST[i].first.first << " " << MST[i].first.second << " " << MST[i].second << endl;
    }

    return;
}


int main(void)
{
    int n, m, u, v, w;

    cout << "Enter number of nodes in G : " ;
    cin >> n;

    cout << "Enter number of edges: " ;
    cin >> m;


    G.resize(m);        //size of G : number of edges
    V.resize(n);        //size of V : number of vertices
    size_c.resize(n);   //size of size_c : number of vertices

    cout << "Enter endpoints of edges: " << endl;
    for(int i=0;i<m;i++)
    {
        cout << "Edge " << i+1 << " endpoints: ";
        cin >> u >> v;
        cout << "Enter edge weight: ";
        cin >> w;

        G[i].first.first = u;
        G[i].first.second = v;
        G[i].second = w;
    }

    //initializing V  and size_c
    for(int i=0;i<n;i++)
    {
        V[i] = i+1;           //initially each vertex is the root since there are n components
        size_c[i] = 1;        //initially size of each component is one since each component has only vertex
    }
        
    components = n;         //initial number of components

    Kruskals_Algorithm(n,m);

    return 0;
}