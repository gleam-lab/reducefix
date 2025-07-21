#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;

int t, n, k;
pair<int, int> p[maxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> p[i].first;
        for (int i = 0; i < n; ++i) cin >> p[i].second;
        
        sort(p, p + n);
        
        priority_queue<int> q;
        long long sum = 0;
        long long ans = LLONG_MAX;
        
        for (int i = 0; i < k - 1; ++i) {
            sum += p[i].second;
            q.push(p[i].second);
        }
        
        for (int i = k - 1; i < n; ++i) {
            sum += p[i].second;
            ans = min(ans, p[i].first * sum);
            if (!q.empty() && q.top() > p[i].second) {
                sum -= q.top();
                q.pop();
                q.push(p[i].second);
                sum += p[i].second;
            } else {
                sum -= p[i].second;
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}