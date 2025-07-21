#include <iostream>
#include <vector>
#include <algorithm>
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
        vector<pair<int, int>> v(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first >> v[i].second;
        }
        
        sort(v.begin(), v.end());
        
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + v[i].second;
        }
        
        double ans = 1e18;
        int j = n - k;
        for (int i = j; i >= 0; --i) {
            double sum = (double)(prefixSum[n] - prefixSum[j]);
            double maxA = (double)v[i].first;
            ans = min(ans, maxA * sum);
            j--;
        }
        
        cout << fixed << setprecision(10) << ans << '\n';
    }
    
    return 0;
}