#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define clr(a,b) memset((a),(b),sizeof(a))
#define sz(x) ((int)x.size())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define trav(a,x) for(auto&a:x)
#define all(v) v.begin(),v.end()

struct SegTree {
    int n;
    vector<ll> tree;
    
    SegTree(int _n) {
        n = _n;
        tree.resize(4*n+10, 0);
    }
    
    void update(int p, int l, int r, int pos, ll val) {
        if(l == r) {
            tree[p] = val;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(p*2, l, mid, pos, val);
        else update(p*2+1, mid+1, r, pos, val);
        tree[p] = tree[p*2] + tree[p*2+1];
    }
    
    ll query(int p, int l, int r, int ql, int qr) {
        if(l > qr || r < ql) return 0;
        if(l >= ql && r <= qr) return tree[p];
        int mid = (l+r)/2;
        return query(p*2, l, mid, ql, qr) + query(p*2+1, mid+1, r, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    SegTree seg_h(w), seg_w(h);
    
    rep(i,0,w) seg_h.update(1, 0, w-1, i, w);
    rep(i,0,h) seg_w.update(1, 0, h-1, i, h);
    
    rep(i,0,q) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        if(grid[r][c]) {
            grid[r][c] = false;
            seg_h.update(1, 0, w-1, c, seg_h.query(1, 0, w-1, c, c));
            seg_w.update(1, 0, h-1, r, seg_w.query(1, 0, h-1, r, r));
        } else {
            int left = 0, right = w-1;
            while(left <= right) {
                int mid = (left+right)/2;
                if(seg_h.query(1, 0, w-1, 0, mid) == mid+1) right = mid-1;
                else left = mid+1;
            }
            if(left < w) {
                grid[r][left] = false;
                seg_h.update(1, 0, w-1, left, seg_h.query(1, 0, w-1, left, left));
            }
            
            left = 0, right = h-1;
            while(left <= right) {
                int mid = (left+right)/2;
                if(seg_w.query(1, 0, h-1, 0, mid) == mid+1) right = mid-1;
                else left = mid+1;
            }
            if(left < h) {
                grid[left][c] = false;
                seg_w.update(1, 0, h-1, left, seg_w.query(1, 0, h-1, left, left));
            }
        }
    }
    
    ll ans = 0;
    rep(i,0,h) ans += seg_w.query(1, 0, h-1, i, i);
    rep(i,0,w) ans += seg_h.query(1, 0, w-1, i, i);
    
    cout << ans << '\n';
    
    return 0;
}