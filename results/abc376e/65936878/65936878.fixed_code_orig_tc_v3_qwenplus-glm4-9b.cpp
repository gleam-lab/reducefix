#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
        sort(v.rbegin(), v.rend()); // Sort in descending order by A_i

        // Calculate the sum of B_i for the last k elements
        vector<int> b_sums(k);
        for (int i = 0; i < k; ++i) b_sums[i] = v[i].second + (i > 0 ? b_sums[i - 1] : 0);
        
        long long min_val = 1e18;
        // Iterate over the first k elements to find the minimum value
        for (int i = 0; i < k; ++i) {
            min_val = min(min_val, (long long)v[i].first * b_sums[i]);
        }
        cout << min_val << '\n';
    }
    return 0;
}