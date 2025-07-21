#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    // Sort the array to facilitate the removal of the largest or smallest K elements.
    std::sort(A.begin(), A.end());

    // The minimum possible value of the maximum value of B minus the minimum value of B
    // is the difference between the Kth smallest and the (n-K-1)th largest element.
    // This is because removing the smallest K elements from the sorted array will
    // maximize the minimum element of the remaining array, and removing the largest
    // K elements will minimize the maximum element of the remaining array.
    int min_value_after_removal = A[k];
    int max_value_after_removal = A[n - 1 - k];

    std::cout << max_value_after_removal - min_value_after_removal << std::endl;

    return 0;
}