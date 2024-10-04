#include<bits/stdc++.h>
typedef long long ll;
#define forr(i, j, k) for(ll i = j; i < k; i++)
using namespace std;

class DisjointSetUnion{
    vector<int>rank,parent;
public:
    DisjointSetUnion(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        forr(i,0,n+1)
            parent[i]=i;
    }
    int findParent(int u){
        if(parent[u]==u) return u;
        return findParent(parent[u]);
    }
    void unionByRank(int m,int n){
        int up_m= findParent(m);
        int up_n= findParent(n);
        if(up_m==up_n) return;
        if(rank[up_m]<rank[up_n]) parent[up_m]=up_n;
        else if(rank[up_m]>rank[up_n]) parent[up_n]=up_m;
        else{
            parent[up_n]=up_m;
            rank[up_m]++;
        }
    }
};
int main(){
    //enter vertices v and edges e;
    int v,e; cin>>v>>e;
    DisjointSetUnion ds(v);
    // Enter the edges
    forr(i,0,e){
        int u,v; cin>>u>>v;
        ds.unionByRank(u,v);
    }
    // Enter the  query q
    cout<<"Enter the  query q\n";
    int q; cin>>q;
    while(q--){
    cout<<"Enter the value m and n you wanna check\n";
    int m,n; cin>>m>>n;
    if(ds.findParent(m)==ds.findParent(n)) cout<<"same\n";
    else cout<<"different\n";
    }
    /* sample input
    7 5

    1 2
    1 3
    4 3
    6 5
    7 5
    2
    1 2
    1 5

    sample output
    same
    different
    */
    return 0;
}
