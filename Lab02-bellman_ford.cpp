// Here's bellman ford algorithm from scratch
#include<bits/stdc++.h>
typedef long long ll;
#define forr(i, j, k) for(ll i = j; i < k; i++)
using namespace std;
void bellman_ford(vector<vector<int>>&edges,int v,int s)
{
    vector<int> dist(v,1e9);
    dist[s]=0;
    forr(i,0,v-1){
        for(auto it:edges){
            int u= it[0];
            int v= it[1];
            int w= it[2];
            if(dist[u]!=1e9 && dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
            }
        }
    }
    forr(i,0,v) cout<<dist[i]<<" ";
}
int main()
{
    int E,V; cin>>E>>V;
    vector<vector<int>> G;
    forr(i,0,E){
        int u,v,w; cin>>u>>v>>w;
        G.push_back({u,v,w});
    }
    bellman_ford(G,V,0);
    return 0;
}
