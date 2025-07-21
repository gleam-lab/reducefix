#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    // We need to remove k elements
    if (k == 0) {
        // If k is 0, then no elements are removed, the range is 0
        std::cout << 0 << std::endl;
        return 0;
    }

    int min_val = A[0];
    int max_val = A[n - 1];
    int l = 0;
    int r = n - 1;

    // Skip the first k elements and last k elements
    while (l < n - k && A[l] == min_val) {
        ++l;
    }
    while (r > k && A[r] == max_val) {
        --r;
    }

    // Calculate the minimum possible maximum value
    int min_possible_max = INT_MAX;
    for (int i = k; i <= r; ++i) {
        min_possible_max = min(min_possible_max, A[i]);
    }

    // Calculate the minimum possible minimum value
    int min_possible_min = INT_MAX;
    for (int i = l; i < n - k; ++i) {
        min_possible_min = min(min_possible_min, A[i]);
    }

    // Output the answer
    std::cout << min_possible_max - min_possible_min << std::endl;

    return 0;
}