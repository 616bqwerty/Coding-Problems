//Linked list implementation of priority queue.

#include<iostream>
#include<stdlib.h>

using namespace std;


//to store data
struct Queue{
    char data;                
    int priority;
    struct Queue *next;
};

struct Queue *head = NULL;             //Linked list to maintain the queue   


void Enqueue(char ch, int p)          //function to enqueue element in into queue
{
    struct Queue *temp, *i;

    temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->data = ch;
    temp->priority = p;

    if(head == NULL)                 //to check if queue is empty
    {
        temp->next = NULL;
        head = temp;
        return;
    }

    i = head;
    while(i->priority <= temp->priority && i!=NULL)      //scanning the list until the element with pririoty less than current element is found
    {
        i = i->next;
    }

    temp->next = i->next;
    i->next = temp;
}

void Dequeue()                //function to dequeue
{
    struct Queue *temp;

    if(head==NULL)                        //checking if the queue is empty
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

void print_queue()                     //function to print queue
{
    struct Queue *temp;

    if(head==NULL)                   //checking if the queue is empty
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(void)
{
    int x = 1, priority;
    char c;
    while(x)                  //menu driven to modify queue
    {
        cout<<"Enter 1 to Enqueue else 2 to Dequeue: "<<endl;
        cin >> x;
        fflush(stdin);

        switch(x)
        {
            case 1: cout<<"Enter charater to Enqueue: "<<endl;
                    cin >> c;
                    cout<<"Enter priority of character: "<<endl;
                    cin >> priority;
                    Enqueue(c,priority);
                    break;
            
            case 2: Dequeue();
                    break;

            default : cout<<"Invalid Entry"<<endl;

        }
        
        cout<<"Queue is:"<<endl;
        print_queue();
        cout<<endl;

        cout<<"Enter 1 to continue else 0:"<<endl;
        cin >> x;
    }
    return 0;
}