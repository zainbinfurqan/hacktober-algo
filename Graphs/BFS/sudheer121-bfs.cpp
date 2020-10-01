// Breadth First Search on graph using adjacency list in C++
#include <iostream>
#include<vector>
#include<queue> 

using namespace std;
const int maxn = 1e5 + 10; 

vector<int> graph[maxn]; 

int breadth_first_search(int src,int n,int m,vector<int> &bfs) //source vertex 
{
    
    vector<int> vis(n+1,0); 
    queue<int> processed;  // vertices are processed and put in a queue, while all their children are pushed in queue
    
    vis[src] = 1; 
    bfs.push_back(src); 
    processed.push(src);
    
    while(!processed.empty())
    {
        int v = processed.front();
        processed.pop();
        for(int child:graph[v])
        {
            if(!vis[child])
            {
                vis[child] = 1;
                bfs.push_back(src);
                processed.push(child);
                
            }
        }
    }
    
}

int print_bfs(int src,int n,int m)
{
    vector<int> bfs;
    breadth_first_search(src,n,m,bfs);
    
    cout<<"Breadth first search traversal is :\n"; 
    for(int vertex:bfs)
    {
        cout<<vertex<<" "; 
    }
}
int initialize(int n)
{
    for(int i=0;i<=n;i++)
    {
        graph[i].clear(); 
    }
}
int main()
{
    int i,j;
    
    int n,m; // n -> total nodes , m -> total edges
    cout<<"Enter total number of nodes and edges \n";
    
    cin>>n>>m;
    cout<<"Enter the edges, each represented by a pair of vertices \n"; 
    
    initialize(n);
    
    for(i=1; i<=m; i++)
    {   
        int x,y; 
        cin>>x>>y;
        
        // undirected edge 
        graph[x].push_back(y);
        graph[y].push_back(x); 
        
    }
    
    cout<<"Enter the vertex, you want to print bfs from \n"; 
    cin>>j;
    print_bfs(j,n,m); 
    return 0;
}
