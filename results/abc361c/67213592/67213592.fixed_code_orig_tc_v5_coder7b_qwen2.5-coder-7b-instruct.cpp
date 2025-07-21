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

    // The minimum possible value of the difference between the maximum and minimum values of B
    // is achieved by removing the smallest K elements and keeping the rest.
    int result = v[n - 1] - v[k];

    std::cout << result << std::endl;

    return 0;
}