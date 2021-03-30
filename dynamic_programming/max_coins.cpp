/*There are N coins, you and your friend decide to pick coins alternately. At every turn you can perform any one of the folllowing operations:
   1)Pick one coin 2)Pick half coins if number of coins is divisible by 2
  You start playing first. Print the maximum number of coins you get by the end.
  Other player plays optimally.
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int main(void)
{
    int n,*a,i;
    cin>>n;              //number of coins
    a=(int*)malloc((n+1)*sizeof(int));
    for(i=0;i<=n;i++)
    {
        if(i==0)
            a[i]=0;
        else if(i==1||i==2)
            a[i]=1;
        else if(i%2!=0)
            a[i]=1+(i-1)-a[i-1];
        else
        {
            a[i]=max(1+(i-1)-a[n-1],i/2+i/2-a[i/2]);
        }
    }
    cout<<a[n];
    return 0;
}