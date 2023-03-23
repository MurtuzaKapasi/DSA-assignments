//Write a C++ program to implement a singly link list and perform operations such as insert,delete, display, search element from it and reverse the list.
//murtuza kapasi

#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
class sll{
    node *nn;
    public:
    node *header;
    sll()
    {
        header=NULL;
    }
    void display();
    void insert_end();
    void insert_beg();
    void insert_pos();
    void delet_beg();
    void delet_end();
    void delet_pos();
    void search();
    void reverse(node *cn);
};

void sll::insert_end()
{   
    nn=new node;
    cout<<"Enter data: ";
    cin>>nn->data;
    nn->next=NULL;
    if(header==NULL)
    {
        header=nn;
    }
    else{
        node *cn;
        cn=header;
        while(cn->next!=NULL)
        {
            cn=cn->next;
        }
        cn->next=nn;
    }
}
void sll::insert_beg()
{
    nn=new node;
    cout<<"Enter data: ";
    cin>>nn->data;
    if(header==NULL)
    {
        header=nn;
        nn->next=NULL;
    }
    else{
        nn->next=header;
        header=nn;
    }
}
void sll::insert_pos()
{
    int p,count=0;
    cout<<"Enter the position to insert data: ";
    cin>>p;
    node *cn;
    cn=header;
    while(cn!=NULL)             
    {
        count++;
        cn=cn->next;
    }
    // cout<<"Length is: "<<count<<endl;
    if(p==1)
    {
        insert_beg();
    }
    else if(p==count+1)
    {
        insert_end();
    }
    else if(p>count+1)
    {
        cout<<"Insertion not possoble\n";
    }
    else 
    {
        nn=new node;
        cout<<"Enter data: ";
        cin>>nn->data;
        node *cn;
        cn=header;
        for(int i=1 ; i<p-1 ; i++)
        {
            cn=cn->next;
        }
        nn->next=cn->next;
        cn->next=nn;
    }
}

void sll::display()
{
    node *cn;
    cn=header;
    cout<<"Linked list is:\n";
    while(cn!=NULL)
    {
        cout<<cn->data<<"\t";
        cn=cn->next;
    }
}
void sll::delet_beg()
{
    node *cn;
    cn=header;
    header=cn->next;
    delete cn;
}
void sll::delet_end()
{
    node *cn,*temp;
    cn=header;
    while(cn->next!=NULL)
    {
        temp=cn;
        cn=cn->next;
    }
    temp->next=NULL;
    delete cn;
}
void sll::delet_pos()
{
     int p,count=0;
     cout<<"Enter the position to delete data: ";
     cin>>p;
     node *cn;
     cn=header;
     while(cn!=NULL)            //counter
     {
        count++;
        cn=cn->next;
     }
     if(p==1)
     {
        delet_beg();
     }
     else if(p==count)
     {
        delet_end();
     }
     else if(p>count)
     {
        cout<<"Invalid position\n";
     }
     else{
            node *cn,*temp;
            cn=header;
            for(int i=1 ; i<p ; i++)
            {   
                temp=cn;
                cn=cn->next;
            }
            temp->next=cn->next;
            delete cn;
     }
}

void sll::search()
{   
    int data;
    cout<<"Enter the data u want to search: ";
    cin>>data;
    node *temp;
    temp=header;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            cout<<"Data found!\n";
            return;
        }
        temp=temp->next;
    }
    cout<<"Data not found!\n";
}
void sll::reverse(node *cn)
{
    if(cn->next!=NULL)
    {
        reverse(cn->next);
    }
    cout<<cn->data<<endl;
}


int main()
{
    sll s;   
    int ch; 
    cout<<"||   Single linked list  ||\n";
    while(1){
    cout<<"\n1.Display\t2.Insert end\t3.Delete end\t4.Insert beg\t5.Delete beg\t6.Insert position\t7.Delete position\t8.Search\t9.Reverse\t10.Quit\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        s.display();
        break;

        case 2:
        s.insert_end();
        break;

        case 3:
        s.delet_end();
        break;

        case 4:
        s.insert_beg();
        break;
        
        case 5:
        s.delet_beg();
        break;

        case 6:
        s.insert_pos();
        break;

        case 7:
        s.delet_pos();
        break;

        case 8:
        s.search();
        break;
        
         case 9:
         s.reverse(s.header);
         break;

         case 10:
         return 0;
    }
    }
}




