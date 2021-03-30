#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{
    int noden;
    Node* parent;
    int height;
};

int findh(struct Node *x)
{
    if(x->parent==NULL)
        return 1;
    if((x->parent)->height==0)
    {
        return findh(x->parent)+1;
    }
    else
    {
        return 1+(x->parent)->height;
    }
}

int main(void)
{
    long int n,i,height,c,hc;
    struct  Node *a;
    cin>>n;
    a=(struct Node*)malloc(n*sizeof(struct Node));
    for(i=0;i<n;i++)
    {
        cin>>c;
        a[i].noden=i;
        if(c==-1)
            a[i].parent=NULL;
        else
            a[i].parent=&a[c];
        a[i].height=0;
    }
    height=0;
    for(i=0;i<n;i++)
    {
        hc=1;
        if(a[i].parent==NULL)
            hc=1;
        else
        {
            if((a[i].parent)->height==0)
            {
                hc=findh(a[i].parent)+1;
                a[i].height=hc;
            }
            else
            {
                a[i].height=1+(a[i].parent)->height;
                hc=a[i].height;
            }
        }
        if(hc>height)
            height=hc;
    }
    cout<<height;
    return 0;
}