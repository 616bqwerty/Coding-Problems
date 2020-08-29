//The maximum weight of gold that fits into a knapsack of capacity w
#include <iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int max(long int x,long int y)
{
    if(x>y)
        return x;
    else 
        return y;
}

int main() 
{
    int w,n,sum;
    long int *a,**v;
    cin>>w;
    cin>>n;
    v=(long int**)malloc(n*sizeof(long int*));
    sum=0;
    a=(long int*)malloc(n*sizeof(long int));
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        v[i]=(long int*)malloc((w+1)*sizeof(long int));
        for(int j=0;j<=w;j++)
        {
            if(j==0)
                v[i][j]=0;
            else if(i==0)
            {
                if(j<a[i])
                    v[i][j]=0;
                else 
                    v[i][j]=a[i];
            }
            else if(j>=a[i])
            {
                v[i][j]=max(v[i-1][j],v[i-1][j-a[i]]+a[i]);
            }
            else
                v[i][j]=v[i-1][j];
           // cout<<v[i][j]<<"  ";
        }
       // cout<<"\n";
    }
    cout<<v[n-1][w];
    return 0;
}
