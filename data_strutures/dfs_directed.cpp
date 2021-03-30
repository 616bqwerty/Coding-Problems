#include<iostream>
#include<vector>

using namespace std;

vector<int> visited;
vector<vector<int>> G;
vector<int> disct;
vector<int> finish;
int count = 1;

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
    cout<<"Discovery time: "<<endl;
    for(int i=0;i<disct.size();i++)
        cout<< i+1 << ": " <<disct[i] <<endl;
    cout<< endl;
    cout<<"Finished time: "<<endl;
    for(int i=0;i<finish.size();i++)
        cout<< i+1 << ": " <<finish[i] <<endl;
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

    dfs(n);

    cout<<"\n"<<endl;

    display();

    return 0;
}