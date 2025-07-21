#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n-1);

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    for (int i = 0; i < n-1; ++i)
        std::cin >> b[i];

    std::sort(a.begin(), a.end(), std::greater<int>());
    std::sort(b.begin(), b.end());

    int min_size = -1;

    for (int i = 0; i < n-1; ++i) {
        if (a[i] > b[i]) {
            min_size = a[i];
            break;
        }
    }

    std::cout << min_size << std::endl;

    return 0;
}