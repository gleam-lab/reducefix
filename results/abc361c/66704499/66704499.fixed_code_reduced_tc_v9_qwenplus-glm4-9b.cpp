#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the sequence
    sort(a.begin(), a.end());

    // Initialize the answer with a large value
    int answer = INT_MAX;

    // The number of elements to keep
    int num_elements_to_keep = n - k;

    // Iterate over all possible elements that could be the largest in the remaining sequence
    for (int i = 0; i <= k; ++i) {
        // Maximum value after removing K elements
        int max_value = a[num_elements_to_keep - 1];
        // Minimum value after removing K elements
        int min_value = a[i];
        // Calculate the difference
        int diff = max_value - min_value;
        // Update the answer if the difference is smaller
        answer = min(answer, diff);
    }

    // Output the answer
    cout << answer << endl;

    return 0;
}