#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> parent(MAXN);
vector<array<int, 10>> largest(MAXN);

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void merge(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    
    if (a > b) swap(a, b);
    parent[b] = a;
    
    array<int, 20> merged;
    merge(largest[a].rbegin(), largest[a].rend(),
          largest[b].rbegin(), largest[b].rend(),
          merged.rbegin(), greater<int>());
    
    for (int i = 0; i < 10; i++) {
        largest[a][i] = merged[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        fill(largest[i].begin(), largest[i].end(), -1);
        largest[i][0] = i;
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find_set(u);
            if (v > 10 || largest[root][v-1] == -1) {
                cout << "-1\n";
            } else {
                cout << largest[root][v-1] << '\n';
            }
        }
    }
    
    return 0;
}