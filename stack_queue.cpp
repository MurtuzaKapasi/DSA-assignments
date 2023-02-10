//Write a C++ program to implement the following data structures and its operations using linked list:
//i) Stack ii) Queue.
//murtuza kapasi

#include <iostream>
using namespace std;

struct node{
int data;
node *next;
};

class stack{
node *nn;
public:
node *head;
stack()
{
    head=NULL;
}
void push();
void pop();
void display();
};

void stack::push(){
    node *top;
    nn=new node;
    cout<<"Enter data: ";
    cin>>nn->data;             
    if(head==NULL)
    {
        head=nn;
        nn->next=NULL;
    }
    else 
    {
        nn->next=head;
        head=nn;
    }
}
void stack::display(){
    node *cn;
    cn=head;
     if(head==NULL)
    {
        cout<<"Stack is empty\n";
    }
    else{
    while(cn!=NULL)
        {
            cout<<cn->data<<endl;
            cn=cn->next;
        }
        }
}
void stack::pop(){
    node *cn;
    cn=head;
     if(head==NULL)
    {
        cout<<"Stack is empty\n";
    }
    else{
    head=head->next;
    delete cn;
    }
}

class queue{
node *nn;
public:
node *front,*rear;
queue()
{
    rear=NULL;
    front=NULL;
}
void Enqueue();
void Dequeue();
void display();
};

void queue::Enqueue(){
    cout<<"Enter data: ";
    nn=new node;
    cin>>nn->data;
    nn->next=NULL;
    
    if(rear==NULL)
    {
        rear=nn;
        front=nn;
    }
    else
    {
        node *cn;
        cn=front;
        while(cn->next!=NULL)
            {
                cn=cn->next;
            }
        cn->next=nn;
        rear=nn;
    } 
}
void queue::Dequeue(){
    node *cn;
    cn=front;
    if(front==NULL)
    {
        cout<<"Queue is empty\n";
    }
    else{
    front=front->next;
    delete cn;
        }
}
void queue::display(){
    node *cn;
    cn=front;
     if(front==NULL)
    {
        cout<<"Queue is empty\n";
    }
    else
     {
    while(cn!=NULL)
        {
            cout<<cn->data<<" ";
            cn=cn->next;
        }
    }
}

int main(){
    cout<<" ||  Stack and Queue  ||\n";
    int ch;
    stack s;
    queue q;
    start:
    cout<<"1.Stack   2.Queue    3.Quit: ";
    cin>>ch;
    switch(ch)
        {
        case 1:
            cout<<"  || Stack  ||\n";
            while(1){
            cout<<"1.Insert\t2.Delet\t3.Display\t4.Exit\n";
            cout<<"Enter operation: ";
            int t;
            cin>>t;
            switch(t)
                {
                    case 1:
                    s.push();
                    break;
                    case 2:
                    s.pop();
                    break;
                    
                    case 3:
                    s.display();
                    break;
                    
                    case 4:
                    goto start;
                    break;
                }
            }

        case 2:
            cout<<"  || Queue  ||\n";
            while(1){
            cout<<"\n1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n";
            cout<<"Enter operation: ";
            int t;
            cin>>t;
            switch(t)
                 {
                    case 1:
                    q.Enqueue();
                    break;
                    case 2:
                    q.Dequeue();
                    break;
                    
                    case 3:
                    q.display();
                    break;
                    
                    case 4:
                    goto start;
                    break;
                }
            }
            
        case 3:
            return 0;
            
        }     
}
