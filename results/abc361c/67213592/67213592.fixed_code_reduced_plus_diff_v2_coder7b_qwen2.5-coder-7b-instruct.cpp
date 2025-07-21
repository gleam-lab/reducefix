#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> v(n);
    for (auto& val : v) {
        std::cin >> val;
    }

    std::sort(v.begin(), v.end());

    long long min_value = std::numeric_limits<long long>::max();
    for (int i = 0; i <= n - k; ++i) {
        min_value = std::min(min_value, static_cast<long long>(v[i + k - 1]) - v[i]);
    }

    std::cout << min_value << std::endl;

    return 0;
}