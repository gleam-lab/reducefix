#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep1(a)          for(ll i = 0; i < (ll)(a); i++)
#define rep2(i, a)       for(ll i = 0; i < (ll)(a); i++)
#define rep3(i, a, b)    for(ll i = (a); i < (ll)(b); i++)
#define rep4(i, a, b, c) for(ll i = (a); i < (ll)(b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep1(a)          for(ll i = (ll)(a-1); i >= (ll)0 ; i--)
#define rrep2(i, a)       for(ll i = (ll)(a-1); i >= (ll)0; i--)
#define rrep3(i, a, b)    for(ll i = (ll)(a-1); i >=(b); i--)
#define rrep4(i, a, b, c) for(ll i = (ll)(a-1); i >=(b); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define fi first
#define se second
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL(t);
    rep(t){
        LL(n,K);
        vector<pll> a(n);
        rep(n) cin >> a[i].fi;
        rep(n) cin >> a[i].se;
        sort(a.begin(), a.end());
        
        priority_queue<ll> pq;
        ll sum = 0;
        
        // Initialize with first K elements
        rep(i, K) {
            pq.push(a[i].se);
            sum += a[i].se;
        }
        
        ll ans = sum * a[K-1].fi;
        
        // Slide window from K to N-1
        rep(i, K, n) {
            if (a[i].se < pq.top()) {
                sum -= pq.top();
                pq.pop();
                sum += a[i].se;
                pq.push(a[i].se);
                ans = min(ans, sum * a[i].fi);
            }
        }
        cout << ans << '\n';
    }
}