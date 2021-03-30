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
    int n,*v,sum,**s,part,i,k,j;
    cin>>n;
    sum=0;
    v=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    if(sum%3!=0)
        cout<<"0";
    else
    {
        s=(int**)malloc(n*sizeof(int*));
        part=sum/3;
        //cout<<part<<"\n";
        for(i=0;i<n;i++)
        {
            s[i]=(int*)malloc((part+1)*sizeof(int));
            for(j=0;j<=part;j++)
            {
                if(j==0)
                    s[i][j]=1;
                else if(i==0)
                {
                    if(v[i]==j)
                        s[i][j]=1;
                    else
                        s[i][j]=0;
                }
                else
                {
                    if(v[i]<=j)
                    {
                        s[i][j]=max(s[i-1][j-v[i]],s[i-1][j]);
                    }
                    else
                        s[i][j]=s[i-1][j];
                }
              //  cout<<"s["<<i<<"]["<<j<<"]"<<s[i][j]<<" ";
            }
           // cout<<"\n";
        }
        if(s[n-1][part]==1)
        {
            i=n-1;
            j=part;
            while(i>0&&j>=0)
            {
                if(s[i][j]==s[i-1][j])
                {
                    v[i-1]=-1;
                    i--;
                }
                else
                {
                    v[i]=-1;
                    i--;
                    j-=v[i];
                }
            }
            k=0;
            for(i=0;i<n;i++)
            {
                if(v[i]==-1)
                    continue;
                k=i;
                s[i]=(int*)malloc((part+1)*sizeof(int));
                for(j=0;j<=part;j++)
                {
                    if(j==0)
                        s[i][j]=1;
                    else if(i==0)
                    {
                        if(v[i]==j)
                            s[i][j]=1;
                        else
                            s[i][j]=0;
                    }
                    else
                    {
                        if(v[i]<=j)
                        {
                            s[i][j]=max(s[i-1][j-v[i]],s[i-1][j]);
                        }
                        else
                            s[i][j]=s[i-1][j];
                    }
                  //  cout<<"s["<<i<<"]["<<j<<"]"<<s[i][j]<<" ";
                }
               // cout<<"\n";
            }
            if(s[k][part]==1)
                cout<<"1";
            else
                cout<<"0";
        }
        else
            cout<<"0";
    }
    return 0;
}
