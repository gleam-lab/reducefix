#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> as[MAXN];
int fa[MAXN];

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
    while((i < as[u].size() || j < as[v].size()) && merged.size() < 10) {
        int val_u = (i < as[u].size()) ? as[u][i] : -1;
        int val_v = (j < as[v].size()) ? as[v][j] : -1;
        
        if(val_u > val_v) {
            merged.push_back(val_u);
            i++;
        } else {
            merged.push_back(val_v);
            j++;
        }
    }
    
    as[u] = merged;
    fa[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for(int i = 1; i <= N; i++) {
        fa[i] = i;
        as[i].clear();
        as[i].push_back(i);
    }
    
    while(Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if(op == 1) {
            merge(u, v);
        } else {
            int root = gtf(u);
            if(v > (int)as[root].size()) {
                cout << "-1\n";
            } else {
                cout << as[root][v-1] << "\n";
            }
        }
    }
    
    return 0;
}