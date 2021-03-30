#include <iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main() 
{
	int t,flag,k;
	char str[100],arr[100];
	cin>>t;
	for(int _=0;_<t;_++)
	{
	    cin>>str;
	    k=0;
	    flag=1;
	    for(int i=0;i<strlen(str);i++)
	    {
	        if(str[i]=='(')
	        {
	            arr[k]=str[i];
	            k++;
	        }
	        if(str[i]==')')
	        {
	            k--;
	        }
	        if(k<-1)
	        {
	            flag=0;
	            break;
	        }
	    }
	    if(flag==0)
	        printf("Invalid\n");
	    else if(k>-1)
	        printf("Invalid\n");
	    else
	        printf("Valid\n");
	}
	return 0;
}
