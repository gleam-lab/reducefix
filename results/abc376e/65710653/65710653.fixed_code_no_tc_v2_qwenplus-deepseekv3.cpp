#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, a, b) for (ll i = (a); i < (ll)(b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (ll)(b); i--)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<pll> ab(n);
        rep(i, 0, n) cin >> ab[i].first;
        rep(i, 0, n) cin >> ab[i].second;
        
        sort(ab.begin(), ab.end());
        
        priority_queue<ll> pq;
        ll sum = 0;
        rep(i, 0, k - 1){
            pq.push(ab[i].second);
            sum += ab[i].second;
        }
        
        ll ans = LLONG_MAX;
        rep(i, k - 1, n){
            ll current_sum = sum + ab[i].second;
            ll current_max = ab[i].first;
            ans = min(ans, current_sum * current_max);
            
            if (!pq.empty() && pq.top() > ab[i].second){
                sum -= pq.top();
                pq.pop();
                sum += ab[i].second;
                pq.push(ab[i].second);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}