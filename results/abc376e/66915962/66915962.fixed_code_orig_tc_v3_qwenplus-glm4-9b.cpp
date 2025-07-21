#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> AB(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> AB[i].first;
            AB[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> AB[i].second;
        }
        
        sort(AB.rbegin(), AB.rend()); // Sort descending by A_i
        long long ans = LLONG_MAX;
        priority_queue<int> maxB;
        long long sumB = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                sumB -= maxB.top();
                maxB.pop();
            }
            maxB.push(AB[i].second);
            sumB += AB[i].second;
            if (i >= k - 1) {
                ans = min(ans, (long long)AB[i].first * sumB);
            }
        }
        
        cout << ans << "\n";
    }

    return 0;
}