#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n+1), b(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort by A values
        sort(a.begin(), a.end());
        
        // Prepare prefix sums of B values
        vector<int> prefixSum(n+1);
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i-1] + b[i].first;
        }
        
        int ans = LLONG_MAX;
        
        // Minimum prefix sum with max K elements from B
        vector<int> minPrefixSum(n+1);
        int j = 0;
        for (int i = 0; i < k; ++i) {
            while (j + 1 < n && b[j+1].first == b[j].first) {
                j++;
            }
            minPrefixSum[i] = prefixSum[j+1] - prefixSum[j];
            j++;
        }
        
        for (int i = 0; i < n - k + 1; ++i) {
            ans = min(ans, minPrefixSum[i] + (prefixSum[i+k-1] - prefixSum[i]) * a[i+k-1].first);
        }
        
        cout << ans << endl;
    }
    return 0;
}