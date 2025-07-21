#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K = 10;

int fa[MAXN];
vector<int> as[MAXN];

int gtf(int x) {
    if(fa[x] != x) {
        fa[x] = gtf(fa[x]);
    }
    return fa[x];
}

void merge(int u, int v) {
    u = gtf(u);
    v = gtf(v);
    if(u == v) return;
    
    if(as[u].size() < as[v].size()) {
        swap(u, v);
    }
    
    vector<int> merged;
    merged.reserve(K);
    int i = 0, j = 0;
    while((i < as[u].size() || j < as[v].size()) && merged.size() < K) {
        if(i < as[u].size() && (j >= as[v].size() || as[u][i] >= as[v][j])) {
            merged.push_back(as[u][i++]);
        } else {
            merged.push_back(as[v][j++]);
        }
    }
    
    as[u] = merged;
    fa[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for(int i = 1; i <= N; i++) {
        fa[i] = i;
        as[i] = {i};
    }
    
    while(Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if(op == 1) {
            merge(u, v);
        } else {
            int root = gtf(u);
            if(v > as[root].size()) {
                cout << "-1\n";
            } else {
                cout << as[root][v-1] << "\n";
            }
        }
    }
    
    return 0;
}