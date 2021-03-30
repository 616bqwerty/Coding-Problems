//infix to postix
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int Push(char *arr,int top,char x)   //function to puch elemnt into stack
{
    int i;
    top++;
    arr[top-1] = x;
    return top;
}


int precedence(char op)    //to check the precedence of operator 
{                          //operator with highest precedence has lowest numbering
    if(op=='^')
        return 1;
    if(op=='*'||op=='/')
        return 2;
    if(op=='+'||op=='-')
        return 3;
    if(op==')')
        return 4;
    return 5;
}

int getNextToken(char c)  //to check whether the current input is an operant or operator
{
    if(c =='+'|| c =='-'|| c =='*' || c =='/' || c =='^'|| c =='('|| c ==')')
        return 0;
    return 1;  
}

void infixToPrefix(char *exp)   //function to convert infix to prefix expression
{                                //it converts the reverse of infix expression to postfix
    char str1[1000];
    int x,top,prevx,j;
    char stack[10000];           //stack of operators
    top = -1;                    //topmost element in stack
    strrev(exp);
    j = 0;
    for(int i=0;i<strlen(exp);i++)
    {
        x = getNextToken(exp[i]);
        if(x==0)
        {
            if(i>0&&prevx!=0)   //checks if previous element was operator and gives spacing accordingly in the expression
            {
                str1[j]=' ';
                j++;
            }
            if(top==-1)
            {
                top++;
                stack[top] = exp[i];
            }
            else if(exp[i]==')')
            {
                stack[++top] = exp[i];
            }
            else if(exp[i]=='(')
            {
                while(stack[top]!=')')
                {
                    str1[j++]=stack[top];
                    str1[j++]=' ';
                    top--;
                }
                top--;
            }
            else
            {
                while(top>=0 && precedence(exp[i])>precedence(stack[top]))
                {
                    str1[j++]=stack[top];
                    str1[j++]=' ';
                    top--;
                }
                stack[++top] = exp[i];
            }
        }
        else
        {
            str1[j++]=exp[i];
        }
        prevx = x;
    }
    while(top>=0)   
    {
        str1[j++]=' ';
        str1[j++]=stack[top];
        top--;
    }
    strrev(str1);
    strcpy(exp,str1);
    cout<<"Pretfix expression is:"<<endl;
    cout<<exp;
}


int main(void)
{
    char str[1000];
    int x=1;
    while(x)
    {
        fflush(stdin);
        cout<<"Enter the infix expression to be converted to prefix: "<<endl;
        cin>>str;
        infixToPrefix(str);
        cout<<endl;
        cout<<"To continue enter 1 else 0: ";
        cin>>x;
    }
    return 0;
}