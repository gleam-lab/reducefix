#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef pair<int,int> P;
using ll = long long;

struct SegTree{
    int n;
    vector<ll> dat;
    SegTree(int _n): n(_n), dat(_n*4) {}
    void update(int k, ll x){
        k += n-1;
        dat[k] = x;
        while(k > 0){
            k >>= 1;
            dat[k] = min(dat[k*2],dat[k*2+1]);
        }
    }
    ll query(int l, int r){
        l += n-1; r += n-1;
        ll res = LLONG_MAX;
        while(l <= r){
            if(l&1) res = min(res,dat[l++]);
            if(!(r&1)) res = min(res,dat[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h,vector<bool>(w,false));
    SegTree seg_h(h),seg_w(w);
    rep(i,h) rep(j,w) seg_h.update(i,j),seg_w.update(j,i);

    rep(qi,q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (!grid[r][c]) {
            auto iter_h = lower_bound(seg_h.dat.begin()+r*(w+1)+1,seg_h.dat.begin()+(r+1)*(w+1),w);
            if(iter_h != seg_h.dat.begin()+(r+1)*(w+1)){
                int tmp = *prev(iter_h)-1;
                grid[tmp][c] = false;
                seg_h.update(tmp,c);
            }

            auto iter_w = lower_bound(seg_w.dat.begin()+c*(h+1)+1,seg_w.dat.begin()+(c+1)*(h+1),h);
            if(iter_w != seg_w.dat.begin()+(c+1)*(h+1)){
                int tmp = *prev(iter_w)-1;
                grid[r][tmp] = false;
                seg_w.update(r,tmp);
            }
        } else {
            grid[r][c] = false;
            seg_h.update(r,c);
            seg_w.update(c,r);
        }
    }
    int ans = 0;
    rep(i,w) ans += seg_h.query(i,i);
    rep(i,h) ans += seg_w.query(i,i);
    cout << ans << "\n";
    return 0;
}