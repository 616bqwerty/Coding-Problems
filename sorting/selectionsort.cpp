#include<iostream>
#include<stdlib.h>

using namespace std;

int main(void){
    int n,*a,j,i,temp,small;
    cin>>n;
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n-1;i++)
    {
        small=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[small])
                small=j;
        }
        temp=a[small];
        a[small]=a[i];
        a[i]=temp;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}