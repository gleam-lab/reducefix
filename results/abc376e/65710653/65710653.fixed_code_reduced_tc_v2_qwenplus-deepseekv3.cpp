#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(), (v).end()

template<typename T>
inline void print(const T &x) { cout << x << '\n'; }

template<typename T>
inline void print(const vector<T> &v) {
    for (auto &x : v) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL(t);
    rep(_, t) {
        LL(n, k);
        vector<pll> ab(n);
        rep(i, n) cin >> ab[i].fi;
        rep(i, n) cin >> ab[i].se;
        
        sort(all(ab));
        
        priority_queue<ll> pq;
        ll sum = 0;
        ll ans = LLONG_MAX;
        
        rrep(i, n) {
            sum += ab[i].se;
            pq.push(ab[i].se);
            
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k) {
                ans = min(ans, ab[i].fi * sum);
            }
        }
        
        print(ans);
    }
    
    return 0;
}