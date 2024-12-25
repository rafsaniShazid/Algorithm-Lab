#include <bits/stdc++.h>
typedef long long ll;
#define forr(i, j, k) for (ll i = j; i < k; i++)
using namespace std;
const int N = 1e5 + 10;
vector<int> size(N, 0);
vector<int> parent(N, 0);

void make(int i) {
    parent[i] = i;
    size[i] = 1;
}

int find(int i) {
    if (i == parent[i]) return i;
    return parent[i] = find(parent[i]);
}

void Union(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a != b) {
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main() {
    int n, k;
    cin >> n >> k; // Read number of nodes and edges
    forr(i, 0, n) {
        make(i); // Initialize all nodes
    }

    // Use a for loop to ensure all edges are read
    forr(i, 0, k) {
        int a, b;
        cin >> a >> b; // Read an edge
        Union(a, b);
    }

    int connected_comp = 0;
    forr(i, 0, n) {
        if (find(i) == i) connected_comp++; // Count connected components
    }
    cout << connected_comp << endl;

    return 0;
}
