#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N;
    std::vector<int> A(N);
    std::vector<int> B(N - 1);

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        std::cin >> B[i];
    }

    // Sort both lists in descending order
    std::sort(A.begin(), A.end(), std::greater<int>());
    std::sort(B.begin(), B.end(), std::greater<int>());

    int j = 0; // Pointer for boxes
    bool feasible = true;

    // Try to fit each toy into one of the boxes
    for (int i = 0; i < N; i++) {
        while (j < N - 1 && B[j] < A[i]) {
            j++;
        }
        if (j == N - 1) {
            // No box is large enough
            std::cout << -1 << std::endl;
            return 0;
        }
        j++; // Move to the next box
    }

    // If we can fit all toys into boxes, the minimum x is the size of the largest box used
    std::cout << B[j - 1] << std::endl;
    return 0;
}