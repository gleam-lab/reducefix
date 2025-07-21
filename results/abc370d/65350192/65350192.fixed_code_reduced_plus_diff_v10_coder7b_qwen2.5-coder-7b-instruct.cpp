#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;

struct SegTree {
    int n;
    vector<ll> segtree;
    SegTree(int size): n(size), segtree(4*size+5) {}
    void update(int pos, int val) {update(pos, val, 0, 0, n-1);}
    void update(int pos, int val, int node, int tl, int tr) {
        if(tl == tr) segtree[node] = val;
        else {
            int tm = (tl+tr)/2;
            if(pos <= tm) update(pos, val, 2*node+1, tl, tm);
            else update(pos, val, 2*node+2, tm+1, tr);
            segtree[node] = min(segtree[2*node+1], segtree[2*node+2]);
        }
    }
    ll query(int l, int r) {return query(l, r, 0, 0, n-1);}
    ll query(int l, int r, int node, int tl, int tr) {
        if(l > r) return INT_MAX;
        if(l == tl && r == tr) return segtree[node];
        int tm = (tl+tr)/2;
        return min(query(l, min(r,tm), 2*node+1, tl, tm),
                   query(max(l,tm+1), r, 2*node+2, tm+1, tr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1));

    vector<SegTree> vertical_walls(w, SegTree(h));
    vector<SegTree> horizontal_walls(h, SegTree(w));

    while(q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        if(grid[x][y] == 0) continue;

        grid[x][y] = 0;

        vertical_walls[y].update(x, 0);
        horizontal_walls[x].update(y, 0);

        if(x > 0) vertical_walls[y].update(x-1, vertical_walls[y].query(x-1,x-1)+1);
        if(x < h-1) vertical_walls[y].update(x+1, vertical_walls[y].query(x+1,x+1)+1);
        if(y > 0) horizontal_walls[x].update(y-1, horizontal_walls[x].query(y-1,y-1)+1);
        if(y < w-1) horizontal_walls[x].update(y+1, horizontal_walls[x].query(y+1,y+1)+1);
    }

    int ans = 0;
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            if(grid[i][j]) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}