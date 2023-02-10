//Write a C++ program to find the minimum spanning tree of a given undirected graph.
//murtuza kapasi

#include<iostream>
using namespace std;
class MST{
  public:
  int adjmatrix[10][10],cost[10][10],spantree[10][10];
  int source[10],visited[10],dist[10],n,e,edges,l,v1,v2,mincost=0;
  MST()
  {
    for (int i=0 ; i<10 ; i++)
    {
      for(int j=0 ; j<10 ; j++)
      {
        cost[i][j]=0;
        adjmatrix[i][j]=0;
     spantree[i][j]=0;

      }
      visited[i]=0;
      source[i]=0;
      dist[i]=0;
    }
  }

  void create();
  void min_spantree();
};

void MST::create()
{
  cout<<"Enter number of vertices: ";
  cin>>n;
  cout<<"Enter number of edged: ";
  cin>>e;
  //Adjacency matrix is created
  for(int i=0 ; i<e ; i++)
  {
    cout<<"Enter source: ";
    cin>>v1;
    cout<<"Enter destination: ";
    cin>>v2;
    cout<<"Enter length: ";
    cin>>l;

    adjmatrix[v1][v2]=adjmatrix[v2][v1]=l;
  }
}

void MST::min_spantree()
{
  int mindist,minCost_index;
  //Create cost matrix
  for (int i=0 ; i<10 ; i++)
    {
      for(int j=0 ; j<10 ; j++)
      { 
        if(adjmatrix[i][j]==0)
          cost[i][j]=99;
        else
          cost[i][j]=adjmatrix[i][j];
      }
    }

    //start from vertex 0
    visited[0]=1;
    //distance and source for vertex 0 is updated in dist[]
    for(int i=0 ; i<n ; i++)
      {
        dist[i]=cost[0][i];
        source[i]=0;
      }

    edges=n-1;

    while(edges>0)
    {
      mindist=99;
    //to find min among dist[] and store its index 
      for(int i=0 ; i<n ; i++)
      {
        if(visited[i]==0 && dist[i]<mindist)
        {
          mindist=dist[i];
          minCost_index=i;
        }  
      }

    v1=source[minCost_index];
    spantree[v1][minCost_index]=spantree[minCost_index][v1]=dist[minCost_index];
    visited[minCost_index]=1;

    edges--;
    for(int i=1 ; i<n ; i++)
    {
      if(visited[i]==0 && cost[minCost_index][i]<dist[i])
      {
        dist[i]=cost[minCost_index][i];
        source[i]=minCost_index;
      }
    }

    mincost=mincost+cost[v1][minCost_index];

    }


}

int main()
{
  MST t;
  t.create();
  cout<<"\nMinimun spannig tree is\n";
    t.min_spantree();
  for (int i=0 ; i<t.n ; i++)
    {
      for(int j=0 ; j<t.n ; j++)
      { 
       cout<<t.spantree[i][j]<<" ";
      }
      cout<<endl;
    }
    return 0;
}
