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
        for (int i = 0; i < k; ++i) {
            minHeap.push(p[i].second);
            sum += p[i].second;
        }
        long long ans = sum * p[k - 1].first;
        
        for (int i = k; i < n; ++i) {
            if (p[i].second > minHeap.top()) {
                sum -= minHeap.top();
                minHeap.pop();
                minHeap.push(p[i].second);
                sum += p[i].second;
            }
            ans = min(ans, sum * p[i].first);
        }
        cout << ans << '\n';
    }
    return 0;
}