#include <bits/stdc++.h>
using namespace std;

class minHeap {
    vector<pair<int, int>> heap;
    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return (2 * index) + 1; }
    int rightChild(int index) { return (2 * index) + 2; }

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)].first > heap[index].first) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int len = heap.size();
        while (true) {
            int left_child = leftChild(index);
            int right_child = rightChild(index);
            int smallest = index;

            if (left_child < len && heap[left_child].first < heap[smallest].first) {
                smallest = left_child;
            }
            if (right_child < len && heap[right_child].first < heap[smallest].first) {
                smallest = right_child;
            }
            if (smallest != index) {
                swap(heap[smallest], heap[index]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insertion(pair<int, int> p) {
        heap.push_back(p);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    pair<int, int> extract_min() {
        if (heap.empty()) return { -1, -1 };
        pair<int, int> min_value = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return min_value;
    }

    void decreaseKey(int key, int newKey) {
        int len = heap.size();
        for (int i = 0; i < len; i++) {
            if (heap[i].first == key) {
                heap[i].first = newKey;
                heapifyUp(i);
                break;
            }
        }
    }

    bool isEmpty() {
        return heap.empty();
    }
};

void dijkstra(int V, int E, vector<int>& dist, vector<vector<pair<int, int>>>& graph, int s) {
    dist[s] = 0;
    minHeap heap;
    heap.insertion({ 0, s });
    while (!heap.isEmpty()) {
        pair<int, int> top = heap.extract_min();
        int dis = top.first;
        int node = top.second;
        for (auto it : graph[node]) {
            int adjNode = it.first;
            int weight = it.second;
            if ((dis + weight) < dist[adjNode]) {
                dist[adjNode] = dis + weight;
                heap.insertion({ dist[adjNode], adjNode });
            }
        }
    }
}

int main() {
    int V, E; cin >> V >> E;
    vector<int> dist(V, 1e9);
    vector<vector<pair<int, int>>> graph(V);
    for (int i = 0; i < E; i++) {
        int v, e, w; cin >> v >> e >> w;
        graph[v].push_back({ e, w });
        graph[e].push_back({ v, w });
    }
    dijkstra(V, E, dist, graph, 0);
    for (int i = 0; i < V; i++) {
        cout << "vertex "<<i<<": Distance "<<dist[i]<<endl;
    }
    return 0;
}
