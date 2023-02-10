//Write a C++ program to construct a binary search tree and perform insertion, deletion, searching of a node and its traversal.
//murtuza kapasi

#include <iostream>
using namespace std;

struct node{
int data;
node *left;
node *right;
};

class tree{
node *nn;
public:
node *root;
tree()
{
    root=NULL;
}

void insert();
void rec_display(node *root);
void rec_inorder(node *cn);
void rec_preorder(node *cn);
void rec_postorder(node *cn);

void non_rec_display(node *root);
void non_rec_inorder(node *temp);
void non_rec_preorder(node *temp);
void non_rec_postorder(node *temp);

node *search(int data);
node *delet(int data);
int countNode(node *temp);
int countLeafNode(node *temp);
int height(node *temp);


};

class stack{
public:
int top;
node *arr[20];
stack()
{
    top=-1;
}
void push(node* data);
node *pop();
};
void stack::push(node *data){
    top++;
    arr[top]=data;
}
node *stack::pop(){
    node *temp;
    temp=arr[top];
    top--;
    return temp;
}

void tree::insert(){
    nn=new node;
    cout<<"Enter data: ";
    cin>>nn->data;
    if(root==NULL)
    {
        root=nn;
    }
    else{
        node *temp,*cn;
        temp=root;
        while(temp!=NULL)
        {    
            cn=temp;
            if((temp->data)>(nn->data))
            {
                temp=temp->left;            
            }
            else{
                temp=temp->right;
            }
        }
        if((cn->data)>(nn->data))
             cn->left=nn;
        else    
            cn->right=nn;
    }
}

//Display Functions
void tree::rec_display(node *root){    
    int ch;
    cout<<"\n1.Inorder    2.Pre order   3.post order    ";
    cin>>ch;
    switch(ch)
        {
            case 1:
                rec_inorder(root);
                break;
            case 2:
                rec_preorder(root);
                break;
            case 3:
                rec_postorder(root);
                break;
            
        }
}
void tree::non_rec_display(node *root){
    int ch;
    cout<<"\n1.Inorder    2.Preorder    3.Postorder    ";
    cin>>ch;
    switch(ch)
        {
            case 1:
                non_rec_inorder(root);
                break;
            case 2:
                non_rec_preorder(root);
                break;
            case 3:
                non_rec_postorder(root);
                break;
        }
    }

//Recursive Functions
void tree::rec_inorder(node *root){
    if(root!=NULL)
        {
            rec_inorder(root->left);
            cout<<root->data<<" ";
            rec_inorder(root->right);
        }
}
void tree::rec_preorder(node *cn){
    if(cn!=NULL)
    {
        cout<<cn->data<<" ";
        rec_preorder(cn->left);
        rec_preorder(cn->right);
    }
}
void tree::rec_postorder(node *cn){
    if(cn!=NULL)
    {
        rec_postorder(cn->left);
        rec_postorder(cn->right);
        cout<<cn->data<<" ";
    }
}

//Non Recursive Functions
void tree::non_rec_inorder(node *temp){
    stack s;
    while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
    while(s.top!=-1)
        {
            temp=s.pop();
            cout<<temp->data<<" ";
            temp=temp->right;
            while(temp!=NULL)
            {
                s.push(temp);
                temp=temp->left;
            }
        }
}
void tree::non_rec_preorder(node *temp){
    stack s;
    while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            s.push(temp);
            temp=temp->left;
        }
        while(s.top!=-1)
            {   
                temp=s.pop();
                temp=temp->right;
                while(temp!=NULL)
                    {
                        cout<<temp->data<<" ";
                        s.push(temp);
                        temp=temp->left;
                    }
            }
        }
void tree::non_rec_postorder(node *temp){
    stack s1,s2;
    temp=root;
    s1.push(temp);
    while(s1.top!=-1)
        {
            temp=s1.pop();
            if(temp->left!=NULL)
            {    s1.push(temp->left);    }
            if(temp->right!=NULL)
            {    s1.push(temp->right);    }

            s2.push(temp);
        }
    while(s2.top!=-1)
        {
            temp=s2.pop();
            cout<<temp->data<<" ";
        }
}

node *tree::search(int data){
    node *cn,*parent;
    cn=root;
    parent=root;
    while(cn!=NULL)
        {  
            if(cn->data==data)
            {
                break;
            }
            else if(cn->data<data)
            {
                parent=cn;
                cn=cn->right;
            }
            else if(cn->data>data)
            {
                parent=cn;
                cn=cn->left;
            }
        }
        if(cn==NULL){
    cout<<"Data not found!";
    return NULL;
        }
    else{
        cout<<"Data found!";
        return parent;
    }
}

node *tree::delet(int data){
    node *cn,*parent,*temp;
    parent=search(data);
    cn=parent;
    
    if(parent->data<data)
        cn=cn->right;
    else    
        cn=cn->left;


    // cout<<"parents data : "<<parent->data;
    // cout<<"\ncn data: "<<cn->data;
        
        //For Leaf node
        if(cn->left==NULL && cn->right==NULL)
        {   
        cout<<"Leaf node is deleted\n";
        if(cn==root)
        {
            root=NULL;
            return root;
        }
            if(cn->data>parent->data)
            {
                parent->right=NULL;
            }
            else
                parent->left=NULL;

                delete cn;
        }
        
        //For node with left child
        else if(cn->left!=NULL && cn->right==NULL)
        {   
            cout<<"Node with left child is deleted\n";
            if(cn==root)
            {
                root=cn->left;
                return root;

                // delete cn;
            }
            if(cn->left->data>parent->data)
            {
                    parent->right=cn->left;
            }
            else 
                parent->left=cn->left;

            delete cn;
        }

        //For leaf with right child
        else if(cn->left==NULL && cn->right!=NULL)
       {
            cout<<"Node with right child is deleted\n";
            if(cn==root)
            {
                root=cn->right;
                return root;
                // delete cn;
            }
            if(cn->right->data>parent->data)
            {
                parent->right=cn->right;
            }
            else
                parent->left=cn->right;

                delete cn;
       }

       //Node with 2 childs
       else if(cn->left!=NULL && cn->right!=NULL)
       {    temp=cn->left;
            while(temp->right!=NULL)
                temp=temp->right;

            int value;
            value=temp->data;
            delet(value);
            cn->data=value;
       }
       return root;
}

int tree::countNode(node *temp){
    if(temp==NULL)
        return 0;
    else
        return (1+countNode(temp->right)+countNode(temp->left));
}

int tree::countLeafNode(node *temp){
    if(temp==NULL)
        return 0;
    else if((temp->right==NULL) && (temp->left==NULL))
        return 1;
    else;
        return (countLeafNode(temp->right)+countLeafNode(temp->left));
}

int tree::height(node *temp)
{   
    int heightL,heightR;
    if(temp==NULL)
        return 0;
    if(temp->left==NULL && temp->right==NULL)
        return 0;
    
    heightL=height(temp->left);
    heightR=height(temp->right);
    
    if(heightR<heightL)
        return (heightL+1);
    return (heightR+1);
    

}


int main()
{    
    int ch;
    tree t;
    stack s;
    int data=0;
  
    
    cout<<"||   TREE  ||\n";
       while(1){
    cout<<"\n1.Insert   2.Display(recursive)  3.Display(Non rec)   4.Search     5.Delete node   6.count node";
        cout<<"\nEnter your choice: ";
    cin>>ch;
    switch(ch)
        {
            case 1:
                t.insert();
                break;
            case 2:
                t.rec_display(t.root);
                break;
            case 3:
                t.non_rec_display(t.root);
                break;
            case 4:
                cout<<"Enter data u want to search: ";
                cin>>data;
                t.search(data);
                break;
            case 5:
                cout<<"Enter data u want to delete: ";
                cin>>data;
                t.delet(data);
                break;
            case 6:
                cout<<"Total number of noder are: ";
                cout<<t.countNode(t.root);
                break;
            case 7:
                cout<<"number of leaf nodes are: ";
                cout<<t.countLeafNode(t.root);
                break;
            case 8:
                cout<<"Height of tree is: "; 
                cout<<t.height(t.root);
                break;
            default:
                cout<<"Program terminated!";
                return 0;
        }
    }
}
