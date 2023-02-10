//Write a C++ program to perform the following operations on a height balanced tree: 
//i) Insert a node ii) Search a node iii) Display it in ascending order.
//murtuza kapasi

#include<iostream>
using namespace std;

struct node{
    int data;
    node * left,*right;
};

class AVL{
 public:
 node *root;
 AVL()
 {
    root=NULL;
 }
    void create();
    node * insert(node *,int );
    void display();
    void inorder_display(node *);
    void preorder_display(node *);
    node * LL(node *);
    node * RR(node *);
    node * LR(node *);
    node * RL(node *);
    int height(node *);
    int max(int,int);
    void search();
};

node * AVL::insert(node *temp,int data)
{  
    if(temp==NULL)
    {
        temp=new node;
        temp->data=data;
        temp->left=temp->right=NULL;
    }

    else{
       if(data<temp->data)
        {
            temp->left=insert(temp->left,data);
            if(height(temp->left)-height(temp->right)==2)
            {
                if(data<temp->left->data)
                    temp=LL(temp);
                else
                    temp=LR(temp);
            }
        }

        else{
            temp->right=insert(temp->right,data);
            if(height(temp->left)-height(temp->right)==-2)
            {
                if(data>temp->right->data)
                    temp=RR(temp);
                else
                    temp=RL(temp);
            }
        }
    }
    return temp;
}

void AVL::create()
{
    int data;
    char ch;
    do{
        cout<<"Enter data: ";
        cin>>data;
        root=insert(root,data);
        cout<<"Continue? ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
}
void AVL::display()
{
              cout<<"\n inorder"<<endl;
              inorder_display(root);

              cout<<"\n Preorder"<<endl;;
              preorder_display(root);
}
void AVL::inorder_display(node *temp)
{
    if(temp!=NULL)
    {
        inorder_display(temp->left);
        cout<<temp->data<<" ";
        inorder_display(temp->right);
    }
}
void AVL::preorder_display(node *temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data<<" ";
        preorder_display(temp->left);
        preorder_display(temp->right);
    }
}

int AVL::height(node *temp)
{   
    if(temp==NULL) 
        return -1;
    if(temp->left==NULL && temp->right==NULL)
        return 0;
    else
      return(1 + max(height(temp->left),(height(temp->right))));
}
int AVL::max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

//Rotations
node *AVL::LL(node *parent)
{
    node *temp;
    temp=parent->left;
    parent->left=temp->right;
    temp->right=parent;
    return temp;
}
node *AVL::RR(node *parent){

  node *temp;
  temp=parent->right;
  parent->right=temp->left;
  temp->left=parent;
  return temp;
}
node *AVL::LR(node *parent)
{
    parent->left=RR(parent->left);
    parent=LL(parent);
    return parent;
}
node *AVL::RL(node *parent)
{
    parent->right=LL(parent->right);
    parent=RR(parent);
    return parent;
}

void AVL::search()
{   int val;
    cout<<"Enter the value: ";
    cin>>val;
    node *temp;
    temp=root;
    while(temp!=NULL)
    {
        if(val==temp->data){
            cout<<"Data found";
            break;
        }
        else if(val<temp->data)
            temp=temp->left;
        else
            temp=temp->right;            
    }
    if(temp==NULL)
        cout<<"Data  not found!\n";
    
}

int main()
{   int ch;
    AVL A;
    while(1){
    cout<<"\n1.Insert 2.Display   3.Search\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1:
            A.create();
            break;
        case 2:
            A.display();
            break;
        case 3:
            A.search();
            break;
        default:
            return 0;
         
    }
    }
}
