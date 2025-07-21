#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;

#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define rrep(i, a, b) for(ll i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<pll> items(N);
    for (ll i = 0; i < N; ++i) cin >> items[i].first;
    for (ll i = 0; i < N; ++i) cin >> items[i].second;

    // Sort by A_i ascending
    sort(all(items));

    // Use min-heap to maintain the K smallest B_i values
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sumB = 0;
    
    // Initialize with first K elements
    for (ll i = 0; i < K; ++i) {
        pq.push(items[i].second);
        sumB += items[i].second;
    }
    
    ll ans = sumB * items[K - 1].first;

    // Sliding window
    for (ll i = K; i < N; ++i) {
        // Remove the smallest B in the current set
        sumB -= pq.top();
        pq.pop();
        
        // Add new element
        pq.push(items[i].second);
        sumB += items[i].second;
        
        // Update answer
        ans = min(ans, sumB * items[i].first);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll T;
    cin >> T;
    while (T--) solve();
}