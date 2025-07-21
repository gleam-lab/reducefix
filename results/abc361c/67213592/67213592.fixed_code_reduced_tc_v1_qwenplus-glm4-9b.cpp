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

    // Initialize the minimum difference to a large number
    int min_diff = INT_MAX;
    
    // Check subarrays of length n - k
    for (int i = 0; i <= n - k; ++i) {
        int diff = a[i + k - 1] - a[i];
        min_diff = min(min_diff, diff);
    }

    cout << min_diff << endl;

    return 0;
}