//Minimum number of operations to perform to convert s2 to s1
#include <iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;


int main() 
{
    char s1[100],s2[100];
    int str[101][101],l1,l2;
    cin>>s1;
    cin>>s2;
    l1=strlen(s1);
    l2=strlen(s2);
    for(int i=0;i<l2+1;i++)
    {
        for(int j=0;j<l1+1;j++)
        {
            if(i==0)
                str[i][j]=j;
            else if(j==0)
                str[i][j]=i;
            else
            {
                if(s2[i-1]==s1[j-1])
                    str[i][j]=str[i-1][j-1];
                else 
                {
                    if(str[i-1][j-1]<=str[i-1][j]&&str[i-1][j-1]<=str[i][j-1])
                        str[i][j]=str[i-1][j-1]+1;
                    else if(str[i-1][j]<=str[i-1][j-1]&&str[i-1][j]<=str[i][j-1])
                        str[i][j]=str[i-1][j]+1;
                    else if(str[i][j-1]<=str[i-1][j-1]&&str[i][j-1]<=str[i-1][j])
                        str[i][j]=str[i][j-1]+1;
                }
            }
          //  cout<<str[i][j]<<" ";
        }
       // cout<<"\n";
    }
    cout<<str[l2][l1];
    return 0;
}
