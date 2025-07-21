#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> as; // as[i] will store top 10 largest vertices in component i, sorted in descending order
vector<int> fa;
int n, q;

int gtf(int x) {
    if(x == fa[x]) return x;
    return fa[x] = gtf(fa[x]);
}

void merge(int u, int v) {
    u = gtf(u);
    v = gtf(v);
    if(u == v) return;
    
    vector<int> merged;
    int i = 0, j = 0;
    // Merge the two sorted lists (both in descending order)
    while((i < as[u].size() || j < as[v].size()) && merged.size() < 10) {
        int val_u = i < as[u].size() ? as[u][i] : -1;
        int val_v = j < as[v].size() ? as[v][j] : -1;
        
        if(val_u > val_v) {
            merged.push_back(val_u);
            i++;
        } else if(val_v != -1) {
            merged.push_back(val_v);
            j++;
        } else {
            break;
        }
    }
    
    fa[v] = u;
    as[u] = merged;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q;
    fa.resize(n+1);
    as.resize(n+1);
    
    for(int i=1; i<=n; i++) {
        fa[i] = i;
        as[i] = {i}; // Initially, each vertex is connected only to itself
    }
    
    while(q--) {
        int op, u, v, k;
        cin >> op;
        if(op == 1) {
            cin >> u >> v;
            merge(u, v);
        } else {
            cin >> v >> k;
            int root = gtf(v);
            if(k > as[root].size()) {
                cout << -1 << "\n";
            } else {
                cout << as[root][k-1] << "\n";
            }
        }
    }
    
    return 0;
}