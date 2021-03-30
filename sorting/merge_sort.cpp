#include <iostream>
#include<stdlib.h>
using namespace std;

void merge(long int *a,long int *l,long int *r,long int lc,long int rc)
{
    long int i,j,k;
    i=0;
    j=0;
    k=0;
    while(j<lc&&k<rc)
    {
        if(l[j]<r[k])
        {
            a[i]=l[j];
            j++;
        }
        else
        {
            a[i]=r[k];
            k++;
        }
        i++;
    }
    while(j<lc)
    {
        a[i]=l[j];
        i++;
        j++;
    }
    while(k<rc)
    {
        a[i]=r[k];
        i++;
        k++;
    }
}

void mergesort(long int *a,long int n)
{
    long int *l,*r,mid,i,j;
    if(n<2)
        return;
    mid=n/2;
    l=(long int*)malloc(mid*sizeof(long int));
    r=(long int*)malloc((n-mid)*sizeof(long int));
    i=0;
    j=0;
    while(i<mid)
    {
        l[j]=a[i];
        j++;
        i++;
    }
    j=0;
    while(i<n)
    {
        r[j]=a[i];
        j++;
        i++;
    }
    mergesort(l,mid);
    mergesort(r,n-mid);
    merge(a,l,r,mid,n-mid);
}

int main() 
{
    long int n,*a,i;
    cin>>n;
    a=(long int*)malloc(n*sizeof(long int));
    for(i=0;i<n;i++)
        cin>>a[i];
    mergesort(a,n);
    for(i=0;i<n;i++)
        cout<<a[i]<<"\n";
	return 0;
}
