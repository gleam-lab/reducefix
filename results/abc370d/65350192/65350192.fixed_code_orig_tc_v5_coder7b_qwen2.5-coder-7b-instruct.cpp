#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
using PII = pair<int,int>;

const int MAX_N = 4e5+5;

struct UnionFind {
    vector<int> par, rank;
    UnionFind(int n):par(n,-1),rank(n,0){}
    int root(int x){
        if(par[x] == -1)return x;
        else return par[x] = root(par[x]);
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
    void unite(int x, int y){
        x = root(x), y = root(y);
        if(x==y)return;
        if(rank[x]<rank[y])swap(x,y);
        par[y] = x;
        if(rank[x]==rank[y])rank[x]++;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;

    UnionFind uf_h(h * w);
    UnionFind uf_w(h * w);

    vector<vector<bool>> grid(h, vector<bool>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)grid[i][j]=true;
    }

    while(q--){
        int r, c;
        cin >> r >> c;
        r--, c--;

        if(grid[r][c]){
            grid[r][c] = false;
            int idx = r * w + c;
            
            // Check left
            if(c > 0 && !grid[r][c-1]){
                int l_idx = r * w + (c-1);
                uf_w.unite(idx, l_idx);
            }
            
            // Check right
            if(c < w-1 && !grid[r][c+1]){
                int r_idx = r * w + (c+1);
                uf_w.unite(idx, r_idx);
            }
            
            // Check up
            if(r > 0 && !grid[r-1][c]){
                int u_idx = (r-1) * w + c;
                uf_h.unite(idx, u_idx);
            }
            
            // Check down
            if(r < h-1 && !grid[r+1][c]){
                int d_idx = (r+1) * w + c;
                uf_h.unite(idx, d_idx);
            }
        }else{
            continue;
        }
    }

    set<int> h_set, w_set;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int idx = i * w + j;
            if(!grid[i][j]){
                int ri = uf_h.root(idx);
                int ci = uf_w.root(idx);
                if(h_set.find(ri)==h_set.end()){
                    h_set.insert(ri);
                }
                if(w_set.find(ci)==w_set.end()){
                    w_set.insert(ci);
                }
            }
        }
    }

    cout << h_set.size() + w_set.size() << endl;
    return 0;
}