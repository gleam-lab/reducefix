#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort based on A's value to maximize the product when taking maximum A_i
        sort(a.begin(), a.end());
        // Sort based on B's value to minimize the sum when taking smallest B_i
        sort(b.begin(), b.end());

        // Initialize variables to track the current sum and result
        int current_sum = 0, result = LLONG_MAX;
        
        // Iterate through sorted arrays to calculate the product
        for (int i = k - 1; i < n; ++i) {
            current_sum += b[i].first;
            result = min(result, static_cast<long long>(a[i].first) * current_sum);
        }

        cout << result << endl;
    }
    return 0;
}