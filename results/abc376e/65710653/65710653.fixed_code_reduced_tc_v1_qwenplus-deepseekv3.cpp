#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = a; i >= b; i--)
#define pb push_back
#define mp make_pair

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL(t);
    rep(_, t) {
        LL(n, k);
        vector<pll> ab(n);
        rep(i, 0, n) cin >> ab[i].first;
        rep(i, 0, n) cin >> ab[i].second;
        
        sort(ab.begin(), ab.end());
        
        priority_queue<ll> pq;
        ll sum = 0;
        ll ans = LLONG_MAX;
        
        rep(i, 0, n) {
            sum += ab[i].second;
            pq.push(ab[i].second);
            
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k) {
                ans = min(ans, ab[i].first * sum);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}