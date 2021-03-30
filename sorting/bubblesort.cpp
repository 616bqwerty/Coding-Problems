#include<iostream>
#include<stdlib.h>

using namespace std;

int main(void){
    int n,*a,j,i,temp;
    cin>>n;
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[j]<a[j-1])
            {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}