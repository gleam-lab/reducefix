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
        for (int i = 0; i < n; i++) cin >> p[i].first;
        for (int i = 0; i < n; i++) cin >> p[i].second;
        
        sort(p, p + n);
        
        priority_queue<int> q; // max-heap to keep the smallest K-1 B_i's
        
        long long sum = 0;
        for (int i = 0; i < k - 1; i++) {
            q.push(p[i].second);
            sum += p[i].second;
        }
        
        long long ans = LLONG_MAX;
        for (int i = k - 1; i < n; i++) {
            if (k == 1) {
                ans = min(ans, (long long)p[i].first * p[i].second);
            } else {
                long long current_sum = sum + p[i].second;
                ans = min(ans, (long long)p[i].first * current_sum);
                
                if (!q.empty() && p[i].second < q.top()) {
                    sum -= q.top();
                    q.pop();
                    q.push(p[i].second);
                    sum += p[i].second;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}