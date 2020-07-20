#include <iostream>
#include<stdlib.h>
using namespace std;

long int partition(long int *a,long int start,long int end)
{
    long int pI,pivot,i,temp;
    pI=start;
    pivot=a[end-1];
    for(i=start;i<end-1;i++)
    {
        if(a[i]<=pivot)
        {
            temp=a[i];
            a[i]=a[pI];
            a[pI]=temp;
            pI=pI+1;
        }
    }
    temp=a[end-1];
    a[end-1]=a[pI];
    a[pI]=temp;
    return pI;
}

void quicksort(long int *a,long int start,long int end)
{
    long int pI;
    if(start<end)
    {
        pI=partition(a,start,end);
        quicksort(a,start,pI);
        quicksort(a,pI+1,end);
    }
}

int main() 
{
    long int n,*a,i;
    cin>>n;
    a=(long int*)malloc(n*sizeof(long int));
    for(i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
	return 0;
}
