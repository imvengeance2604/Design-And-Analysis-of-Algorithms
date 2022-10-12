#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int INF=1e9+10;
vector<pair<int,int>>g[N];
void dijkstra(int source)
{vector<int> vis(N,0);
    vector<int> dist(N,INF);
    set<pair<int,int>>st;
    st.insert({0,source});
    dist[source]=0;
    while(st.size()>0)
    {auto node=*st.begin();
        int v=node.second;
        int vdist=node.first;
        st.erase(st.begin());
        if(vis[v]) 
            {continue;}
        vis[v]=1;
        for(auto child:g[v])
        {int wt=child.first;
            int child_v=child.second;
            if(dist[v]+wt<dist[child_v])
            {dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }
    for(int i=0;i<9;i++)
    {cout<<dist[i]<<"\n";}
    
}
int main()
{int n,e;
    cin>>n>>e;
    
    for(int i=0;i<e;i++)
        {int s,e,w;
            cin>>s>>e>>w;
            g[s].push_back({w,e});}
            
            dijkstra(0);}
