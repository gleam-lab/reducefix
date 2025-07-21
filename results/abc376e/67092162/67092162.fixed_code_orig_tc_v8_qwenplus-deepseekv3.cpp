#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;

int t, n, k;
pair<int, int> p[maxN];
long long prefix[maxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> p[i].first;
        for (int i = 1; i <= n; i++) cin >> p[i].second;
        
        sort(p + 1, p + n + 1);
        
        priority_queue<int> pq;
        long long sum = 0;
        
        for (int i = 1; i <= n; i++) {
            if (i <= k) {
                sum += p[i].second;
                pq.push(p[i].second);
                prefix[i] = sum;
            } else {
                if (p[i].second < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    sum += p[i].second;
                    pq.push(p[i].second);
                }
                prefix[i] = sum;
            }
        }
        
        long long ans = LLONG_MAX;
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                ans = min(ans, 1LL * p[i].first * p[i].second);
            }
        } else {
            for (int i = k; i <= n; i++) {
                long long current = 1LL * p[i].first * (prefix[i-1] + p[i].second);
                ans = min(ans, current);
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}