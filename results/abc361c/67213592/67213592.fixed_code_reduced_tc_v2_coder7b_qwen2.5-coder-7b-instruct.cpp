#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    for (auto& val : v) {
        std::cin >> val;
    }

    std::sort(v.begin(), v.end());

    int min_diff = INT_MAX;
    for (int i = 0; i <= n - k; ++i) {
        min_diff = std::min(min_diff, v[i + k - 1] - v[i]);
    }

    std::cout << min_diff << std::endl;

    return 0;
}