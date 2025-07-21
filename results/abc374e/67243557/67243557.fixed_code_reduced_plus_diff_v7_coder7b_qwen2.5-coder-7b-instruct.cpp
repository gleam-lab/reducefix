#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(const vector<int>& a, const vector<int>& b, const vector<int>& p, const vector<int>& q, ll x){
    ll ans = 0;
    rep(i,a.size()){
        ll cnt = min(x / (a[i] * b[i]), 1LL);
        ans += cnt * p[i] * a[i] + cnt * q[i] * b[i];
        x -= cnt * a[i] * b[i];
    }
    return ans;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i,n)cin >> a[i] >> p[i] >> b[i] >> q[i];
    ll l = 0, r = 10000000000LL;
    while(r - l > 1){
        ll mid = (l + r) / 2;
        if(f(a, b, p, q, mid) <= x) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}