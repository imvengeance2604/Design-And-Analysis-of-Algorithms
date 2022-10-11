#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int vis[1000]={0};


int main() {int n,e;
    cin>>n>>e;
    vector<pair<int,int>> v[n];
    for(int i=0;i<e;i++)
        {int s,e,w;
            cin>>s>>e>>w;
            v[s].push_back({w,e});
            v[e].push_back({w,s});}
            int ne=1;
           
            vis[0]=1;
            int mc=0;
     while(ne<n)
     {int min=9999,v1;
        pair<int,int> x;
        for(int i=0;i<n;i++)
        {if(vis[i]==1)
            {for(pair<int,int> p:v[i])
                {if(vis[p.second]==0&&p.first<min)
                    {min=p.first;
                        x=p;
                        v1=i;}
                }
            }
        }

     
     int m1=x.first;
     int n1=x.second;
     vis[n1]=1;
     cout<<v1<<" "<<n1<<" "<<m1<<"\n";
     ne++;
     mc+=m1;
     pair<int,int> r={m1,v1};
     remove(v[v1].begin(),v[v1].end(),x);
     remove(v[n1].begin(),v[n1].end(),r);

    }       
cout<<mc;
return 0;

    
    
    }
