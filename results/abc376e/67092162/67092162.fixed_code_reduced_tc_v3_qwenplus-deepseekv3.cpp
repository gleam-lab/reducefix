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
        for (int i = 0; i < n; ++i) {
            cin >> p[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> p[i].second;
        }
        sort(p.begin(), p.end());
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        long long ans = LLONG_MAX;
        
        for (int i = n - 1; i >= 0; --i) {
            sum += p[i].second;
            minHeap.push(p[i].second);
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == k) {
                ans = min(ans, p[i].first * sum);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}