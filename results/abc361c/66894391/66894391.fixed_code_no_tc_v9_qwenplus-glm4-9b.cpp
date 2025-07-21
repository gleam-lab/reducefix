#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Sort the array to be able to calculate the minimum difference
    sort(A.begin(), A.end());

    // We will remove K largest elements to minimize the max value of B
    // and K smallest elements to minimize the min value of B.
    // The minimum difference will be between the K-th smallest and the (N-K-1)-th largest.

    // If K is odd, remove K elements from both ends, otherwise remove K-1 from the largest end.
    int remove_left = (k + 1) / 2; // Remove from the left (smallest values)
    int remove_right = k / 2;     // Remove from the right (largest values)

    int min_value = A[remove_left];       // Minimum value after removal
    int max_value = A[n - remove_right - 1]; // Maximum value after removal

    cout << max_value - min_value << endl;

    return 0;
}