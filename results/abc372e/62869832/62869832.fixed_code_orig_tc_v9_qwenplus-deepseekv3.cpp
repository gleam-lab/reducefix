#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int parent[MAXN];
vector<int> top10[MAXN];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (top10[a].size() < top10[b].size())
            swap(a, b);
        
        vector<int> merged;
        merge(top10[a].rbegin(), top10[a].rend(),
              top10[b].rbegin(), top10[b].rend(),
              back_inserter(merged), greater<int>());
        
        if (merged.size() > 10)
            merged.resize(10);
        
        top10[a] = merged;
        parent[b] = a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        top10[i] = {i};
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            union_sets(u, v);
        } else {
            int root = find_set(u);
            if (v > top10[root].size()) {
                cout << "-1\n";
            } else {
                cout << top10[root][v-1] << "\n";
            }
        }
    }
    
    return 0;
}