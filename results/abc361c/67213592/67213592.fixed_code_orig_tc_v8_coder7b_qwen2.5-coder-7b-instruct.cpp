#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end());

    int best_diff = INT_MAX;
    for (int i = 0; i <= n - k - 1; ++i) {
        best_diff = std::min(best_diff, v[i + k - 1] - v[i]);
    }

    std::cout << best_diff << '\n';

    return 0;
}