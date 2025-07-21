#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Sort the array to know the order
    std::sort(a.begin(), a.end());

    int minDiff = INT_MAX;

    // The initial window is a[0, k-1] and a[k, n-1]
    int maxVal = *std::max_element(a.begin() + k, a.end());
    int minVal = a[0];

    minDiff = std::max(maxVal - minVal, (long long)a[n - 1] - (long long)a[k]);

    // Slide the window from (1, k-1) to (n-k, n-1)
    for (int i = 1; i <= n - k; ++i) {
        maxVal = *std::max_element(a.begin() + i, a.begin() + k + i);
        minVal = a[i - 1];

        int currentDiff = max(maxVal - minVal, (long long)a[n - 1] - (long long)a[k + i]);
        minDiff = min(minDiff, currentDiff);
    }

    std::cout << minDiff << std::endl;

    return 0;
}