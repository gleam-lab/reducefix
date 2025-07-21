#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
int as[200005][11];
int fa[200005];
int n,q;

int gtf(int x){
    int ret = x;
    while(fa[ret] != ret) ret = fa[ret];
    int t = x;
    while(t != ret){
        int temp = t;
        t = fa[t];
        fa[temp] = ret;
    }
    return ret;
}

void update_as(int root, int val){
    for(int i = 0; i <= 9; ++i){
        if(as[root][i] == -1 || val > as[root][i]){
            for(int j = 9; j > i; --j) as[root][j] = as[root][j-1];
            as[root][i] = val;
            break;
        }
    }
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        fa[i] = i;
        for(int j = 0; j < 10; ++j) as[i][j] = -1;
    }

    int op, ix, iy;
    for(int i = 0; i < q; ++i){
        cin >> op >> ix >> iy;
        if(op == 1){
            ix = gtf(ix), iy = gtf(iy);
            if(ix != iy){
                for(auto it : adj[iy]) update_as(ix, it);
                for(auto it : adj[ix]) update_as(iy, it);
                adj[ix].insert(adj[ix].end(), adj[iy].begin(), adj[iy].end());
                adj[iy].clear();
                fa[iy] = ix;
            }
        } else {
            ix = gtf(ix);
            if(iy > 10 || as[ix][iy-1] == -1) cout << "-1" << '\n';
            else cout << as[ix][iy-1] << '\n';
        }
    }
    return 0;
}