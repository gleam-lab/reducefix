#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 200005;

vector<int> parent(MAX_N + 1);
vector<vector<int>> graph(MAX_N + 1);

void find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
        graph[rootX].insert(rootY);
        graph[rootY].insert(rootX);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    while (Q--) {
        int t, u, v, k;
        cin >> t >> u >> v;
        if (t == 1) {
            union_sets(u, v);
        } else if (t == 2) {
            int rootV = find(v);
            if (k > graph[rootV].size()) {
                cout << -1 << '\n';
            } else {
                // Using a set to keep vertices sorted in descending order
                set<int> sorted(graph[rootV].begin(), graph[rootV].end());
                cout << sorted.begin()[k - 1] << '\n'; // -1 index correction
            }
        }
    }
    return 0;
}