#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i].first;
        for (int i = 0; i < n; ++i) cin >> p[i].second;
        
        sort(p.begin(), p.end());
        
        priority_queue<int> pq;
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            pq.push(p[i].second);
            sum += p[i].second;
        }
        long long ans = p[k - 1].first * sum;
        
        for (int i = k; i < n; ++i) {
            if (p[i].second < pq.top()) {
                sum -= pq.top();
                pq.pop();
                pq.push(p[i].second);
                sum += p[i].second;
            }
            ans = min(ans, p[i].first * sum);
        }
        cout << ans << "\n";
    }
    return 0;
}