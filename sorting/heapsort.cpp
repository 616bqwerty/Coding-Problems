#include<iostream>
#include<stdlib.h>

using namespace std;

void heapify(int *heap,int size)
{
    int i, temp;
    i = size;
    while(i>0)
    {
        if(heap[i] >= heap[((i+1)/2)-1])
            return;
        temp = heap[i];
        heap [i] = heap[(i+1)/2 -1];
        heap[(i+1)/2 -1] = temp;
        i = (i+1)/2 -1;
    }
}

void adjust(int *heap,int root,int n)
{
    int r,l,temp,small = -1;
    r = ((root+1)*2+1) - 1;
    l = (root+1)*2 - 1;
    if(r>n && l>n)
        return;
    if(r>n)
    {
        if(heap[root]>heap[l])
        {
            small = l;
        }
    }
    else if(heap[r]>heap[l])
    {
        small = l;
    }
    else if(heap[l]>=heap[r])
    {
        small = r;
    }
    if(small>=0 && heap[root]>heap[small])
    {
        temp = heap[root];
        heap[root] = heap[small];
        heap[small] = temp;
        adjust(heap,small,n);
    }
    return;
}

void heapsort(int *heap, int n)
{
    int temp, j, root, small;
    root = 0;
    j = n-1;
    while(j>0)
    {
        temp = heap[root];
        heap[root] = heap[j];
        heap[j] = temp;
        j--;
        adjust(heap,root,j);
    }
}

int main(void)
{
    int n,*heap;
    cin>>n;
    heap = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        cin>>heap[i];
        heapify(heap,i);
        // for(int j=0;j<=i;j++)
        //     cout<<heap[j]<<" ";
        // cout<<endl;
    }
    cout<<"Heapify: "<<endl;
    for(int i=0;i<n;i++)
        cout<<heap[i]<<" ";
    cout<<endl;
    heapsort(heap,n);
    cout<<"Sorted elements: "<<endl;
    for(int i=0;i<n;i++)
        cout<<heap[i]<<" ";
    return 0;
}