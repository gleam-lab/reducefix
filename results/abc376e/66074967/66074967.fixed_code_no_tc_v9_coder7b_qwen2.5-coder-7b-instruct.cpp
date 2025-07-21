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
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort based on A_i values to maximize the product with maximum A_i in subset
        sort(a.begin(), a.end());
        // Pair corresponding B_i values based on sorted A_i indices
        for(int i = 0; i < n; ++i) {
            b[a[i].second].second = i;
        }
        
        // Now sort B based on their new paired indices
        sort(b.begin(), b.end());

        // Initialize variables to track current sum and minimum product
        int current_sum = 0, min_product = INT_MAX;

        // Iterate through sorted pairs to calculate the minimum product
        for(int i = k - 1; i < n; ++i) {
            current_sum += b[i].first;
            // Calculate product with current max A_i and update if smaller than previous minimum
            min_product = min(min_product, static_cast<long long>(a[i].first) * current_sum);
        }

        cout << min_product << endl;
    }
    return 0;
}