// Minimum spanning tree using DSU(union by size)
#include <bits/stdc++.h>
typedef long long ll;
#define forr(i, j, k) for (ll i = j; i < k; i++)
using namespace std;
const int N = 1e5 + 10;
vector<int> sizes(N, 0);
vector<int> parent(N, 0);

void make(int i) {
    parent[i] = i;
    sizes[i] = 1;
}

int find(int i) {
    if (i == parent[i]) return i;
    return parent[i] = find(parent[i]);
}

void Union(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a != b) {
        if (sizes[a] < sizes[b]) swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}

int main() {
    //Enter number of vertex and edges
    int V,E;
    cin>>V>>E;
    vector<pair<int,pair<int,int>>> graph;
    forr(i,1,E+1) make(i);
    forr(i,1,E+1){
        int w,u,v;
        // Enter weight and two vertices of each edge
        cin>>w>>u>>v;
        graph.push_back({w,{u,v}});
    }
    sort(graph.begin(),graph.end());
    int cost=0;
    for(auto it:graph)
    {
        int w= it.first;
        int u= it.second.first;
        int v= it.second.second;
        if(find(u)==find(v)) continue;
        Union(u,v);
        cost+=w;
        cout<< u<<" "<<v<<endl;
    }
    cout<<"Total cost: "<<cost<<endl;
}
/*
6 9
4 1 5
9 4 5
1 1 4
2 1 2
3 2 4
3 2 3
5 3 4
7 2 6
8 3 6
*/
