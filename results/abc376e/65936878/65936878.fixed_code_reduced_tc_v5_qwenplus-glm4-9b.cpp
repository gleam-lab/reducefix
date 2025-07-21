#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) cin >> v[i].first;
        for (int i = 0; i < n; i++) cin >> v[i].second;
        
        // Sort the vector by the values in A in descending order
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        long long sum = 0, maxsum = 0, ans = 1e18;
        
        // Calculate the sum of B for the first K elements and the max B sum for K+1 elements
        for (int i = 0; i < k; i++) {
            sum += v[i].second;
        }
        for (int i = k; i < n; i++) {
            maxsum = max(maxsum, v[i].second);
        }
        
        // Calculate the minimum possible value
        ans = min(ans, maxsum * sum);
        
        // Iterate through the vector to find the best possible answer
        for (int i = 0; i < k; i++) {
            for (int j = k; j < n; j++) {
                ans = min(ans, v[i].first * (sum - v[i].second + v[j].second));
                sum = sum - v[i].second + v[j].second;
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}