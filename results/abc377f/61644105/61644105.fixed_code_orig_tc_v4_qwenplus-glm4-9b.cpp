#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int MOD = 1e9 + 7;

int find(int x, vector<int>& parent) {
    if (x == parent[x]) return x;
    parent[x] = find(parent[x], parent);
    return parent[x];
}

void union_sets(int x, int y, vector<int>& parent, vector<int>& rank) {
    int xroot = find(x, parent);
    int yroot = find(y, parent);
    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // We will use a union-find to find connected components of safe cells
    vector<int> parent(n * n + 1), rank(n * n + 1, 0);
    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < m; ++i) {
        int x = pieces[i].first - 1;
        int y = pieces[i].second - 1;
        int idx = x * n + y;

        // Calculate all the indices affected by this piece
        vector<int> affected = {idx, idx - x, idx - y, idx + x, idx + y, idx + x + y, idx - x - y};

        for (int j = 0; j < affected.size(); ++j) {
            int next = affected[j];
            if (next >= 0 && next < n * n && parent[next] != idx) {
                union_sets(idx, next, parent, rank);
            }
        }
    }

    // Count the number of unique sets (connected components of safe cells)
    long long safe_cells = 0;
    for (int i = 0; i < n * n; ++i) {
        if (find(i, parent) == i) {
            safe_cells++;
        }
    }

    cout << (safe_cells * (n * n - m)) % MOD << endl;

    return 0;
}