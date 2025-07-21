#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n + 1), B(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> B[i];
        }
        
        vector<pair<int, int>> AB(n + 1);
        for (int i = 1; i <= n; ++i) {
            AB[i] = make_pair(A[i], B[i]);
        }
        
        // Sort by A[i] descending
        sort(AB.begin() + 1, AB.begin() + 1 + n, [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        long long sum = 0;
        // Sum the first k B[i]
        for (int i = 1; i <= k; ++i) {
            sum += AB[i].second;
        }
        
        long long ans = AB[k].first * sum;
        
        // We need to minimize the value of max(A[i]) * sum
        // since we already have the maximum A[i] in AB[k].first
        // we need to minimize sum while still having at least k elements
        
        // First, try to reduce sum by replacing the smallest b's with larger b's
        // if the replacement improves the answer
        for (int i = k + 1; i <= n; ++i) {
            if (AB[i].second > sum - AB[k].second) {
                sum = sum - AB[k].second + AB[i].second;
                ans = min(ans, AB[i].first * sum);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}