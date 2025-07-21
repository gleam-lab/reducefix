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

    // We will calculate the difference for removing the smallest K elements
    // and then remove the largest K elements and calculate the difference.
    // We need to consider all these cases and find the minimum difference.

    int min_difference = A[n - k] - A[k - 1]; // Initial case: remove the smallest K and the largest K
    for (int i = 0; i < k; ++i) {
        // Remove i smallest elements and calculate the new difference
        int new_min_difference = A[n - k - i] - A[k + i - 1];
        min_difference = min(min_difference, new_min_difference);
    }
    
    // If k is even, also consider removing i largest elements and calculate the new difference
    for (int i = 0; i < k / 2; ++i) {
        int new_min_difference = A[n - 2 * k + i] - A[n - k + k / 2 + i];
        min_difference = min(min_difference, new_min_difference);
    }

    cout << min_difference << endl;

    return 0;
}