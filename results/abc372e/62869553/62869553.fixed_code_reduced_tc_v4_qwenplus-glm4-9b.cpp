#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 200005;
vector<int> parent(MAX_N), size(MAX_N), vertices(MAX_N);
priority_queue<int> pq[MAX_N];

void findSet(int x) {
    if (parent[x] != x) {
        parent[x] = findSet(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    x = findSet(x);
    y = findSet(y);
    if (x != y) {
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        // Merging the priority queues
        while (!pq[y].empty()) {
            pq[x].push(pq[y].top());
            pq[y].pop();
        }
    }
}

int solveKthLargest(int v, int k) {
    v = findSet(v);
    if (size[v] < k) {
        return -1;
    }
    while (k--) {
        if (!pq[v].empty()) {
            pq[v].pop();
        }
    }
    if (!pq[v].empty()) {
        return pq[v].top();
    }
    return -1;
}

int main() {
    int N, Q, u, v, k;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        size[i] = 1;
        vertices[i] = i;
    }

    for (int i = 0; i < Q; i++) {
        cin >> u >> v;
        if (u == 1) {
            unionSets(u, v);
        } else {
            cin >> k;
            cout << solveKthLargest(v, k) << endl;
        }
    }

    return 0;
}