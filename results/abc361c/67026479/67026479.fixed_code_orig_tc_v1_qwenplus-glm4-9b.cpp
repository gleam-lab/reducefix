#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // Prefix minimum array
    vector<int> prefix_min(n, 0);
    prefix_min[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix_min[i] = min(prefix_min[i - 1], a[i]);
    }

    int min_diff = INT_MAX;
    
    // Sliding window to find the minimum difference
    for (int i = 0; i <= n - k; ++i) {
        int max_of_window = *max_element(a.begin() + i, a.begin() + i + k);
        int min_of_window = prefix_min[i + k - 1];
        min_diff = min(min_diff, max_of_window - min_of_window);
    }

    cout << min_diff << endl;

    return 0;
}