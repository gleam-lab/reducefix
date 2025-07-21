#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;

vector<int> parent(MAX_N);
vector<vector<int>> sizes(MAX_N);
vector<int> vertices(MAX_N);

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (sizes[rootX] < sizes[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        sizes[rootX] += sizes[rootY];
    }
}

int queryKthLargest(int v, int k) {
    int rootV = find(v);
    sort(vertices[rootV].rbegin(), vertices[rootV].rend());
    if (k > sizes[rootV]) {
        return -1;
    }
    return vertices[rootV][k - 1];
}

int main() {
    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        sizes[i] = 1;
    }

    int op, u, v, k;
    for (int i = 0; i < Q; i++) {
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            unionSets(u, v);
        } else {
            cin >> v >> k;
            int result = queryKthLargest(v, k);
            cout << result << endl;
        }
    }

    return 0;
}