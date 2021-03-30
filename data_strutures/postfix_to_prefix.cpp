//postfix to prefix
#include<bits/stdc++.h>
using namespace std;

string postfix;  
int top = -1, current=0;  
string stac[1000];   


void push(string k)   //funtion to push element
{
    if(top==-1){
        top=999;
        stac[top]=k;
    }
    else{
        top--;
        stac[top]=k;
    }
}


void pop(){         //function to pop element
    if(top==999){    
        top=-1;
    }
    else{
        top++;
    }
}


string getNextToken()     //to check whether the current token is operand or operator
{   
    string token="";
    
    if(current>=postfix.length()){
        return token;
    }
    
    if(postfix[current] >= 48 && postfix[current] <= 57){
        
        for(; current < postfix.length() ; current++){
            if(postfix[current] >= 48 && postfix[current] <= 57){
                token += postfix[current];
            }
            else{
                break;
            }
        }
        current++;
        return token;
    }
    else
    {
        token += postfix[current];
        current++;
        current++;
    }
    return token;
    
}


void PostfixToPrefix()        //function to convert postfix to prefix
{    
    string answer="";
    
    while(1)
    {
        string next = getNextToken();
        if(next=="")break;
        
        if((next[0] >= 48 && next[0] <= 57)||(next[0] >= 'a' && next[0] <= 'z')||(next[0] >= 'A' && next[0] <= 'Z')){
            push(next);
        }
        else
        {
            string op1 = stac[top];
            pop();
            string op2 = stac[top];
            pop();
            
            answer = next + " " + op2 + " " + op1 + " ";
            push(answer);
        }
    }
    cout<<"The prefix expression is: "<<stac[top]<<"\n";
}


int main()
{
    int x=1;
    while(x)
    {
        cout<<"Enter the postfix expression to be converted in prefix\n";
        cin >> postfix;
        PostfixToPrefix();
        cout<<endl;
        cout<<"To continue enter 1 else 0: ";
        cin>>x;
    }    
    return 0;
}

