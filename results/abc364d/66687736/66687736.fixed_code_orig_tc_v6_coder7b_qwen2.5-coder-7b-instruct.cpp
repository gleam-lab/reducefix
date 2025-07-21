#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; ++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    
    vector<pair<int, int>> queries(q);
    rep(i, q) {
        int b, k;
        cin >> b >> k;
        queries[i] = {b, k};
    }
    
    sort(a.begin(), a.end());
    
    vector<int> results(q);
    rep(j, q) {
        int b = queries[j].first;
        int k = queries[j].second - 1; // Adjusting to zero-based index
        
        int pos = lower_bound(a.begin(), a.end(), b) - a.begin();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        if (pos > 0) pq.push(abs(a[pos - 1] - b));
        if (pos < n) pq.push(abs(a[pos] - b));
        
        rep(i, n - 1) {
            int dist = abs(a[i + 1] - b);
            if (dist < pq.top()) {
                pq.pop();
                pq.push(dist);
            }
        }
        
        results[j] = pq.top();
    }
    
    rep(i, q) cout << results[i] << '\n';
    
    return 0;
}