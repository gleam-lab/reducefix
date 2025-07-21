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
        for (int i = 0; i < n; ++i) {
            cin >> p[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> p[i].second;
        }
        
        sort(p, p + n);
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        long long ans = LLONG_MAX;
        
        for (int i = n - 1; i >= 0; --i) {
            minHeap.push(p[i].second);
            sum += p[i].second;
            
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            
            if (minHeap.size() == k) {
                ans = min(ans, (long long)p[i].first * sum);
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}