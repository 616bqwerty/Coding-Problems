/*
Array implementation of priority queue. In this implementation, assume the maximum size of all 1D queues are the same. 
Thus, you can use a 2D array for implementing the priority queue. Each 1D queue is to be implemented as a circular queue.
*/

#include<iostream>
#include<stdlib.h>
#define Max 1000

using namespace std;


//to store front and rear indices for each priority
struct Priority{
    int front;
    int rear;
};

Priority p[5][2];               // array for storing front and rear of each priority
char queue[5][1000];            // array to represent multiple queues for different priority

void initialize()              //function to initialize front and rear of each priority
{

    for(int i=0; i<5 ; i++)
    {
        p[i]->front = -1;
        p[i]->rear = -1;
    }

}

int Enqueue(char c, int priority)         //function to enqueue 
{
    int rear, front;
    rear = p[priority]->rear;
    front = p[priority]->front;

    if(front == -1 && rear == -1)        //to check if queue is empty
    {
        p[priority]->front = p[priority]->rear = 0;
        queue[priority][0] = c;
        return 1;
    }

    rear ++;

    if(rear == Max)
    {
        rear = 0;
    }

    if(rear == front)              //to check if queue of priority  if full
    {
        cout<<"---Queue is full---"<<endl;
        return 0;
    }

    queue[priority][rear] = c;
    p[priority]->rear = rear;
    return 1;
}

int Dequeue()                  //function to dequeue
{
    int i;

    for(i=0; i<5; i++)
    {

        if(p[i]->front == -1 && p[i]->rear == -1)      //to check if queue of ith priority is empty
        {
            continue;
        }

        if(p[i]->front == p[i]->rear)     //to check if only one element is present in the queue of ith priority
        {
            p[i]->front = -1;
            p[i]->rear = -1;
        }
        else
        {
            p[i]->front ++;
            if(p[i]->front == Max)
                p[i]->front = 0;
        }
        
        return 1;

    }

    cout<<"--No deletion possible, queue is empty--"<<endl;
    return 0;
}

void print_queue()         //function to print queue
{
    int front, rear;

    for(int i=0 ; i<5 ;i++)
    {

        front = p[i]->front;
        rear = p[i]->rear;

        if(front==-1 && rear==-1)    //to check if queue of ith priority is empty
            continue;

        for(int j=front; ; j++)
        {

            if(j == Max)
            {
                j = -1;
                continue;
            }

            cout<<queue[i][j]<<" ";

            if(j == rear )
                break;

        }

    }
    cout<<endl;
}

int main(void)
{
    int x = 1, priority, check;
    char c;

    initialize();        //initializing rear and front for each queue

    while(x)             //menu driven to modify queue
    {

        cout<<"Enter 1 to Enqueue or 2 to Dequeue"<<endl;
        cin>>x;

        switch(x)
        {
            case 1: cout<<"Enter charater to Enqueue: "<<endl;
                    cin >> c;
                    cout<<"Enter priority of character: "<<endl;
                    cin >> priority;
                    check = Enqueue(c,priority-1);
                    break;
            
            case 2: check = Dequeue();
                    break;

            default : cout<<"Invalid Entry"<<endl;

        }

        if(check)        //printing queue if it was succesfully modified
        {
            cout<<"Queue is:"<<endl;
            print_queue();
            cout<<endl;
        }
        

        cout<<"Enter 1 to continue else 0:"<<endl;
        cin >> x;

    }

    return 0;
}