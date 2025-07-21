#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000;
vector<int> parent(MAX_N, -1); // Union-find parent array

int find(int x) {
    if (parent[x] < 0) {
        return x;
    } else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

void union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (parent[rootX] > parent[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootX] += parent[rootY];
        parent[rootY] = rootX;
    }
}

int n, m;

int main() {
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Initialize union-find structure
    for (int i = 1; i <= n * n; i++) {
        parent[i] = -1; // Unrooted initially
    }

    // Link all capturing cells together
    for (auto& p : pieces) {
        int x = p.first - 1;
        int y = p.second - 1;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                union_sets((nx) * n + (ny), x * n + y);
            }
        }
    }

    // Count the number of elements in each set and subtract from total
    int free_cells = n * n;
    for (int i = 0; i < n * n; i++) {
        int root = find(i);
        if (parent[root] == -1) { // It's a root with size 1
            free_cells--;
        }
    }

    cout << free_cells << endl;

    return 0;
}