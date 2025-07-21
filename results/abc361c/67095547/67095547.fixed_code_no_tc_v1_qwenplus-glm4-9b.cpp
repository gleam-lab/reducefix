#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // We will sort the array and then consider removing elements from both ends.
    sort(a.begin(), a.end());

    int ans = INT_MAX; // Initialize answer to the maximum possible value.
    
    // Iterate through the number of elements we keep from the beginning.
    for (int i = 0; i <= k; ++i) {
        int max_val = *max_element(a.begin() + n - k, a.begin() + n - i);
        int min_val = *min_element(a.begin() + i, a.begin() + n - k);
        ans = min(ans, max_val - min_val);
    }

    cout << ans << endl;
    return 0;
}