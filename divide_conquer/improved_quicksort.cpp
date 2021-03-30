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
    long int pI,i1,i2,i,temp;
    if(start<end)
    {
        pI=partition(a,start,end);
        i1=pI;
        i2=pI;
        i=0;
        while(i<i1)
        {
            if(a[i]==a[pI])
            {
                temp=a[i];
                a[i]=a[i1-1];
                a[i1-1]=temp;
                i1=i1-1;
            }
            i++;
        }
        i=end-1;
        while(i>i2)
        {
             if(a[i]==a[pI])
            {
                temp=a[i];
                a[i]=a[i2-1];
                a[i2-1]=temp;
                i2=i2+1;
            } 
            i--;
        }
        //cout<<i1<<" "<<i2<<"\n";
        quicksort(a,start,i1);
        quicksort(a,i2+1,end);
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
