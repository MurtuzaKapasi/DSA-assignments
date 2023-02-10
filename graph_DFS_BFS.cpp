//Write a C++ program for the implementation of BFS and DFS for a given graph.
//murtuza kapasi

#include<iostream>
#include<queue>
using namespace std;

class graph
{
    public:
    int n,s,no,d;
    int mat[10][10];
    int visited[10],visited2[10];
    graph()
    {
        cout<<"Enter number of nodes u want: ";
        cin>>no;
        n=no;
         mat[n][n];
        visited[n];
        visited2[n];
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                mat[i][j]=0;
            }
        }
        
        for(int i=0 ; i<n ; i++){
            visited[i]=0;   
            visited2[i]=0; }
        
    }
   
    void BFS(int);
    void display_matrix();
    void DFS(int);
    inline void insert();
    void insert_edge(int,int);
};

void graph::insert()
{
    cout<<"Enter source and destination: ";
    cin>>s>>d;
    insert_edge(s,d);

}
void graph::insert_edge(int v1,int v2)
{   
    mat[v1][v2]=1;
    mat[v2][v1]=1;
}
void graph::display_matrix()
{
    for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
}
void graph::DFS(int v1)
{   
    int v2=0;
    cout<<v1<<" ";
    visited[v1]=1;
    for( v2=0 ; v2<n ; v2++)
    {   
        if(mat[v1][v2]==1 && visited[v2]==0)
        {
            DFS(v2);
        }
    }
}

void graph::BFS(int v1)
{  
  queue<int> q;
  q.push(v1);
  visited2[v1]=1;
  while(!q.empty())
    {
      v1=q.front();
        q.pop();
      cout<<v1<<" ";
      for(int v2=0;v2<n;v2++)
        {
           
          if(mat[v1][v2]==1 && visited2[v2]==0)
          {
            q.push(v2);
            visited2[v2]=1;
          }
        
        }
     }  
}
int main()
{   
    graph g;
    int ch,d=0;
    while(1){
    cout<<"\n1.insert edge    2.display   3.Display elements(DFS)   4.Display elements(BFS)\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        g.insert();
        break;
        
        case 2:
        cout<<" Matrix representation is\n";
        g.display_matrix();
        break;
        case 3:
        g.DFS(d);
        break;
        case 4:
        g.BFS(d);
        break;

        default:
        return 0;
    }
    }
}
