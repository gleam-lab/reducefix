#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

pair<int, int> p[maxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> p[i].first;
        for (int i = 0; i < n; i++) cin >> p[i].second;
        
        sort(p, p + n);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        long long ans = LLONG_MAX;
        
        for (int i = 0; i < n; i++) {
            sum += p[i].second;
            pq.push(p[i].second);
            
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k) {
                ans = min(ans, sum * p[i].first);
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}