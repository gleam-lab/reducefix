#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;

vector<int> parent(MAX_N);
vector<vector<int>> graph(MAX_N);
vector<vector<int>> vertex_list(MAX_N);

void find_set(int v) {
    if (parent[v] == v) return;
    parent[v] = find_set(parent[v]);
}

void union_sets(int u, int v) {
    find_set(u);
    find_set(v);
    if (vertex_list[u].size() > vertex_list[v].size()) {
        swap(vertex_list[u], vertex_list[v]);
    }
    for (int to : vertex_list[v]) {
        vertex_list[u].push_back(to);
    }
    parent[v] = u;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> answers;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        vertex_list[i].push_back(i);
    }
    for (int i = 0; i < Q; i++) {
        int type, u, v, k;
        cin >> type >> u >> v;
        if (type == 1) {
            union_sets(u, v);
            vector<int> combined_list = vertex_list[u];
            sort(combined_list.rbegin(), combined_list.rend()); // Sort in descending order
            vertex_list[u] = combined_list;
            // Keep only the top 10 elements
            if (combined_list.size() > 10) {
                combined_list.resize(10);
            }
            vertex_list[u].erase(unique(vertex_list[u].begin(), vertex_list[u].end()), vertex_list[u].end());
        } else {
            int leader = parent[v];
            if (vertex_list[leader].size() < k) {
                answers.push_back(-1);
            } else {
                answers.push_back(vertex_list[leader][k - 1]);
            }
        }
    }
    for (int ans : answers) {
        cout << ans << '\n';
    }
    return 0;
}