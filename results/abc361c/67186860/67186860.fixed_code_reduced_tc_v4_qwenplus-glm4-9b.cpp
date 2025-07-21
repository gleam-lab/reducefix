#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    // We start the sliding window from index k and iterate to the end of the array
    // Since we remove K elements, we are left with N-K elements to consider.
    int min_diff = INT_MAX;
    for (int i = k; i <= n - k; ++i) {
        // The current max is the last element of the array of size N-K
        // The current min is the first element of the array of size N-K
        int current_max = a[i + k - 1];
        int current_min = a[i - 1];
        min_diff = min(min_diff, current_max - current_min);
    }

    // Output the minimum difference found
    cout << min_diff << endl;
    return 0;
}