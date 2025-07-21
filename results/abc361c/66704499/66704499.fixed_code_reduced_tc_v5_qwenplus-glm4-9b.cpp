#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    // The following step calculates the prefix max and suffix min arrays
    vector<int> prefix_max(n);
    vector<int> suffix_min(n);
    prefix_max[0] = a[0];
    for (int i = 1; i < n; ++i){
        prefix_max[i] = max(prefix_max[i - 1], a[i]);
    }
    suffix_min[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i){
        suffix_min[i] = min(suffix_min[i + 1], a[i]);
    }

    // Initialize the answer with a large value
    int ans = INT_MAX;
    // We need to consider removing `k` elements, which means we'll have `n-k` elements remaining
    for (int i = k; i <= n - k; ++i){
        // Calculate the maximum of the remaining elements
        int max_value = prefix_max[n - i - 1];
        // Calculate the minimum of the remaining elements
        int min_value = suffix_min[i - 1];
        // Update the answer with the minimum difference found
        ans = min(ans, max_value - min_value);
    }

    // Output the answer
    cout << ans << endl;

    return 0;
}