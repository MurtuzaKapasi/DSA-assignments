//Write a C++ program to implement a threaded binary tree and its traversal.
//murtuza kapasi

#include<iostream>
using namespace std;

struct node{
int data;
node *left,*right;
int l,r;
};

class TBT{
    node *nn,*root,*dummy;
public:

TBT()
{
    dummy->data=99;
    dummy->left=dummy->right=NULL;
    dummy->l=dummy->r=0;
    root=NULL;
}
void create();
void inorder();
int preorder();
};

void TBT::create()
{
    nn=new node;
    cout<<"Enter data: ";
    cin>>nn->data;
    nn->l=nn->r=0;
    if(root==NULL)
    {
        root=nn;
        nn->left=nn->right=dummy;
        dummy->l=1;
        dummy->left=nn;
    }
    else
    {
        node *temp,*parent;
        temp=root;
        while(temp!=NULL)
            {
                parent=temp;
                if(nn->data<temp->data)
                {
                    if(temp->l==0)
                        temp=NULL;
                    else
                        temp=temp->left;
                }
                else
                {
                    if(temp->r==0)
                        temp=NULL;
                    else
                        temp=temp->right;
                }
            }

        if(nn->data<parent->data)
        {
            nn->left=parent->left;
            nn->right=parent;
            parent->left=nn;
            parent->l=1;
        }
        else
        {
            nn->right=parent->right;
            nn->left=parent;
            parent->right=nn;
            parent->r=1;
        }
    }
}

void TBT::inorder()
{
    node *temp;
    temp=root;
    while(temp->l==1)
        {
            temp=temp->left;
        }
    // cout<<temp->data;
    while(temp!=dummy)
        {
            cout<<temp->data<<" ";
            temp=temp->right;
        }
}

int TBT::preorder()
{
    node *cn,*temp;
    temp=root;
    while(1)
        {
            while(temp->l==1)
                {
                    cout<<temp->data<<" ";
                    temp=temp->left;
                }
                cout<<temp->data;
            while(temp->r==0)
                {
                    if(temp->right==dummy)
                    {   return 0;   }
                    
                    else
                    temp=temp->right;
                }
                temp=temp->right;
        }
}

int main()
{    
    TBT t;
    int ch;
    cout<<"     Threaded binary tree   \n";
    while(1){
    cout<<"\n1.Insert data    2.Inorder display    3.Preorder display\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
        {
            case 1:
                t.create();
                break;
            case 2:
                t.inorder();
                break;
            case 3:
                t.preorder();
                break;
            default:
                return 0;            
        }
        }
8}
