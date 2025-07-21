#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef pair<int,int> P;
using ll = long long;

struct BIT{
    int n;
    vector<ll> dat;
    BIT(int n_) : n(n_), dat(n_,0){}
    void add(int p,ll x){
        for(int i=p;i<=n-1;i+=(i&(-i))) dat[i] += x;
    }
    ll sum(int p){
        ll s=0;
        for(int i=p;i>=0;i=(i&(i+1))-1) s+=dat[i];
        return s;
    }
};

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    BIT bit_h(h),bit_w(w);
    rep(i,h) rep(j,w) {
        bit_h.add(i,1);
        bit_w.add(j,1);
    }
    rep(qi,q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (bit_h.sum(r) == 1 && bit_w.sum(c) == 1) {
            bit_h.add(r,-1);
            bit_w.add(c,-1);
        } else {
            int mh = bit_h.sum(r)-1;
            int mw = bit_w.sum(c)-1;
            if(mh > 0){
                bit_h.add(r,-1);
                bit_h.add(mh-1,1);
            }
            if(mw > 0){
                bit_w.add(c,-1);
                bit_w.add(mw-1,1);
            }
        }
    }
    int ans = 0;
    rep(i,w) {
        ans += bit_h.sum(i);
    }
    cout << ans << "\n";
    return 0;
}