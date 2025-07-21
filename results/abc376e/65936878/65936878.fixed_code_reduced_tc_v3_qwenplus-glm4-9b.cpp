#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }

        // Sort the vector based on the first element of the pair descending
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        // To minimize the expression, we need to find the optimal combination of K elements
        // where the maximum value of A_i is minimized and the sum of B_i is maximized.
        int ans = 0;
        int sumB = 0;
        int maxA = v[0].first; //Initially, we consider the first element as the maximum

        // Iterate to include exactly K elements
        for (int i = 0; i < k; i++) {
            sumB += v[i].second;
            // Check if we need to replace the current maxA with the current element
            if (v[i].first > maxA) {
                maxA = v[i].first;
            }
        }

        // The answer for this test case is the product of the minimum maxA and sumB
        ans = maxA * sumB;

        // Output the result
        cout << ans << '\n';
    }
    return 0;
}