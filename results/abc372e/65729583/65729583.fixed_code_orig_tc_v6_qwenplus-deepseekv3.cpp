#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 10;

int parent[MAXN];
vector<int> component[MAXN];
priority_queue<int> heap[MAXN];

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;

    if (component[u].size() < component[v].size()) {
        swap(u, v);
    }

    // Merge the smaller component into the larger one
    parent[v] = u;
    for (int num : component[v]) {
        component[u].push_back(num);
        heap[u].push(num);
        while (heap[u].size() > MAXK) {
            heap[u].pop();
        }
    }
    component[v].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        component[i].push_back(i);
        heap[i].push(i);
    }

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            
            if (heap[root].size() < k) {
                cout << -1 << '\n';
                continue;
            }

            vector<int> temp;
            for (int i = 0; i < k; i++) {
                temp.push_back(heap[root].top());
                heap[root].pop();
            }
            
            cout << temp.back() << '\n';
            
            for (int num : temp) {
                heap[root].push(num);
            }
        }
    }

    return 0;
}