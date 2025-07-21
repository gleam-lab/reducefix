#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int parent[MAXN];
vector<priority_queue<int, vector<int>, greater<int>>> topK(MAXN); // Min-heap to keep top 10 largest

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU == rootV) return;

    if (topK[rootU].size() < topK[rootV].size()) {
        swap(rootU, rootV);
    }

    while (!topK[rootV].empty()) {
        topK[rootU].push(topK[rootV].top());
        topK[rootV].pop();
        if (topK[rootU].size() > 10) {
            topK[rootU].pop();
        }
    }

    parent[rootV] = rootU;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        topK[i].push(i);
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (topK[root].size() < v) {
                cout << -1 << '\n';
            } else {
                vector<int> temp;
                while (!topK[root].empty()) {
                    temp.push_back(topK[root].top());
                    topK[root].pop();
                }
                cout << temp[temp.size() - v] << '\n';
                for (int num : temp) {
                    topK[root].push(num);
                }
            }
        }
    }

    return 0;
}