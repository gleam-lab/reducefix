#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K = 10;

int parent[MAXN];
vector<int> topk[MAXN];

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (topk[a].size() < topk[b].size()) {
            swap(a, b);
        }
        vector<int> merged;
        merge(topk[a].rbegin(), topk[a].rend(),
              topk[b].rbegin(), topk[b].rend(),
              back_inserter(merged), greater<int>());
        if (merged.size() > K) {
            merged.resize(K);
        }
        topk[a] = merged;
        parent[b] = a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        topk[i] = {i};
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            union_sets(u, v);
        } else {
            int root = find_set(u);
            if (topk[root].size() < v) {
                cout << "-1\n";
            } else {
                cout << topk[root][v-1] << "\n";
            }
        }
    }

    return 0;
}