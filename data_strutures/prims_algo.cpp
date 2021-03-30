//Given a weighted, undirected and connected graph G, the objective is to find the minimum spanning tree G' for G using prim's algorithm
#include<iostream>
#include<stdlib.h>

using namespace std;

//to store information about ecah vertes
struct Vertex{
    int parent;     //indicates parent of a vertex in MST, for root parent = -1
    int picked;     //assigning minimum cost required to connect to the build up spanning tree
    int mst_V;      //check if vertex is in MST or not
};


int FindMinEdge(Vertex *v, int n)   //function to find minimum vertex that can be connected to MST using edge of minimum weight
{
    int min_w = 60000, min_v;

    for(int i=0;i<n;i++)
    {
        if(v[i].mst_V == 0 && v[i].picked <= min_w)   //updating minimum edge weight and also checking if the vertex is in MST or not
        {
            min_w = v[i].picked;
            min_v = i;
        }
    }
    return min_v;
}


void PrimsMST(int **G, int n)    //function to find and print minimum spanning tree
{
    Vertex *v;
    int min_cost = 0, u;
    
    v = (Vertex*)malloc(sizeof(Vertex));  //array of vertices

    //intializing picked to maximum value and presence of vertex in MST as 0
    for(int i=0;i<n;i++)
    {
        v[i].mst_V = 0;
        v[i].picked = 60000;
    }


    v[0].picked = 0;   //starting with vertex 1
    v[0].parent = -1;  //vertex is root

    for(int i = 0 ;i<n-1; i++)
    {
        u = FindMinEdge(v,n);   //finding the next vertex to be included in the MST
        v[u].mst_V = 1;         //adding it to the MST

        for(int j=0; j<n ; j++)
        {
            if(G[u][j] > 0 && v[j].mst_V == 0 && G[u][j] < v[j].picked)   //updating the cost of its neighbours which are not present in MST
            {
                v[j].parent = u;                //setting the parent as u
                v[j].picked = G[u][j];          //updating cost
            }
        }
    }

    for(int i=1; i<n;i++)        //printing all the edges and thier corresponding weights in MST
    {
        cout << "Edge " << i << endl;
        cout << "u = " <<v[i].parent+1 << "  v = " <<  i+1 << "  Cost : " << G[v[i].parent][i] << endl;
        min_cost += G[v[i].parent][i];
    }
    cout << "Total cost : " << min_cost << endl;      //Total cost of MST
    return;
}

int main(void)
{
    int n, **matrix, m, x, y;

    cout << "Enter number of vertices: ";
    cin >> n;
    
    matrix = (int**)malloc(n*sizeof(int*));

    //initializing matrix elements to 0
    for(int i=0;i<n;i++)
    {
        matrix[i] = (int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
            matrix[i][j] = 0;
    }

    cout << "Enter number of edges: ";
    cin >> m;

    cout << endl;
    cout << "Enter the endpoints of each edge and the weight of that edge: " << endl;
    for(int i=0;i<m;i++)
    {
        cout << "Endpoints of edge " << i+1 <<" : ";
        cin >> x >> y;
        cout << "Weight of edge " << i+1 << " : ";
        cin >> matrix[x-1][y-1];
        matrix[y-1][x-1] = matrix[x-1][y-1];    //since graph is undirected matrix[u][v] = matrix[v][u]
        cout << endl;
    }

    cout << "Minimum Spanning Tree is: " << endl;
    PrimsMST(matrix,n);

    cout << "-----End-----"<<endl;
    return 0;
}