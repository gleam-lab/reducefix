#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K = 10;

int fa[MAXN];
vector<int> top[MAXN];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;
    
    if(top[u].size() < top[v].size()) {
        swap(u, v);
    }
    
    vector<int> merged;
    int i = 0, j = 0;
    while(i < top[u].size() && j < top[v].size() && merged.size() < K) {
        if(top[u][i] > top[v][j]) {
            merged.push_back(top[u][i++]);
        } else {
            merged.push_back(top[v][j++]);
        }
    }
    while(i < top[u].size() && merged.size() < K) {
        merged.push_back(top[u][i++]);
    }
    while(j < top[v].size() && merged.size() < K) {
        merged.push_back(top[v][j++]);
    }
    
    top[u] = merged;
    fa[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for(int i = 1; i <= N; i++) {
        fa[i] = i;
        top[i] = {i};
    }
    
    while(Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if(op == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if(top[root].size() < v) {
                cout << "-1\n";
            } else {
                cout << top[root][v-1] << "\n";
            }
        }
    }
    
    return 0;
}