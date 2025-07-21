#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (long long &val : a) cin >> val;

    // Sort array
    sort(a.begin(), a.end());

    // Initialize the answer to a large value
    long long min_diff = LLONG_MAX;

    // We will try to remove K elements from each possible position
    for (long long i = 0; i <= n - k; ++i) {
        long long max_val = *max_element(a.begin() + i, a.begin() + n - k);
        long long min_val = *min_element(a.begin() + i, a.begin() + n - k);

        // Calculate the difference
        long long current_diff = max_val - min_val;

        // Update the minimum difference
        min_diff = min(min_diff, current_diff);
    }

    // Output the minimum difference
    cout << min_diff << endl;

    return 0;
}