//infix to postfix
#include<iostream>
#include<stdlib.h>
#include<string>

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
    if(op=='(')
        return 4;
    return 5;
}

int getNextToken(char c)  //to check whether the current input is an operant or operator
{
    if(c =='+'|| c =='-'|| c =='*' || c =='/' || c =='^'|| c =='('|| c ==')')
        return 0;
    return 1;  
}

void infixToPostfix(string exp)   //function to convert infix to postfix expression
{
    int x,top,prevx;
    char stack[10000];           //stack of operators
    top = -1;                    //topmost element in stack
    for(int i=0;i<exp.length();i++)
    {
        x = getNextToken(exp[i]);
        if(x==0)
        {
            if(i>0&&prevx!=0)   //checks if previous element was operator and gives spacing accordingly in the expression
                cout<<" ";
            if(top==-1)
            {
                top++;
                stack[top] = exp[i];
            }
            else if(exp[i]=='(')
            {
                stack[++top] = exp[i];
            }
            else if(exp[i]==')')
            {
                while(stack[top]!='(')
                {
                    cout<<stack[top]<<" ";
                    top--;
                }
                top--;
            }
            else
            {
                while(top>=0 && precedence(exp[i])>=precedence(stack[top]))
                {
                    cout<<stack[top]<<" ";
                    top--;
                }
                stack[++top] = exp[i];
            }
        }
        else
        {
            cout<<exp[i];
        }
        prevx = x;
    }
    while(top>=0)   //prints the remaining elements left in the stack
    {
        cout<<" "<<stack[top];
        top--;
    }
}


int main(void)
{
    string str;
    int x=1;
    while(x)
    {
        fflush(stdin);
        cout<<"Enter the infix expression to be converted to postfix: "<<endl;
        cin>>str;
        cout<<"Postfix expression is:"<<endl;
        infixToPostfix(str);
        cout<<endl;
        cout<<"To continue enter 1 else 0: ";
        cin>>x;
    }
    
    return 0;
}