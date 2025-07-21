#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool compare(const pii& a, const pii& b) {
    return a.first > b.first;
}

void solve(int n, int k, vector<int>& a, vector<int>& b) {
    vector<pii> ab(n);
    for (int i = 0; i < n; ++i) ab[i] = {a[i], b[i]};
    
    sort(ab.begin(), ab.end(), compare);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    ll sumB = 0;
    for (int i = 0; i < k; ++i) {
        pq.push(ab[i].second);
        sumB += ab[i].second;
    }
    
    ll ans = LLONG_MAX;
    for (int i = k; i < n; ++i) {
        ans = min(ans, static_cast<ll>(ab[i].first) * sumB);
        
        sumB -= pq.top();
        pq.pop();
        
        pq.push(ab[i].second);
        sumB += ab[i].second;
    }
    
    if (!pq.empty()) ans = min(ans, static_cast<ll>(ab[n-1].first) * sumB);
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        solve(n, k, a, b);
    }
    
    return 0;
}