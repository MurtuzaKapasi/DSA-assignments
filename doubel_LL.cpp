//Write a C++ program to implement a doubly linked list and perform operations such as insert, delete, display and search element from it.
//murtuza kapasi
#include <iostream>
using namespace std;
struct node {
  int data;
  node *prev;
  node *next;
};
class student {
  node *nn;

public:
  node *header;
  student() { header = NULL; }

  void display();
  void insert_end();
  void insert_beg();
  void insert_pos();
  void delet_beg();
  void delet_end();
  void delet_pos();
  void search();
};

void student::insert_end() {
  nn = new node;
  cout << "Enter data: ";
  cin >> nn->data;
  if (header == NULL) {
    header = nn;
    nn->prev = NULL;
    nn->next = NULL;
  } else {
    node *cn;
    cn = header;
    while (cn->next != NULL) {
      cn = cn->next;
    }
    cn->next = nn;
    nn->prev = cn;
    nn->next = NULL;
  }
}
void student::insert_beg() {
  nn = new node;
  cout << "Enter data: ";
  cin >> nn->data;
  nn->prev = NULL;

  if (header == NULL) {
    header = nn;
    nn->prev = NULL;
    nn->next = NULL;
  } else {
    nn->next = header;
    header->prev = nn;
    header = nn;
  }
}
void student::insert_pos(){   int n,count=0;
    node *cn;
    cn=header;
    cout<<"Enter the position: ";
    cin>>n;
    while(cn!=NULL)
        {
            count++;
            cn=cn->next;
        }
    if(n==1)
    {
        insert_beg();
    }
     else if(n==count+1)
    {
        insert_end();
    }
    else if(n>count+1){
        cout<<" Invalid position\n";
    }
    else{
        nn=new node;
        cn=header;
        node*temp;
        for(int i=1 ; i<n ; i++)
            {
                cn=cn->next;
                temp=cn;
            }
        nn->next=temp->next;
        temp->next=nn;
        nn->prev=temp;
        cn->prev=nn;
        }
}
void student::display() {
  node *cn;
  cn = header;
  while (cn != NULL) {
    cout << cn->data << endl;
    cn = cn->next;
  }
}
void student::delet_beg() {
  node *cn;
  cn = header;
  cn=header;
  header=header->next;
  header->next->prev=NULL;
 delete cn;
 cout<<"Deleted successfully!\n";
}
void student::delet_end(){
    node *cn,*temp;
    cn=header;
    while(cn->next!=NULL)
        {
            temp=cn;
            cn=cn->next;
        }
    temp->next=NULL;
    delete cn;
    cout<<"Deleted successfully!\n";

    
}
void student::delet_pos(){
    int n,count=0;
     node *cn;
    cn=header;
    cout<<"Enter the position: ";
    cin>>n;
    while(cn!=NULL)
        {
            count++;
            cn=cn->next;
        }
    if(n==1)
    {
        delet_beg();
    }
     else if(n==count)
    {
        delet_end();
    }
    else if(n>count){
        cout<<" Invalid position\n";
    }
    else{
        nn=new node;
        cn=header;
        node*temp;
        for(int i=1 ; i<n ; i++)
            {
                cn=cn->next;
                temp=cn;
            }
        nn->next=temp->next;
        temp->next=nn;
        nn->prev=temp;
        cn->prev=nn;
         cout<<"Deleted successfully!\n";
        }

}
void student::search()
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

int main() {
  int h;
  student s;
  cout << "||    LINKED LIST   ||" << endl;
  while (1) {
    cout << "|  MENU |" << endl;

    cout << "1.display data\n2.Insert end \n3.Insert "
            "beg.\n4.Insert  position\n5.Delete beg\n6.Delete end\n7.Delete pos\n8.Search\n9.Quit\n";
    cout<<"Enter your choice: ";
    cin >> h;
    switch (h) {
    case 1:
         s.display();
          break;
    case 2:
         s.insert_end();
         break;
    case 3:
        s.insert_beg();
        break;
    case 4:
        s.insert_pos();
        break;
    case 5:
         s.delet_beg();
         break;
    case 6:
        s.delet_end();
        break;
    case 7:
        s.delet_pos();
        break;
    case 8:
         s.search();
         break;
    case 9:
        return 0;
    }
  }
}