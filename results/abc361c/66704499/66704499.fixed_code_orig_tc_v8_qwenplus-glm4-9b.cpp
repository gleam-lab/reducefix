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

    // Sort the array in non-decreasing order
    sort(A.begin(), A.end());

    // Initialize the difference between the max and min after removing K elements
    int min_diff = A[n - 1] - A[0];

    // Iterate over all possible sizes of the remaining sequence (from 1 to n - k)
    for (int remaining_size = 1; remaining_size <= n - k; ++remaining_size) {
        // Calculate the difference between the max and min of the remaining sequence
        int current_diff = A[n - remaining_size] - A[remaining_size - 1];

        // Update the minimum difference found so far
        min_diff = min(min_diff, current_diff);
    }

    // Output the minimum difference
    cout << min_diff << endl;

    return 0;
}