#include <bits/stdc++.h>
using namespace std;
void dfs(vector <int> adj[],int v,bool vis[])
{vis[v]=true;
    cout<<v;
for(int u:adj[v])
{if(vis[u]==false)
{dfs(adj,u,vis);}}}
int main() 
{int e,n;
cin>>n;
    vector<int> adj[n];
    bool vis[n];

    
    for(int i=0;i<n;i++)
    {vis[i]=false;}
    cin>>e;
    for(int i=0;i<e;i++)
        {int m,x;
            cin>>m>>x;
            adj[m].push_back(x);
            adj[x].push_back(m);}
for(int i=0;i<n;i++)
    {if(vis[i]==false)
        {dfs(adj,i,vis);}}
            
}
