#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pll> pairs(N);
        rep(i, 0, N) cin >> pairs[i].first;
        rep(i, 0, N) cin >> pairs[i].second;
        
        sort(all(pairs));
        
        priority_queue<ll> max_heap;
        ll sum = 0;
        ll ans = LLONG_MAX;
        
        rep(i, 0, N) {
            ll current_A = pairs[i].first;
            ll current_B = pairs[i].second;
            
            if (max_heap.size() < K) {
                max_heap.push(current_B);
                sum += current_B;
                if (max_heap.size() == K) {
                    ans = min(ans, sum * current_A);
                }
            } else {
                if (current_B < max_heap.top()) {
                    sum -= max_heap.top();
                    max_heap.pop();
                    max_heap.push(current_B);
                    sum += current_B;
                    ans = min(ans, sum * current_A);
                }
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}