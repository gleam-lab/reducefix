#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        vector<long long> b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> b[i];
            a[i].second = i;
        }
        
        // Sort by A values in descending order
        sort(a.begin(), a.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first;
        });
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long sum = 0, ans = LLONG_MAX;
        
        for (int i = 0; i < n; ++i) {
            pq.push(b[a[i].second]);
            sum += b[a[i].second];
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (i >= k - 1) {
                ans = min(ans, (sum + b[a[i + k - 1].second]) * a[i].first);
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}