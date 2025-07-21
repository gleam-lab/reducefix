#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep(i,r) for(ll i=0;i<(ll)r;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

const ll inf = (1LL << 61);

struct SegTree {
    ll n;
    vl dat;
    
    SegTree() {}
    
    SegTree(ll sz) {
        n = 1;
        while(n < sz) n <<= 1;
        dat.assign(2 * n, inf);
    }
    
    void update(ll pos, ll val) {
        pos += n;
        dat[pos] = min(dat[pos], val);
        while(pos > 1) {
            pos >>= 1;
            dat[pos] = min(dat[pos * 2], dat[pos * 2 + 1]);
        }
    }
    
    ll query(ll a, ll b, ll k = 1, ll l = 0, ll r = -1) {
        if(r == -1) r = n;
        if(r <= a || b <= l) return inf;
        if(a <= l && r <= b) return dat[k];
        ll vl = query(a, b, k * 2, l, (l + r) / 2);
        ll vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
        return min(vl, vr);
    }
};

int main() {
    ll h, w, q; cin >> h >> w >> q;
    vector<SegTree> seg_h(h), seg_w(w);
    rep(i, h) seg_h[i] = SegTree(w + 1);
    rep(j, w) seg_w[j] = SegTree(h + 1);
    
    rep(i, q) {
        ll r, c; cin >> r >> c;
        r--, c--;
        
        if(seg_h[r].query(0, c + 1) != inf) {
            seg_h[r].update(c + 1, inf);
        } else if(seg_h[r].query(c + 2, w + 1) != inf) {
            seg_h[r].update(c + 2, inf);
        } else {
            seg_h[r].update(c + 1, inf);
        }
        
        if(seg_w[c].query(0, r + 1) != inf) {
            seg_w[c].update(r + 1, inf);
        } else if(seg_w[c].query(r + 2, h + 1) != inf) {
            seg_w[c].update(r + 2, inf);
        } else {
            seg_w[c].update(r + 1, inf);
        }
    }
    
    ll ans = 0;
    rep(i, h) {
        ans += seg_h[i].query(0, w + 1);
    }
    rep(j, w) {
        ans += seg_w[j].query(0, h + 1);
    }
    
    cout << ans << endl;
    return 0;
}