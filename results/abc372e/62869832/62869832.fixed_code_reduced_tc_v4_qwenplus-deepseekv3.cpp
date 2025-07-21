#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K = 10;

int parent[MAXN];
vector<int> topk[MAXN];

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void merge_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (topk[a].size() < topk[b].size()) {
            swap(a, b);
        }
        parent[b] = a;
        
        vector<int> merged;
        merge(topk[a].begin(), topk[a].end(),
              topk[b].begin(), topk[b].end(),
              back_inserter(merged), greater<int>());
        
        if (merged.size() > K) merged.resize(K);
        topk[a] = merged;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        topk[i] = {i};
    }
    
    while (Q--) {
        int type, u, v;
        cin >> type >> u >> v;
        
        if (type == 1) {
            merge_sets(u, v);
        } else {
            int root = find_set(u);
            if (v > topk[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << topk[root][v-1] << '\n';
            }
        }
    }
    
    return 0;
}