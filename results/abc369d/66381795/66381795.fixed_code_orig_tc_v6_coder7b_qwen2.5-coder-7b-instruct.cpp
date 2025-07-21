#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> data(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += data[i];
    }

    std::cout << sum << std::endl;
    return 0;
}