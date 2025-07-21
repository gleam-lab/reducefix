#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define MAXK 10

int parent[MAXN], rank[MAXN], size[MAXN], heap[MAXK * MAXN], heap_size[MAXN];
int n, q;

// Find the root of the set containing x
int findRoot(int x) {
    if (parent[x] != x) parent[x] = findRoot(parent[x]);
    return parent[x];
}

// Union the sets containing x and y
void unionSets(int x, int y) {
    int root_x = findRoot(x);
    int root_y = findRoot(y);
    if (root_x != root_y) {
        if (rank[root_x] > rank[root_y]) {
            parent[root_y] = root_x;
            size[root_x] += size[root_y];
        } else if (rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
            size[root_y] += size[root_x];
        } else {
            parent[root_y] = root_x;
            size[root_x] += size[root_y];
            rank[root_x]++;
        }
    }
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
        size[i] = 1;
    }

    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            unionSets(u, v);
        } else if (op == 2) {
            int root_v = findRoot(v);
            if (size[root_v] < k) cout << -1 << endl;
            else {
                // Build the heap of sizes for the component of v
                for (int i = 1; i <= n; i++) {
                    if (findRoot(i) == root_v) {
                        heap[++heap_size[root_v]] = i;
                    }
                }
                // Convert the heap to a max heap
                for (int i = (heap_size[root_v] + 1) / 2; i >= 1; i--) {
                    heapify(heap_size[root_v], i);
                }
                // Find the k-th largest vertex
                int count = 0;
                for (int i = heap_size[root_v]; i >= 1 && count < k; i--) {
                    swap(heap[i], heap[i / 2]);
                    count++;
                }
                cout << heap[1] << endl;
            }
        }
    }
    return 0;
}

// Heapify the subtree rooted at index i
void heapify(int n, int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    if (left <= n && heap[left] > heap[largest]) largest = left;
    if (right <= n && heap[right] > heap[largest]) largest = right;
    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(n, largest);
    }
}