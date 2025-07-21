#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K = 10;

int fa[MAXN];
vector<int> top[MAXN];

int gtf(int x) {
    if(x == fa[x]) return x;
    return fa[x] = gtf(fa[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
        top[i] = {i};
    }
    
    while(q--) {
        int op, u, v, k;
        cin >> op;
        
        if(op == 1) {
            cin >> u >> v;
            int fu = gtf(u), fv = gtf(v);
            if(fu == fv) continue;
            
            vector<int> merged;
            merge(top[fu].rbegin(), top[fu].rend(),
                  top[fv].rbegin(), top[fv].rend(),
                  back_inserter(merged), greater<int>());
            
            if(merged.size() > K) merged.resize(K);
            top[fu] = merged;
            fa[fv] = fu;
        } else {
            cin >> v >> k;
            int fv = gtf(v);
            if(k > top[fv].size()) {
                cout << "-1\n";
            } else {
                cout << top[fv][top[fv].size()-k] << "\n";
            }
        }
    }
    
    return 0;
}