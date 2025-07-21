#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long ans = 1e18;  // Start with a very large number

    // Iterate over all elements to potentially remove them
    for (int i = 0; i < n; ++i) {
        if (k == 0) break;  // No more elements to remove

        // Calculate the maximum of the remaining elements on the right
        int max_right = 0;
        for (int j = i + 1; j < n && k > 0; ++j) {
            max_right = max(max_right, A[j]);
            --k;  // We removed one element
        }

        // Calculate the potential new value of B - max(B) if we remove 'k' elements
        long long potential_diff = max_right - A[i];

        // Update the answer if we found a smaller potential difference
        ans = min(ans, potential_diff);

        // If no more elements to remove, we can break early
        if (k == 0) break;
    }

    cout << ans << endl;

    return 0;
}