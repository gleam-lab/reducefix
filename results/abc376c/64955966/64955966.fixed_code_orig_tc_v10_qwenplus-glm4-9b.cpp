#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N;
    std::vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        std::cin >> B[i];
    }

    std::sort(A.rbegin(), A.rend());
    std::sort(B.rbegin(), B.rend());

    int largestBox = B[0];
    for (int i = 1; i < N; ++i) {
        if (A[i] > largestBox) {
            std::cout << -1 << std::endl;
            return 0;
        }
        // Update the largest available box size
        if (i > 0) {
            largestBox = std::max(largestBox, B[i]);
        }
    }

    std::cout << largestBox << std::endl;
    return 0;
}