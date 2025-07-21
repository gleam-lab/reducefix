#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i].first;
        for (int i = 0; i < n; ++i) cin >> p[i].second;
        
        sort(p.begin(), p.end());
        
        priority_queue<int> q;
        long long sum = 0;
        for (int i = 0; i < k - 1; ++i) {
            q.push(-p[i].second);
            sum += p[i].second;
        }
        
        long long ans = LLONG_MAX;
        for (int i = k - 1; i < n; ++i) {
            sum += p[i].second;
            q.push(-p[i].second);
            if (q.size() > k) {
                sum += q.top();
                q.pop();
            }
            ans = min(ans, p[i].first * sum);
        }
        cout << ans << '\n';
    }
    return 0;
}