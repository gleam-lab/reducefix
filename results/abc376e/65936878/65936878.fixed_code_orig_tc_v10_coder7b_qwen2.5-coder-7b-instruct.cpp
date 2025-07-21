#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    vector<pair<int, int>> pairs(n);
    for(int i = 0; i < n; ++i) pairs[i] = {a[i], b[i]};
    
    sort(pairs.begin(), pairs.end());
    priority_queue<int> pq;
    int sum = 0;
    for(int i = 0; i < k-1; ++i) {
        pq.push(-pairs[i].second);
        sum -= pairs[i].second;
    }
    
    int res = 1e18;
    for(int i = k-1; i < n; ++i) {
        int curr = pairs[i].first * (-pq.top() + pairs[i].second + sum);
        res = min(res, curr);
        
        sum -= pairs[i].second;
        pq.push(-pairs[i].second);
    }

    cout << res << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}